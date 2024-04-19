# TODO STEP 2

- Examine the C++-program in `main.cpp` and how it differs from
  the C program `main.c` in the previous step and describe the
  obvious simplifications of using and `std::string` instead of a
  `char`-Array to store whole lines of input wrt. to
  - setting a limit for the longest line that can be processed?
  - extracting numbers from that line if the data type of `sum`
    and `value` is changed from `float` to `double` or even to an
    integral type?
- In the `main` program remove the arguments `&std::cin` and
  `&std::cout` from the call of `do_averages` to demonstrate the
  default values set in the header `do_averages.h` take over.

**Note:** The solution provided in the next step makes two more
substantial changes which **you are not meant to do yourself**
as part of this step:

1. The single file `main.cpp is split into three files each of
   which is responsible for a separate major part:
   - `main.cpp` - controls the overall functionality
   - `do_averages.cpp` - calculates the averages per input line
   - `do_averages.h` - describes the call interface of the latter

2. As the input source and the output destination are controlled
   by `std::istream` and `std::ostream` arguments to `do_averages`
   an alternative to interactive testing is made available. It
   supplies test input via an `std::istringstream`, catches the
   output in an `std::ostringstream` and checks it against what is
   expected.

------------------------------------------------------------------

TODO (optional - meant for further self-study only):

- Introduce a type alias `value_type` and use as type of the
  variables `sum` and `value`. (The intent here is you can change
  the type of both variables with only a single modification to
  the source code:
  - `typedef float value_type;` (C-style type alias)
  - `using value_type = float;` (or C++11 type alias)
- Compile and test the program with various arithmetic types. (Try
  at least one other floating point type, one signed integral type
  and one unsigned integral type.)
- How does the program react to input that is not numeric?
- Furthermore there need to be a header file with the prototype of
  `do_average` so that in can be in included in `main.cpp`:\
  - `#include "do_averages.h"`
- Why does in make sense to include that header file also in
  the implementation `averages.cpp`, though technically speaking
  the prototype definition isn't required here?

  NOTE: You can still compile both `.cpp` implementation files
  with a single command if you use `*.cpp` instead of `main.cpp`.
