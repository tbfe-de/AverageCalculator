#include "Averager.h"

#include <iostream>

namespace my {

void Averager::print(std::ostream& lhs) const {
    if (count_ == 0)
        lhs << "no values";
    else
        lhs << sum_/count_;
}

void Averager::operator+=(value_type rhs) {
    sum_ += rhs;
    ++count_;
}

void Averager::reset() {
    sum_ = 0;
    count_ = 0;
}

} // namespace
