#include "MinMaxer.h"

#include <iostream>

namespace my {

void MinMaxer::print(std::ostream& lhs) const {
    if (first_)
        lhs << "no values";
    else
        lhs << min_<< " ... " << max_;
}

void MinMaxer::operator+=(value_type rhs) {
    if (first_) {
        min_ = max_ = rhs;
        first_ = false;
    }
    else if (rhs < min_)
        min_ = rhs;
    else if (rhs > max_)
        max_ = rhs;
}

} // namespace
