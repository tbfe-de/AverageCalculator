TODO:

- Examine the C++-program below and how it differs from the one
  in Step1.
- What are the obvious simplifications by using `std::string`
  instead of a char-Array to store whole lines of input wrt.
  - setting a limit for the longest line that can be processed
  - extracting numbers from that line?

------------------------------------------------------------------

TODO (optional - meant for further self-study only):

- How does the program react to input that is not numeric?
- What needs to be modified if the values read from each input
  line are rather `double`-s than `float`?
- What needs to be modified if the values read from each input
  line are rather `unsigned int`-s than `float`?
- How would the program need to be re-structured if each of the
  functions `main` and `do_averages` will have their
  implementation in its own translations unit:
  - `main.cpp`
  - `do_averages.cpp`
- Furthermore there need to be header file with the prototype of
  `do_average` so that in can be in included in `main.cpp`:
  - `do_averages.h`
