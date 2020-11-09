//
// Created by iXasthur on 09.11.2020.
//

#ifndef THREAD_SORT_LINESSORTER_H
#define THREAD_SORT_LINESSORTER_H

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <thread>
#include "utils/SortTask.h"
#include "utils/SortQueue.h"
#include "MergeSorter.h"

class LinesSorter {
private:
    SortQueue sortQueue = SortQueue();

    std::vector<std::vector<std::string>> sortedLinesSubvecs;

    void thread() {
        if (sortQueue.size() > 0) {
            SortTask task = sortQueue.pop();
            task.execute();
            sortedLinesSubvecs.emplace_back(task.lines);
        }
    }

    static long static_thread_entry(void *param) {
        auto *myObj = (LinesSorter *) param;
        myObj->thread();
        return 0;
    }

    void sort(int threadCount) {
        unsigned long long linesCount = initial.size();
        if (linesCount < threadCount) {
            threadCount = (int) linesCount;
        }

        unsigned long long taskLinesCount = linesCount / threadCount;

        // Fill sort queue with SortTasks
        for (int i = 0; i < threadCount; ++i) {
            auto start = initial.begin() + i * taskLinesCount;
            auto end = start + taskLinesCount;
            SortTask task = SortTask(std::vector<std::string>(start, end));
            sortQueue.push(task);
        }

        // Create threads
        HANDLE threads[threadCount];
        for (int i = 0; i < threadCount; i++) {
            threads[i] = CreateThread(
                    nullptr,                                      // default security attributes
                    0,                                                // use default stack size
                    reinterpret_cast<LPTHREAD_START_ROUTINE>(&static_thread_entry),    // thread function name
                    this,                                             // argument to thread function
                    0,                                             // use default creation flags
                    nullptr                                            // returns the thread identifier
            );
        }
        WaitForMultipleObjects(threadCount, threads, TRUE, INFINITE);

        // Unite subvectors of lines and sort
        for (auto &subvec : sortedLinesSubvecs) {
            for (const std::string &line : subvec) {
                sorted.emplace_back(line + '\n');
            }
            MergeSorter::sort(sorted.data(), sorted.size());
        }

        sortedLinesSubvecs.clear();
    }

public:
    std::vector<std::string> initial;
    std::vector<std::string> sorted;

    explicit LinesSorter(const std::vector<std::string> &lines, int threadCount) {
        initial = lines;
        if (threadCount > 0) {
            sort(threadCount);
        } else {
            throw std::runtime_error("Thread Count must be > 0");
        }
    }

};

#endif //THREAD_SORT_LINESSORTER_H
