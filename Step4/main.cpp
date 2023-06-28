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
