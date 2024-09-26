/*
 =================================================================
 Step 8 (for Solution see Step 9)
 =================================================================
*/

#include "do_averages.h"

#include <sstream>
    // std::istringstream
    // std::ostringstream

#ifndef TEST
int main() {
    do_averages();
}
#else
#include "pxt.h"

void typical_good_input() {
    { ////////////////////////////////////////////////////////////
    std::istringstream input{
            "1 5 7"     "\n"
            "1.5 7"     "\n"
            "15.7"      "\n"
    };
    std::ostringstream output{};
    PX(do_averages(input, output), output.str())
        >>= "4.33333"   "\n"
            "4.25"      "\n"
            "15.7"      "\n";
    } ////////////////////////////////////////////////////////////
}

void some_empty_inputs() {
    { ////////////////////////////////////////////////////////////
    std::istringstream input{"\n"};
    std::ostringstream output{};
    PX(do_averages(input, output), output.str()) == "";
    } ////////////////////////////////////////////////////////////

    { ////////////////////////////////////////////////////////////
    std::istringstream input{"     \n"};
    std::ostringstream output{};
    PX(do_averages(input, output), output.str()) == "";
    } ////////////////////////////////////////////////////////////
}

void some_invalid_inputs() {
    { ////////////////////////////////////////////////////////////
    std::istringstream input{
            "1 5 7"     "\n"
            "1 S 7"     "\n"
            "15.7"      "\n"
    };
    std::ostringstream output{};
    PX(do_averages(input, output), output.str())
        >>= "4.33333"                            "\n"
             "non-numeric input - line ignored"  "\n"
             "15.7"                              "\n";
    } ////////////////////////////////////////////////////////////

    { ////////////////////////////////////////////////////////////
    std::istringstream input{
            "1 5 7"     "\n"
            "xxx 7"     "\n"
            "1 xyz 7"   "\n"
            "1 xyz"     "\n"
    };
    std::ostringstream output{};
    PX(do_averages(input, output), output.str())
        >>= "4.33333"                            "\n"
             "non-numeric input - line ignored"  "\n"
             "non-numeric input - line ignored"  "\n"
             "non-numeric input - line ignored"  "\n";
    } ////////////////////////////////////////////////////////////
}

void fails_on_my_mac_only() {
    { ////////////////////////////////////////////////////////////
    std::istringstream input{
            "1 xyz"     "\n"
            "1 abc"     "\n"
    };
    std::ostringstream output{};
    PX(do_averages(input, output), output.str())
        >>= "non-numeric input - line ignored"  "\n"
            "non-numeric input - line ignored"  "\n";
    } ////////////////////////////////////////////////////////////
}

int main() {
    typical_good_input();
    some_empty_inputs();
    some_invalid_inputs();
//  fails_on_my_mac_only();
}

#endif
