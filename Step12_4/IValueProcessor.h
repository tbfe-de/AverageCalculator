#ifndef MY_I_VALUE_PROCESSOR_H_
#define MY_I_VALUE_PROCESSOR_H_

#include <iosfwd>

namespace my {

template<typename T>
class IValueProcessor {
public:
    virtual ~IValueProcessor() = default;
    using value_type = T;
    virtual void reset() =0;                    // reset to initial state
    virtual void operator+=(value_type) =0;     // add (another) value
    virtual void print(std::ostream&) const =0; // helper to operator<<
    virtual bool hasValues() const =0;          // reset to initial state
};

template<typename T>
inline
std::ostream& operator<<(std::ostream& os, my::IValueProcessor<T> const& rhs) {
    rhs.print(os);
    return os;
}

} // namespace

#endif // include guard