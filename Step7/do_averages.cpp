#include "do_averages.h"

#include <iostream>
    // std::cin
    // std::cout
    // std::istream
    // std::ostream
#include <sstream>
    // std::istringstream
    // std::ostringstream
#include <string>
    // std::getline
    // std::string

struct sum_count {
    float sum;
    int count;
};

void do_single_average(std::string line, sum_count& result) {
    std::istringstream iss{line};
    float value;
    while (iss >> value) {
        result.sum += value;
        ++result.count;
    }
}

void do_averages(std::istream& in, std::ostream& out) {
    std::string line;
    while (std::getline(in, line)) {
        sum_count sc{0.0f, 0};
        do_single_average(line, sc);
        if (sc.count == 0) return;
        out << sc.sum/sc.count << std::endl;
    }
}

void do_averages() {
    do_averages(std::cin, std::cout);
}
