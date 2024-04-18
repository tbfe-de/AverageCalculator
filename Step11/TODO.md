# TODO

- Move the class `Averager` into files of their own properly in
  dividing it into
  - a header file (`Averager.h`) with the class definition and
  - an implementation file (`Averager.cpp`) for the non-`inline`
    member and friend functions (if any).
- Accordingly add `#include` directives to the file(s) which need
  to know the class definition.

Note: If you already compile handing ALL implementation files to
the compiler with `*.cpp` nothing more needs to be done. In case
you use a more sophisticated build mechanism (like *Makefiles* or
*CMake*) you may need to adapt it, so that a new object file
(`Averager.o`) is created by the compiler and then included in the
linker command.

-----------------------------------------------------------------

TODO (optional - meant for further self-study only):

- Move the class definition of `Averager` into its own header
  file and the out-of-class definition of its friend functions
  into an implementation file.
