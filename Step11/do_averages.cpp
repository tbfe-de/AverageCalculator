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

class Averager {
    float sum_{0.0f};
    int count_{0};
    friend
    std::ostream& operator<<(std::ostream&, Averager const & rhs);
    friend
    void operator+=(Averager& lhs, float rhs);
public:
    auto getCount() const { return count_; }
};

std::ostream& operator<<(std::ostream& lhs, Averager const& rhs) {
    return lhs << rhs.sum_/rhs.count_;
}

void operator+=(Averager& lhs, float rhs) {
    lhs.sum_ += rhs;
    ++lhs.count_;
}

void do_single_average(std::string line, Averager& result) {
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
}

void do_averages(std::istream& in, std::ostream& out) {
    std::string line;
    while (std::getline(in, line)) {
        Averager sc{};
        try {
            do_single_average(line, sc);
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
