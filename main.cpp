#include <iostream>
#include "io/FileReader.h"
#include "io/FileWriter.h"
#include "sort/LinesSorter.h"

int main() {
    FileReader reader = FileReader("in.txt");
    LinesSorter sorter = LinesSorter(reader.lines, 4);
    FileWriter::write(sorter.sorted, "out.txt");
    return 0;
}
