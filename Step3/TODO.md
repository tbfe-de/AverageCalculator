# TODO

- Examine the file structure of the two implementation files (aka.
  translation units) `main.cpp` and `do_averages.cpp` and the
  single header file `averages.h`). together
- ¨Understand that in `main.cpp` there are two different `main`
   functions (though both cannot exist at the same time):
  - one is for interactive testing (as used in the previous step);
  - the other contributes a "TDD approach" (TDD = "Test Driven
    Development") which means the function `do_averages` is called
    with prepared input and its output is checked against
    expectations.
- Which `main` program gets compiled depends on whether the
  macro `TEST` is defined during on compilation.
  - you may add its definition directly to the source code in file
    `main.cpp` with a line near the beginning:\
    `#define TEST`
  - alternatively, if `g++` or `clang++` is used for compilation
    that macro can be defined without changing the source code in
    `main.cpp` by using the command line option `-DTEST`.

Currently `do_averages` has default arguments, which allows to
call it without any arguments from the `main` function for
interactive use.

- Remove the default arguments and add an overload instead, so
  that call without arguments in `main` for interactive use can
  stay the same.

NOTE: Do not invest time into examining the files `pxt.h` and
`pxt.cpp`.\
**YANETUT (You Are Not Expected To Understand This.)**\
Their content is "advance stuff" when it comes to *how it is
implemented* but still meant to be *easy to use* for "test
driven development". The only point to make sure is to hand over
the names of all implementation files including `pxt.cpp` to the
compile command by using `*.cpp`.

-----------------------------------------------------------------

TODO (optional - meant for further self-study only):

- Add some more tests, especially for the border cases like:
  - completely empty input
  - just a single number
  - empty line between non-empty lines
  - non-numeric input in the middle
  - non numeric input at the start
- Build "test groups" by putting related tests in a single
  function, then from `main` just call theses functions. (The
  intent here is that now each test group can be easily enabled or
  disabled by putting a '//'-comment in front of such a function
  call.)
