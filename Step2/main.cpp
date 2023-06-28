/*
 =================================================================
 Exercise 2 (for Solution see Exercise 3)
 =================================================================
 TODO:
 - Examine the C++-program below and how it differs from the one
   in Step1.
 - What are the obvious simplifications by using `std::string`
   instead of a char-Array to store whole lines of input wrt.
   - setting a limit for the longest line that can be processed
   - extracting numbers from that line?

------------------------------------------------------------------

 TODO (optional - meant for further self-study only):
 - How does the program react to input that is not numeric?
 - What needs to be modified if the values read from each input
   line are rather `double`-s than `float`?
 - What needs to be modified if the values read from each input
   line are rather `unsigned int`-s than `float`?
 - How would the program need to be re-structured if the functions
   `main` and `do_averages` should each have their own
    translations unit on their own as files
   - `main.cpp`
   - `do_averages.h`
   and a header files
   - `do_averages.h`
   in which the the prototype of `do_averages` is defined?
*/

//@impl main.cpp

//@impl main.cpp
//
#include <iostream>
    // std::cin
    // std::cout
    // std::endl
    // std::istream
    // std::ostream
#include <string>
    // std::getline
    // std::string
#include <sstream>
    //std::istringstream

void do_averages(std::istream& in, std::ostream& out) {
    std::string line;
    while (std::getline(in, line)) {
        float sum = 0.0f;
        int count = 0;
        float value;
        std::istringstream iss{line};
        while (iss >> value) {
            sum += value;
            ++count;
        }
        if (count == 0) return;
        out << sum/count << std::endl;
    }
}

int main() {
    do_averages(std::cin, std::cout);
}
