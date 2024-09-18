#include "IValueProcessor.h"

#include <iosfwd>

namespace my {

void do_processing(std::istream&, std::ostream&, IValueProcessor&);

void do_processing(IValueProcessor&);

} // namespace
