#include <iostream>
#include "io/FileReader.h"
#include "io/FileWriter.h"
#include "sort/LinesSorter.h"

int main() {
    LinesSorter sorter = LinesSorter(FileReader::read("in.txt"), 4);
    FileWriter::write(sorter.sorted, "out.txt");
    return 0;
}
