#ifndef MY_AVERAGER_H_
#define MY_AVERAGER_H_

#include <iosfwd>

namespace my {

class Averager {
    float sum_{0.0f};
    int count_{0};
    friend
    std::ostream& operator<<(std::ostream&, Averager const& rhs);
    friend
    void operator+=(Averager& lhs, float rhs);
public:
    auto getCount() const { return count_; }
};

} // namespace

#endif // include guard
