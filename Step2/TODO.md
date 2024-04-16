# TODO

- Examine the C++-program below and how it differs from the one
  in Step1.
- What are the obvious simplifications by using `std::string`
  instead of a `char`-Array to store whole lines of input wrt. the
  following:
  - setting a limit for the longest line that can be processed?
  - extracting numbers from that line if the data type of `sum`
    and `value` is changed from `float` to `double` or to an
    integral type?
- Introduce a type alias `value_type` and use as type of the
  variables `sum` and `value`. (The intent here is you can change
  the type of both variables with only a single modification to
  the source code:
  - `typedef float value_type;` (C-style type alias)
  - `using value_type = float;` (or C++11 type alias)
- Compile and test the program with various arithmetic types. (Try
  at least one other floating point type, one signed integral type
  and one unsigned integral type.)

------------------------------------------------------------------

TODO (optional - meant for further self-study only):

- How does the program react to input that is not numeric?
- How would the program need to be re-structured if each of the
  functions `main` and `do_averages` will have their
  implementation in its own translations unit (but see also the
  NOTE below):
  - `main.cpp`
  - `do_averages.cpp`
- Furthermore there need to be a header file with the prototype of
  `do_average` so that in can be in included in `main.cpp`:\
  - `#include "do_averages.h"`
- Why does in make sense to include that header file also in
  the implementation `averages.cpp`, though technically speaking
  the prototype definition isn't required here?

  NOTE: You can still compile both `.cpp` implementation files
  with a single command if you use `*.cpp` instead of `main.cpp`.
