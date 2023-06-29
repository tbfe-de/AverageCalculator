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
- The output of the average as quotient of `sum_` and `count_`
  shall be done in function `do_averages` as it now can can see
  what has been returned in `sum_count`
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
    { ////////////////////////////////////////////////////////////
    std::istringstream input{
            "1 5 7"     "\n"
            "1.5 7"     "\n"
            "15.7"      "\n"
    };
    std::ostringstream output{};
    PX(do_averages(input, output), output.str())
        >>= "4.33333"   "\n"
             "4.25"     "\n"
             "15.7"     "\n";
    } ////////////////////////////////////////////////////////////

    { ////////////////////////////////////////////////////////////
    std::istringstream input{"\n"};
    std::ostringstream output{};
    PX(do_averages(input, output), output.str()) == "";
    } ////////////////////////////////////////////////////////////

    { ////////////////////////////////////////////////////////////
    std::istringstream input{
            "1 5 7"     "\n"
            "1 S 7"     "\n"
            "15.7"      "\n"
    };
    std::ostringstream output{};
    PX(do_averages(input, output), output.str())
        >>= "4.33333"   "\n"
             "1"        "\n"
             "15.7"     "\n";
    } ////////////////////////////////////////////////////////////
 }

#endif
