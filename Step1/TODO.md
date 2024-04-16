 TODO:
- Examine the C-program `main.c` and determine what it does.
- Assuming you use the `gcc` directly from a terminal window, will
  that source code compile without any modifications if you use
  any of the two commands:
  -  `gcc -xc -std=c89 main.c` (= version of the C language as
     standardized by ANSI 1989 and ISO 1990)
  -  `g++ -xc++ -std=c++23 main.cpp` (= version of the C+ language
     as standardized by ISO 33 years later)

REMARK: If you use the CLANG compiler family instead of GCC you
may need to change the compile command to the command `clang` or
`clang++` respectively. If C++23 is not yet supported on your
system (or just out of curiosity) maybe try some earlier versions
with `-std=c+20`, `-std=c++17`, `-std=c++14`, `-std=c++11`, and/or
`-std=c++98`.

 -----------------------------------------------------------------

TODO (optional - meant for further self-study only):

- How does the program react to input that is not numeric?
- What needs to be modified if the values read from each input
  line are `double`-s instead of `float`-s?
- What needs to be modified if the values read from each input
  line are rather `unsigned int`-s instead of `float`-s?
