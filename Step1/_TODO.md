# TODO STEP 1

- Examine the C-program `main.c` and determine what it does.
  If you think you understand, predict the output if you compile
  the program (see below) and run it from the command line as
  `./a.out` nd use the following input:
  - `1  2.2  3  4.75  0.05` (all in a single line)
  - Understand as the program reads lines in a loop you need to
    indicate the end of your input by either typing CTRL-D or with
    an empty line (or try some more test inputs).
- Assuming you use the `gcc` directly from a terminal window, will
  that source code compile without any modifications if you use
  any of the two commands:
  - `gcc -xc -std=c89 main.c` (= version of the C language as
   standardized by ANSI 1989 and ISO 1990)
  - `g++ -xc++ -std=c++23 main.c` (= version of the C++language
   as standardized by ISO 33 years later)

REMARK 1:
If you use the CLANG compiler family instead of GCC you may need
to change the compile command to `clang` or `clang++`
respectively.

REMARK 2:
If C++23 is not (yet) supported on your system - or just out of
curiosity - also try some older versions of C++ with `-std=c+20`,
`-std=c++17`, `-std=c++14`, `-std=c++11`, or `-std=c++98`.

-----------------------------------------------------------------

TODO (optional - meant for further self-study only):

- How does the program react to input that is not numeric?
- What needs to be modified if the values read from each input
  line are `double`-s instead of `float`-s?
- What needs to be modified if the values read from each input
  line are rather `unsigned int`-s instead of `float`-s?
