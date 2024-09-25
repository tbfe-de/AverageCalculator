#ifndef MY_AVERAGER_H_
#define MY_AVERAGER_H_

#include "IValueProcessor.h"

#include <iosfwd>

namespace my {

class Averager : public IValueProcessor {
    value_type sum_{}; // empty braces mean zero for
    std::size_t count_{}; // builtin arithmetic types
public: // implementing the interface
    void print(std::ostream&) const override;  
    void operator+=(value_type rhs) override;
    auto getCount() const { return count_; }
};

} // namespace



#endif // include guard
