#ifndef MY_AVERAGER_H_
#define MY_AVERAGER_H_

#include "IValueProcessor.h"

#include <iosfwd>

namespace my {

class Averager : public IValueProcessor {
    value_type sum_{}; // empty braces mean zero for
    value_type count_{}; // builtin arithmetic types
public: // implementing the interface
    void print(std::ostream&) const override;  
    void operator+=(value_type rhs) override;
    bool hasValues() const override { return (count_ > 0); }
    void reset() override;
};

} // namespace



#endif // include guard
