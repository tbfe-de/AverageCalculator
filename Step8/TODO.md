TODO:

- Instead of returning the indication if there has been bad
  input with with a `bool`-result throw an exception.
- The simple-most solution would be to just `throw` the message to
  be displayed by `do_averages` before continuing as, ie. the type
  caught by catch would be `char const*`.

-----------------------------------------------------------------

TODO (optional - meant for further self-study only):

- Come up with more sophisticated ways to construct an error
  message in `do_single_average`. eg. build an `std::string`
  naming the offending (non-numeric) character and its position
  in the input line.
- Of course, if an `std::string` is thrown instead of a simple
  string literal in double quotes the type expected by catch
  needs to be changed accordingly.

- HINT: After a failed application of `operator>>` like

   ```cpp
   float value;
   iss >> value;
   ```

   the not yet processed part of an `std::istringstream`
   representing a single line of input the unread remainder may be
   retrieved like this:

   ```cpp
   if (iss.fail() && !iss.eof())     // failed before eol
       iss.clear();                  // clear fail state
       std::string remainder{};      // variable to read ...
       std::getline(iss, remainder); // ... what remains
   }
   ```
