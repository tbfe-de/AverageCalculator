/*
 =================================================================
 Exercise 7 (for Solution see Exercise 8)
 =================================================================
 TODO:
 - Have the function `do_single_average` return a `bool`-result
   to to indicate whether all the input was numeric or not.
 - When `do_averages` calls `do_single_average` and receives the
   result `false` it should show a message that it ignores this
   line of input.
 - If there has been non-numeric input the content of `sum_count`
   should NOT be considered for the decision whether to end the
   loop in `do_averages.

 HINT: The decision in whether there has been non-numeric input
 in a line can be made in `do_single_average` by looking at both,
 the count of successfully read data items and the state of the
 `std::istringstream iss` as follows:
    if (((result.count > 0) && !iss.eof())
     || (!iss.fail() && !iss.eof())) ...

 -----------------------------------------------------------------

 TODO (optional - meant for further self-study only):
 - Further explore how the "state bits" for `fail` and `eof` are
   set in an `std::istream` depending on the validity of the the
   input when numeric values are extracted.
 - How can the above logic to test for invalid input be simplified
   if the line turned into an `std::istringstream` would still
   contain the trailing `'\n'` which is stripped off as the line
   was read into an `std::string` with `std::getline`?
 - Based on the above, how might `do_averages` "help" the called
   function `do_single_average` to simplify the test?

   the sum and the count as return value of `do_averages` instead
   via a reference argument.
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
