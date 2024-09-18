#include "do_processing.h"

#include "Averager.h"
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
    
void do_processing(std::istream& in, std::ostream& out, IValueProcessor& processor) {

    std::string line;
    auto process_single_value = [&line](IValueProcessor& result) {
        std::istringstream iss{line};
        float value;
        while (iss >> value)
            result += value;
        bool const received_some_values_but_not_seen_eol{
            !result.hasValues() && !iss.eof()
        };
        bool const fail_bit_is_set_but_eof_bit_is_not{
            iss.fail() && !iss.eof()
        };
        if (received_some_values_but_not_seen_eol
        || fail_bit_is_set_but_eof_bit_is_not)
            throw "non-numeric input";
    };

    while (std::getline(in, line)) {
        processor.reset();
        try {
            process_single_value(processor);
        }
        catch (char const* errmsg) {
            out << errmsg << " - line ignored" << std::endl;
            continue;
        }
        if (not processor.hasValues()) return;
        out << processor << std::endl;
    }
}

void do_processing(IValueProcessor& processor) {
    do_processing(std::cin, std::cout, processor);
}

} // namespace
