/*
 =====================================================================
 Exercise Mittwoch 1
 =====================================================================
 TODO:
   Put the class `Averager`  and the functions `do_averages` and
   `do_single_average` into a namespace "my" and adapt the call in
   the main program accordingly.
   As this as the sole exercise would be a bit too easy :-) also move
   the the class definition of `Averager` into a header file and the
   out-of-class definition of its friend functions into an implementation
   file. For your convenience both files have alsready been prepared
   (with the usual names "Averager.h" and "Averager.cpp" as EMPTY
   files)
*/

//@impl do_averages.cpp
//
#include "do_averages.h"

#include <iostream>
#include <sstream>
#include <string>

class Averager {
    float sum_{0.0f};
    int count_{0};
    friend std::ostream& operator<<(std::ostream&, Averager const&);
    friend Averager& operator+=(Averager&, float);
public:
    int getCount() const { return count_; }
};

std::ostream& operator<<(std::ostream& lhs, Averager const& rhs) {
    auto const result = (rhs.count_ > 0)
                            ? std::to_string(rhs.sum_/rhs.count_)
                            : std::string{"---"};
    return lhs << result;
}

Averager& operator+=(Averager& lhs, float rhs) {
    lhs.sum_ += rhs;
    ++lhs.count_;
    return lhs;
}

void do_single_average(std::string const& line_par, Averager& sc_par) {
    std::istringstream iss{line_par};
    float value;
    while (iss >> value) {
        sc_par += value;
        // sc_par.sum += value;
        //++sc_par.count;
    }
    if (((sc_par.getCount() > 0) && !iss.eof())
     || (iss.fail() && !iss.eof()))
        throw 0;
}

void do_averages(std::istream& in, std::ostream& out) {
    std::string line;
    while (std::getline(in, line)) {
        Averager sc;
        try {
            do_single_average(line, sc);
        }
        catch (int) {
            out << "non-numeric input - ignored" << std::endl;
            continue;
        }
        if (sc.getCount() == 0)
            return;
        out << sc << std::endl;
        // out << sc.sum/sc.count << std::endl;
    }
}

void do_averages() {
    do_averages(std::cin, std::cout);
}
