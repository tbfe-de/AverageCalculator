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
    float sum{0.0f};
    int count{0};
};

std::ostream& operator<<(std::ostream& lhs, sum_count const& rhs) {
    return lhs << rhs.sum/rhs.count;
}

void operator+=(sum_count& lhs, float rhs) {
    lhs.sum += rhs;
    ++lhs.count;
}

void do_single_average(std::string line, sum_count& result) {
    std::istringstream iss{line};
    float value;
    while (iss >> value)
        result += value;
    bool const received_some_values_but_not_seen_eol{
        (result.count > 0) && !iss.eof()
    };
    bool const fail_bit_is_set_but_eof_bit_is_not{
        iss.fail() && !iss.eof()
    };
    if (received_some_values_but_not_seen_eol
     || fail_bit_is_set_but_eof_bit_is_not)
        throw "non-numeric input";
}

void do_averages(std::istream& in, std::ostream& out) {
    std::string line;
    while (std::getline(in, line)) {
        sum_count sc{};
        try {
            do_single_average(line, sc);
        }
        catch (char const* errmsg) {
            out << errmsg << " - line ignored" << std::endl;
            continue;
        }
        if (sc.count == 0) return;
        out << sc << std::endl;
    }
}

void do_averages() {
    do_averages(std::cin, std::cout);
}
