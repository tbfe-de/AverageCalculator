#include "Averager.h"

#include <iostream>

namespace my {
    std::ostream& operator<<(std::ostream& lhs, Averager const& rhs) {
        return lhs << rhs.sum_/rhs.count_;
    }

    void operator+=(Averager& lhs, float rhs) {
        lhs.sum_ += rhs;
        ++lhs.count_;
    }
}
