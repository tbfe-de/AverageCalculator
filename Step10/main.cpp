/*
 =================================================================
 Exercise 10 (for Solution see Exercise 11)
 =================================================================
 TODO:
  - Turn the `struct sum_count` into a `class Averager` by making
    `operator<<` and `operator+=` friends and in addition
    provide a member function `getCount` tor return the `count_`
    member in the two places where it is currently used.

 -----------------------------------------------------------------

 TODO (optional - meant for further self-study only):
 ...
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
        >>= "4.33333"                                     "\n"
             "non-numeric input - line ignored"  "\n"
             "15.7"                                       "\n";
    } ////////////////////////////////////////////////////////////
 }

#endif
