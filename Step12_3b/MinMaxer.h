#ifndef MY_MINMAXER_H_
#define MY_MINMAXER_H_

#include "IValueProcessor.h"

#include <iosfwd>

namespace my {

class MinMaxer : public IValueProcessor {
    value_type min_{}; // empty braces mean zero for
    value_type max_{}; // builtin arithmetic types
    bool first_{true};
public: // implementing the interface
    void print(std::ostream&) const override;  
    void operator+=(value_type rhs) override;
    auto isFirst() const { return first_; }
};

} // namespace



#endif // include guard
