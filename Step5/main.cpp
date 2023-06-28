/*
 =================================================================
 Exercise 5 (for Solution see Exercise 6)
 =================================================================
 TODO:
 - Move the INNER loop of `do_averages` into a function of its
   own, called `do_single_average`. Its argument should be
   - an `std::string` (the single line just read) and
   - an `std::ostring` reference by which `out` is forwarded(to show
      the average)
   Its return value should be a `bool`-ean which indicates that
   the OUTER loop (in `do averages`) should
    - continue (if `true` is returned) or
    - or be left (if `false` is returned
   (Apart from that The OUTER loop should remain unchanged.)

 -----------------------------------------------------------------

 TODO (optional - meant for further self-study only):
 - Show that instead of calling `do_single_average` with a first
   `std::string` argument it would also be possible to forward
   the single line top process as an `std::istream` reference?
 - If the new function would not return a `bool`-result to help
   the caller decide whether the OUTER loop should be continued
   or terminated, how could it still decide whether to end or
   not if an empty line is read. (HINT: a test whether the line
   read available in the local variable `line` can be made with
   `line.empty()`)
 - If you followed the hint just given, what would happen if as
   input just some spaces (but no number) were used?
 - What solutions are there to test whether an `std::string`
   contains nothing but a sequence of "white-space" characters.
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
