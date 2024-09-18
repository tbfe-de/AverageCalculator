#ifndef MY_I_VALUE_PROCESSOR_H_
#define MY_I_VALUE_PROCESSOR_H_

#include <iosfwd>

namespace my {

class IValueProcessor {
public:
    virtual ~IValueProcessor() = default;
    using value_type = float;
    virtual void reset() =0;                    // reset to initial state
    virtual void operator+=(value_type) =0;     // add (another) value
    virtual void print(std::ostream&) const =0; // helper to operator<<
    virtual bool hasValues() const =0;          // reset to initial state
};

inline
std::ostream& operator<<(std::ostream& os, my::IValueProcessor const& rhs) {
    rhs.print(os);
    return os;
}

} // namespace

#endif // include guard