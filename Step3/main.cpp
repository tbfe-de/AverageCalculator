/*
 =================================================================
 Exercise 3 (for Solution see Exercise 4)
 =================================================================
 TODO:
 - Examine the file structure of the two translation units

   - `main.cpp` and
   - `do_averages` together with the share header file
   - `do_averages.h`

 - Note that in `main.cpp` there are two different `main`
   functions, one for interactive testing and another one for a
   "TDD approach". (TDD = "Test Driven Development" which means
   the function `do_averages` is called with prepared input and
   its output is checked against expectations). Which `main`
   program gets compiled and executed depends on the macro `TEST`
   being set on compilation.
 - Currently `do_averages` has default arguments, which allows
   to call it without any arguments from the `main` function.
   Remove the default arguments and instead add an overload
   without no arguments so that the call in `main` can stay the
   same.

 -----------------------------------------------------------------

 TODO (optional - meant for further self-study only):
 - Add some more tests, especially for the border cases like:
   - completely empty input
   - just a single number
   - empty line between non-empty lines
   - non-numeric input in the middle
   - non numeric input at the start
 - Build group of tests and put them in a function of their own
   with `main` calling these functions.
*/

//@impl main.cpp
//
#include "do_averages.h"

#include <sstream>
    //std::istringstream

#ifndef TEST
int main() {
    do_averages();
}
#else
#include "pxt.h"

int main() {
    std::istringstream test_input{
            "1 5 7"     "\n"
            "1.5 7"     "\n"
            "15.7"      "\n"
    };
    std::ostringstream received_output{};
    PX(do_averages(&test_input, &received_output), received_output.str())
    #if 0 // expectations are specified as classic C literals (which
          // are getting concatenated if seperated by white-space only)
        >>= "4.33333"   "\n"
             "4.25"     "\n"
             "15.7"     "\n";
    #else // alternatively expectations can be specified as raw strings
          // literals (since C++11) requiring less quoting as everything
          // inside is taken literal (especially the line endings)
        >>= R"(
                4.33333
                4.25
                15.7
        )";
    #endif
 }

#endif
