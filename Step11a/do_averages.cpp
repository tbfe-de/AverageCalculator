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
public:
    void operator+=(float rhs) {
        this->sum_ += rhs;  // or in short just sum_ += rhs;
        ++this->count_;     // or in short just ++count_;
    }
    auto getSum() const { return sum_; }
    auto getCount() const { return count_; }
};

std::ostream& operator<<(std::ostream& lhs, Averager const& rhs) {
    return lhs << rhs.getSum()/rhs.getCount();
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
