# TODO STEP 8

- Throw an exception instead of returning the indication whether
  there has been incompletely processed input with with a
  `bool`-result throw an exception.
- The simple-most solution would be to just `throw` the message,
  eg. "non-numeric value in input line" to be displayed by
  `do_averages` before continuing. Ie. the type to be caught by
  the `catch`-block would be `char const*`.

------------------------------------------------------------------

TODO (optional - meant for further self-study only):

- Come up with more sophisticated ways to construct an error
  message in `do_single_average`. eg. build an `std::string`
  naming the offending (non-numeric) character and its position
  in the input line.
- Of course, if an `std::string` is thrown instead of a simple
  string literal in double quotes, the type expected by catch
  needs to be changed accordingly.

- HINT: After a failed application of `operator>>` like

   ```cpp
   float value;
   iss >> value;
   ```

   the not yet processed part of an `std::istringstream`
   (representing a single line of input) may be retrieved like
   this:

   ```cpp
   if (iss.fail() && !iss.eof()) // incompletely processed line
       iss.clear();                  // clear the fail state
       std::string remainder{};      // variable used to read ...
       std::getline(iss, remainder); // ... what still remains
   }
   ```
