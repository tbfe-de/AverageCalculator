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

void do_averages(std::istream* in, std::ostream* out) {
    std::string line;
    while (std::getline(*in, line)) {
        float sum = 0.0f;
        int count = 0;
        float value;
        std::istringstream iss{line};
        while (iss >> value) {
            sum += value;
            ++count;
        }
        if (count == 0) return;
        *out << sum/count << std::endl;
    }
}

void do_averages() {
    do_averages(std::cin, std::cout);
}
