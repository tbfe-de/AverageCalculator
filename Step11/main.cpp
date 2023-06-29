/*
 =================================================================
 Exercise 11 (for Solution see Exercise 12)
 =================================================================
 TODO:
   Put the class `Averager` and the functions `do_averages` and
   `do_single_average` into a namespace "my" and adapt the call in
   the main program accordingly.
   As this as the sole exercise would be a bit too easy :-) also move
   the the class definition of `Averager` into a header file and the
   out-of-class definition of its friend functions into an implementation
   file. For your convenience both files have alsready been prepared
   (with the usual names "Averager.h" and "Averager.cpp" as EMPTY
   files)

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
