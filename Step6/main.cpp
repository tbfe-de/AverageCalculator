/*
 =================================================================
 Exercise 6 (for Solution see Exercise 7)
 =================================================================
 TODO:
 - Change the first argument of `do_single_average` into an
   `std::string` (the single line just read).
 - Change the second argument of `do_single_average` into a
   reference to the following:
    struct sum_count {
        float sum;
        int count;
    };
- The output of the average should be moved back to `do_averages`
  as it now can be done based on the what is returned from
  `do_single_average` via that struct.
- Same for the decision whether to end the outer loop, so it is
  no longer required to return a `bool` from `do_single_average`.

 -----------------------------------------------------------------

 TODO (optional - meant for further self-study only):
 - Discuss the pro's and con's of returning the structure holding
   the sum and the count as return value of `do_averages` instead
   via a reference argument.
*/

#include "do_averages.h"

#include <sstream>
    // std::istringstream

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
