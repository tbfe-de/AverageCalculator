/*
 =================================================================
 Exercise 9 (for Solution see Exercise 10)
 =================================================================
 TODO:
  - Add direct member initialization to the `struct sum_count`,
    overload `operator<<` so that it shows the quotient, and
    `operator+=` for a right-hand operand of type float so that
    it gets added to he `sum` and increments the `count`.

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
