/*
 =================================================================
 Exercise 4 (for Solution see Exercise 5)
 =================================================================
 TODO:
 - Currently the arguments handed over to `do_average` are
   pointers. Turn them into references.

 -----------------------------------------------------------------

 TODO (optional - meant for further self-study only):
 - Inform yourself (eg. using cppreference.com) about the
   purpose of the header file `<iosfwd>`.
 - In which place were its use more appropiate than the currently
   used `<iostream>`?
 - Why hadn't that change been possible in the version handing
   over the arguments as pointers, using `&std::cin` and
   `&std::cout` as default values?
 - Why in the current versions wouldn't that change be possible
   if the overload with no arguments were defined as `inline`
   function?
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
    PX(do_averages(&input, &output), output.str())
        >>= "4.33333"   "\n"
             "4.25"     "\n"
             "15.7"     "\n";
    } ////////////////////////////////////////////////////////////

    { ////////////////////////////////////////////////////////////
    std::istringstream input{"\n"};
    std::ostringstream output{};
    PX(do_averages(&input, &output), output.str()) == "";
    } ////////////////////////////////////////////////////////////

    { ////////////////////////////////////////////////////////////
    std::istringstream input{
            "1 5 7"     "\n"
            "1 S 7"     "\n"
            "15.7"      "\n"
    };
    std::ostringstream output{};
    PX(do_averages(&input, &output), output.str())
        >>= "4.33333"   "\n"
             "1"        "\n"
             "15.7"     "\n";
    } ////////////////////////////////////////////////////////////
 }

#endif
