#ifndef MY_MINMAXER_H_
#define MY_MINMAXER_H_

#include "IValueProcessor.h"

#include <iosfwd>

namespace my {

class MinMaxer : public IValueProcessor<long long> {
    value_type min_{}; // empty braces mean zero for
    value_type max_{}; // builtin arithmetic types
    bool first_{true};
public: // implementing the interface
    void print(std::ostream&) const override;  
    void operator+=(value_type rhs) override;
    bool hasValues() const override { return (first_ == false); }
    void reset() override;
};

} // namespace



#endif // include guard
