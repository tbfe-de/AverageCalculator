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

bool do_single_average(std::string line, sum_count& result) {
    std::istringstream iss{line};
    float value;
    while (iss >> value) {
        result.sum += value;
        ++result.count;
    }
    bool const have_received_some_values_but_dont_see_eol{
        (result.count > 0) && !iss.eof()
    };
    bool const fail_bit_set_but_not_together_with_eof_bit{
        iss.fail() && !iss.eof()
    };
    bool const some_non_numeric_input{
        have_received_some_values_but_dont_see_eol
     || fail_bit_set_but_not_together_with_eof_bit
    };
    return not some_non_numeric_input;
}

void do_averages(std::istream& in, std::ostream& out) {
    std::string line;
    while (std::getline(in, line)) {
        sum_count sc = {0.0f, 0};
        if (not do_single_average(line, sc)) {
            out << "non-numeric input - line ignored" << std::endl;
            continue;
        }
        if (sc.count == 0) return;
        out << sc.sum/sc.count << std::endl;
    }
}

void do_averages() {
    do_averages(std::cin, std::cout);
}
