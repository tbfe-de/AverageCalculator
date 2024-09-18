/*
 =================================================================
 Step 12_3a (Solution for Step12 optional part 3 (2nd variant)
 =================================================================
*/

#include "do_processing.h"
#include "Averager.h"
#include "MinMaxer.h"

#include <iostream>
    // std:cerr
#include <sstream>
    // std::istringstream

#ifndef TEST
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << "A\n"
                  << "  -or- " << argv[0] << "  X\n";
    }
    else switch (argv[1][0]) {
        case 'A': {
            my::Averager processor{};
            my::do_processing(std::cin, std::cout, processor);
            break;
        }
        case 'X': {
            my::MinMaxer processor{};
            my::do_processing(std::cin, std::cout, processor);
            break;
        }
        default:
            std::cerr << "Invalid argument\n";
    } 
}
#else
#include "pxt.h"

using my::do_processing;

void typical_good_inputs_for_averages() {
    { ////////////////////////////////////////////////////////////
    std::istringstream input{
            "1 5 7"     "\n"
            "1.5 7"     "\n"
            "15.7"      "\n"
    };
    std::ostringstream output{};
    my::Averager processor{};
    PX(do_processing(input, output, processor), output.str())
        >>= "4.33333"   "\n"
            "4.25"      "\n"
            "15.7"      "\n";
    } ////////////////////////////////////////////////////////////
}

void typical_good_inputs_for_minmaxes() {
    { ////////////////////////////////////////////////////////////
    std::istringstream input{
            "1 5 7"     "\n"
            "1.5 7"     "\n"
            "15.7"      "\n"
    };
    std::ostringstream output{};
    my::MinMaxer processor{};
    PX(do_processing(input, output, processor), output.str())
        >>= "1 ... 7"       "\n"
            "1.5 ... 7"     "\n"
            "15.7 ... 15.7" "\n";
    } ////////////////////////////////////////////////////////////
}

void some_empty_inputs_for_averages() {
    { ////////////////////////////////////////////////////////////
    std::istringstream input{"\n"};
    std::ostringstream output{};
    my::Averager processor{};
    PX(do_processing(input, output, processor), output.str()) == "";
    } ////////////////////////////////////////////////////////////

    { ////////////////////////////////////////////////////////////
    std::istringstream input{"     \n"};
    std::ostringstream output{};
    my::Averager processor{};
    PX(do_processing(input, output, processor), output.str()) == "";
    } ////////////////////////////////////////////////////////////
}

void some_empty_inputs_for_minmaxes() {
    { ////////////////////////////////////////////////////////////
    std::istringstream input{"\n"};
    std::ostringstream output{};
    my::MinMaxer processor{};
    PX(do_processing(input, output, processor), output.str()) == "";
    } ////////////////////////////////////////////////////////////

    { ////////////////////////////////////////////////////////////
    std::istringstream input{"     \n"};
    std::ostringstream output{};
    my::MinMaxer processor{};
    PX(do_processing(input, output, processor), output.str()) == "";
    } ////////////////////////////////////////////////////////////
}

void some_invalid_inputs_for_averages() {
    { ////////////////////////////////////////////////////////////
    std::istringstream input{
            "1 5 7"     "\n"
            "1 S 7"     "\n"
            "15.7"      "\n"
    };
    std::ostringstream output{};
    my::Averager processor{};
    PX(do_processing(input, output, processor), output.str())
        >>= "4.33333"                            "\n"
             "non-numeric input - line ignored"  "\n"
             "15.7"                     "\n";
    } ////////////////////////////////////////////////////////////

    { ////////////////////////////////////////////////////////////
    std::istringstream input{
            "1 5 7"     "\n"
            "xxx 7"     "\n"
            "1 xyz 7"   "\n"
            "1 xyz"     "\n"
    };
    std::ostringstream output{};
    my::Averager processor{};
    PX(do_processing(input, output, processor), output.str())
        >>= "4.33333"                            "\n"
             "non-numeric input - line ignored"  "\n"
             "non-numeric input - line ignored"  "\n"
             "non-numeric input - line ignored"  "\n";
    } ////////////////////////////////////////////////////////////
}

void some_invalid_inputs_for_minmaxes() {
    { ////////////////////////////////////////////////////////////
    std::istringstream input{
            "1 5 7"     "\n"
            "1 S 7"     "\n"
            "15.7"      "\n"
    };
    std::ostringstream output{};
    my::MinMaxer processor{};
    PX(do_processing(input, output, processor), output.str())
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
    my::MinMaxer processor{};
    PX(do_processing(input, output, processor), output.str())
        >>= "1 ... 7"                            "\n"
             "non-numeric input - line ignored"  "\n"
             "non-numeric input - line ignored"  "\n"
             "non-numeric input - line ignored"  "\n";
    } ////////////////////////////////////////////////////////////
}

void fails_on_my_mac_only_for_averages() {
    { ////////////////////////////////////////////////////////////
    std::istringstream input{
            "1 xyz"     "\n"
            "1 abc"     "\n"
    };
    std::ostringstream output{};
    my::Averager processor{};
    PX(do_processing(input, output, processor), output.str())
        >>= "non-numeric input - line ignored"  "\n"
            "non-numeric input - line ignored"  "\n";
    } ////////////////////////////////////////////////////////////
}

void fails_on_my_mac_only_for_minmaxes() {
    { ////////////////////////////////////////////////////////////
    std::istringstream input{
            "1 xyz"     "\n"
            "1 abc"     "\n"
    };
    std::ostringstream output{};
    my::MinMaxer processor{};
    PX(do_processing(input, output, processor), output.str())
        >>= "non-numeric input - line ignored"  "\n"
            "non-numeric input - line ignored"  "\n";
    } ////////////////////////////////////////////////////////////
}

void run_tests_for_averages() {
    typical_good_inputs_for_averages();
    some_empty_inputs_for_averages();
    some_invalid_inputs_for_averages();
//  fails_on_my_mac_only_for_averages();
}

void run_tests_for_minmaxes() {
    typical_good_inputs_for_minmaxes();
    some_empty_inputs_for_minmaxes();
    some_invalid_inputs_for_minmaxes();
//  fails_on_my_mac_only_for_minmaxes();
}

int main() {
    run_tests_for_averages();
    run_tests_for_minmaxes();
}

#endif
