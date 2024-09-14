# TODO STEP 7

- Let the function `do_single_average` return a `bool`-result
  to indicate whether all the input was numeric or not.
- When `do_averages` calls `do_single_average` and receives the
  result `false` it should show a message that it ignores this
  line of input.
- If there has been non-numeric input the content of `sum_count`
  should NOT be considered for the decision whether to end the
  loop in `do_averages.

HINT: The decision whether there has been non-numeric input in a
line can be made in `do_single_average` by looking at both, the
count of successfully read data items and the state of the
`std::istringstream iss`:

```cpp
   …
   if (((result.count > 0) && !iss.eof())
    || (iss.fail() && !is.eof()))
       return false;
   else
       return true;
   …
```

Why is the test that complicated?

- If already seen some values but not yet having arrived at "eof"
  (which actually is "end of line" in this case) then there has
  been something in the input that was not numeric:

   ```cpp
   … (result.count > 0) && !iss.eof() …
   ```

- Same if extracting some value failed but the end has not been
  reached:

   ```cpp
   … iss.fail() && !iss.eof() …
   ```

- Both need to be or-ed together to get a `true` result if there
  have been errors and hence `false` must be returned from
  `do_single_average`.

-----------------------------------------------------------------

TODO (optional - meant for further self-study only):

- Further explore how the "state bits" for `fail` and `eof` are
  set in an `std::istream` depending on the validity of the the
  input when numeric values are extracted.
- How can the above logic to test for invalid input be simplified
  if the line turned into an `std::istringstream` would **still
  contain** the trailing `'\n'`, which has been stripped off when
  the line was read into an `std::string` using `std::getline`?
- Based on the above, how might `do_averages` "help" the called
  function `do_single_average` to simplify the test?
