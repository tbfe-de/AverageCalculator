/*
 =================================================================
 Exercise 4 (for Solution see Exercise 5)
 =================================================================
 TODO:
 - Currently the arguments handed over to `do_average` are
   pointers. Turn them into references.

 -----------------------------------------------------------------

 TODO (optional - meant only for further self-study only):
 - Have a closer look to the `main` function compiled when `TEST`
   is defined and note that how the expectations for output are
   specified differently if the expected output is only one line
   (or nothing at all) or multiple line. It affects how potential
   differences are displayed if a test fails.
 - If multiples lines of output are expected it is easier to use
   "raw string literals" (as available since C++11). Accordingly
   modify how the expectation is supplied.
*/

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
