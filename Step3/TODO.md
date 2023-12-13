TODO:

- Examine the file structure of the two translation units
  - `main.cpp` and
  - `do_averages` together with the shared header file
  - `do_averages.h`

- Note that in `main.cpp` there are now two different `main`
  functions.
  - One is for interactive testing (as used in the previous step).
  - The other contributes a "TDD approach" (TDD = "Test Driven
    Development") which means the function `do_averages` is called
    with prepared input and its output is checked against
    expectations.
- Which `main` program gets compiled depends on whether the
  macro `TEST` is defined during on compilation?
  - Given `g++` or `clang++` is used for compilation that macro
    can be defined using the command line option
    `-DTEST`.
- Currently `do_averages` has default arguments,
    which allows to call it without any arguments from the `main`
    function. Remove the default arguments and instead add an
    overload without no arguments so that the call in `main` can
    stay the same.

-----------------------------------------------------------------

TODO (optional - meant for further self-study only):

- Add some more tests, especially for the border cases like:
  - completely empty input
  - just a single number
  - empty line between non-empty lines
  - non-numeric input in the middle
  - non numeric input at the start
- Build group of tests and put them in a function of their own
  with `main` calling these functions.
