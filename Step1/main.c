/*
 =================================================================
 Exercise 1 (for Solution see Exercise 2)
 =================================================================
 TODO:
 - Examine the C-program below and determine what it does.
 - When compiling with `onlineGDB` change the compiler C++20 in
   the *Language* drop down menu top right
 - When compiling with `g++` or `clang++` change the compile
   optional from
    -xc -std=c89
  (= oldest C version for standardize by ANSI/ISO) to
    -xc++ -std=c++20`
  (= C++ version standardized by ISO 30 years after the C))
 Will it still compile?

 -----------------------------------------------------------------

 TODO (optional - meant only for further self-study only):
 - How does the program react to input that is not numeric?
 - What needs to be modified if the values read from each input
   line are rather `double`-s than `float`?
 - What needs to be modified if the values read from each input
   line are rather `unsigned int`-s than `float`?
*/

#include <stdio.h>

void do_averages(FILE* in, FILE* out) {
    char line[100];
    while (fgets(line, sizeof line, in)) {
        float sum = 0.0f;
        int count = 0;
        int nchars = 0;
        float value;
        int nc;
        while (sscanf(&line[nchars], "%f%n", &value, &nc) == 1) {
            sum += value;
            ++count;
            nchars += nc;
        }
        if (count == 0) return;
        fprintf(out, "%f\n", sum/count);
    }
}

int main() {
    do_averages(stdin, stdout);
    return 0;
}
