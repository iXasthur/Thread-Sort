//
// Created by iXasthur on 09.11.2020.
//

#ifndef THREAD_SORT_SORTTASK_H
#define THREAD_SORT_SORTTASK_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class SortTask {
public:
    bool completed = false;
    std::vector<std::string> lines;

    explicit SortTask(const std::vector<std::string> &lines) {
        this->lines = lines;
    }

    void execute() {
        if (!completed) {
            std::sort(lines.begin(), lines.end());
            completed = true;
        }
    }
};


#endif //THREAD_SORT_SORTTASK_H
