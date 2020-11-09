//
// Created by iXasthur on 09.11.2020.
//

#ifndef THREAD_SORT_FILEREADER_H
#define THREAD_SORT_FILEREADER_H

#include <vector>
#include <string>
#include <fstream>

class FileReader {
public:
    std::vector<std::string> lines;

    explicit FileReader(const std::string &path) {
        std::ifstream in(path);
        std::string str;
        while (std::getline(in, str)) {
            lines.push_back(str);
        }
        in.close();
    }
};


#endif //THREAD_SORT_FILEREADER_H
