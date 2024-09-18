#include "do_averages.h"

#include "Averager.h"

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
    auto do_single_average = [&line](my::Averager& result) {
        std::istringstream iss{line};
        float value;
        while (iss >> value)
            result += value;
        bool const received_some_values_but_not_seen_eol{
            (result.getCount() > 0) && !iss.eof()
        };
        bool const fail_bit_is_set_but_eof_bit_is_not{
            iss.fail() && !iss.eof()
        };
        if (received_some_values_but_not_seen_eol
        || fail_bit_is_set_but_eof_bit_is_not)
            throw "non-numeric input";
    };

    while (std::getline(in, line)) {
        Averager sc{};
        try {
            do_single_average(sc);
        }
        catch (char const* errmsg) {
            out << errmsg << " - line ignored" << std::endl;
            continue;
        }
        if (sc.getCount() == 0) return;
        out << sc << std::endl;
    }
}

void do_averages() {
    do_averages(std::cin, std::cout);
}

} // namespace
