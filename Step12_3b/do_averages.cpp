#include "do_averages.h"

#include "MinMaxer.h"

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

namespace my {
    
void do_averages(std::istream& in, std::ostream& out) {

    std::string line;
    auto do_single_average = [&line](MinMaxer& result) {
        std::istringstream iss{line};
        float value;
        while (iss >> value)
            result += value;
        bool const received_some_values_but_not_seen_eol{
            !result.isFirst() && !iss.eof()
        };
        bool const fail_bit_is_set_but_eof_bit_is_not{
            iss.fail() && !iss.eof()
        };
        if (received_some_values_but_not_seen_eol
        || fail_bit_is_set_but_eof_bit_is_not)
            throw "non-numeric input";
    };

    while (std::getline(in, line)) {
        MinMaxer sc;
        try {
            do_single_average(sc);
        }
        catch (char const* errmsg) {
            out << errmsg << " - line ignored" << std::endl;
            continue;
        }
        if (sc.isFirst()) return;
        out << sc << std::endl;
    }
}

void do_processing() {
    do_averages(std::cin, std::cout);
}

} // namespace