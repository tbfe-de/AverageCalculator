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

bool do_single_average(std::istream& in_line, std::ostream& out) {
    float sum = 0.0f;
    int count = 0;
    float value;
    while (in_line >> value) {
        sum += value;
        ++count;
    }
    if (count == 0) return false;
    out << sum/count << std::endl;
    return true;
}

void do_averages(std::istream& in, std::ostream& out) {
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream iss{line};
        if (not do_single_average(iss, out))
            return;
    }
}

void do_averages() {
    do_averages(std::cin, std::cout);
}
