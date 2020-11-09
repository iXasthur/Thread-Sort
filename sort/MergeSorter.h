//
// Created by iXasthur on 09.11.2020.
//

#ifndef THREAD_SORT_MERGESORTER_H
#define THREAD_SORT_MERGESORTER_H

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>

class MergeSorter {
public:
    template<typename T>
    static void sort(T *array, std::size_t size) noexcept {
        if (size > 1) {
            std::size_t const left_size = size / 2;
            std::size_t const right_size = size - left_size;

            MergeSorter::sort(&array[0], left_size);
            MergeSorter::sort(&array[left_size], right_size);

            std::size_t lidx = 0, ridx = left_size, idx = 0;
            std::unique_ptr<T[]> tmp_array(new T[size]);

            while (lidx < left_size || ridx < size) {
                if (array[lidx] < array[ridx]) {
                    tmp_array[idx++] = std::move(array[lidx]);
                    lidx++;
                } else {
                    tmp_array[idx++] = std::move(array[ridx]);
                    ridx++;
                }

                if (lidx == left_size) {
                    std::copy(std::make_move_iterator(&array[ridx]),
                              std::make_move_iterator(&array[size]),
                              &tmp_array[idx]);
                    break;
                }
                if (ridx == size) {
                    std::copy(std::make_move_iterator(&array[lidx]),
                              std::make_move_iterator(&array[left_size]),
                              &tmp_array[idx]);
                    break;
                }
            }

            std::copy(std::make_move_iterator(&tmp_array[0]),
                      std::make_move_iterator(&tmp_array[size]),
                      array);
        }
    }
};


#endif //THREAD_SORT_MERGESORTER_H
