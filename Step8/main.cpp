/*
 =================================================================
 Exercise 8 (for Solution see Exercise 9)
 =================================================================
  - Instead of returning the indication if there has been bad
    input with with a `bool`-result throw an exception.
  - The simple-most solution would be to just `throw` the message
    to be displayed by `do_averages` before continuing as, ie.
    he type caught by catch would be `char const*`.

 -----------------------------------------------------------------

 TODO (optional - meant for further self-study only):
 - Come up with more sophisticated ways to construct an error
   message in `do_single_average`. eg. build an `std::string`
   naming the offending (non-numeric) character and its position
   in the input line.
 - Of course, if an `std::string` is thrown instead of a simple
   string literal in double quotes the type expected by catch
   needs to be changed accordingly.

 HINT: After a failed application of `operator>>` like
    float value;
    iss >> value;
 the not yet processed part of an `std::istringstream`
 representing a single line of input the unread remainder may be
 retrieved like this:
    if (iss.fail() && !iss.eof())   // failed before eol
        iss.clear();                // clear fail state
        std::string remainder{};    // variable to read ...
        std::getline(iss, remainder);   // ... what remains
    }
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
    std::istringstream test_input{
            "1 5 7"     "\n"
            "1.5 7"     "\n"
            "15.7"      "\n"
    };
    std::ostringstream received_output{};
    PX(do_averages(&test_input, &received_output), received_output.str())
    #if 0 // expectations are specified as classic C literals (which
          // are getting concatenated if seperated by white-space only)
        >>= "4.33333"   "\n"
             "4.25"     "\n"
             "15.7"     "\n";
    #else // alternatively expectations can be specified as raw strings
          // literals (since C++11) requiring less quoting as everything
          // inside is taken literal (especially the line endings)
        >>= R"(
                4.33333
                4.25
                15.7
        )";
    #endif
 }

#endif
