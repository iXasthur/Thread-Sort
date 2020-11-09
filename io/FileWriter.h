//
// Created by iXasthur on 09.11.2020.
//

#ifndef THREAD_SORT_FILEWRITER_H
#define THREAD_SORT_FILEWRITER_H

#include <vector>
#include <string>
#include <fstream>

class FileWriter {
public:
    static void write(const std::vector<std::string> &lines, const std::string &path) {
        std::ofstream out(path);
        for (const std::string &line : lines) {
            out << line;
        }
        out.close();
    }
};


#endif //THREAD_SORT_FILEWRITER_H
