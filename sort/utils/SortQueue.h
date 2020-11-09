//
// Created by iXasthur on 09.11.2020.
//

#ifndef THREAD_SORT_SORTQUEUE_H
#define THREAD_SORT_SORTQUEUE_H

#include <vector>
#include <string>
#include <mutex>
#include <queue>

class SortQueue {
public:
    void push(SortTask &value) {
        std::lock_guard<std::mutex> lock(mutex);
        queue.push(value);
    }

    SortTask pop() {
        std::lock_guard<std::mutex> lock(mutex);
        SortTask ret = queue.front();
        queue.pop();
        return ret;
    }

    unsigned long long size() {
        std::lock_guard<std::mutex> lock(mutex);
        return queue.size();
    }

private:
    std::queue<SortTask> queue;
    mutable std::mutex mutex;
};


#endif //THREAD_SORT_SORTQUEUE_H
