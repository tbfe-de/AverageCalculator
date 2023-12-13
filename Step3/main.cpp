/*
 =================================================================
 Exercise 3 (Solution see Exercise 4 ignoring the new TODO-s)
 =================================================================
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

#include <sstream>  // std::istringstream
                    // std::ostringstream

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
