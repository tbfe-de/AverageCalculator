/*
 =================================================================
 Step 12_3b (Solution for Step12 optional part 3 - 2nd variant)
 =================================================================
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

using my::do_averages;

void typical_good_input() {
    { ////////////////////////////////////////////////////////////
    std::istringstream input{
            "1 5 7"     "\n"
            "1.5 7"     "\n"
            "15.7"      "\n"
    };
    std::ostringstream output{};
    PX(do_averages(input, output), output.str())
        >>= "1 ... 7"       "\n"
            "1.5 ... 7"     "\n"
            "15.7 ... 15.7" "\n";
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
        >>= "1 ... 7"                            "\n"
             "non-numeric input - line ignored"  "\n"
             "15.7 ... 15.7"                     "\n";
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
        >>= "1 ... 7"                            "\n"
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
