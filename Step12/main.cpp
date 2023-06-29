/*
 =================================================================
 Exercise 11 (for Solution see Exercise 12)
 =================================================================
 TODO:
 - move class Averager into a header and an implementation file
   and put everything into a `namespace my`

 -----------------------------------------------------------------

 TODO (optional - meant for further self-study only):
 ...
*/

#include "do_averages.h"

#include <sstream>
    // std::istringstream

#ifndef TEST
int main() {
    my::do_averages();
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
    PX(my::do_averages(input, output), output.str())
        >>= "4.33333"   "\n"
             "4.25"     "\n"
             "15.7"     "\n";
    } ////////////////////////////////////////////////////////////

    { ////////////////////////////////////////////////////////////
    std::istringstream input{"\n"};
    std::ostringstream output{};
    PX(my::do_averages(input, output), output.str()) == "";
    } ////////////////////////////////////////////////////////////

    { ////////////////////////////////////////////////////////////
    std::istringstream input{
            "1 5 7"     "\n"
            "1 S 7"     "\n"
            "15.7"      "\n"
    };
    std::ostringstream output{};
    PX(my::do_averages(input, output), output.str())
        >>= "4.33333"                                     "\n"
             "non-numeric input - line ignored"  "\n"
             "15.7"                                       "\n";
    } ////////////////////////////////////////////////////////////
 }

#endif
