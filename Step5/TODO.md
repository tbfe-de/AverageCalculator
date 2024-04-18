# TODO

- Move the INNER loop of `do_averages` together with all statement
  accessing any of the variables `value`, `sum`, and `count` into
  new function called `do_single_average`. Its argument should be
  - an `std::istream&` (by which the `std::istringstream` holding
    the single line just read is forwarded) and
  - an `std::ostream` reference (by which `out` is forwarded).
  - The return value of `do_single_average` should be a `bool`-ean
    which indicates whether the OUTER loop (in `do averages`)
    - should `continue` (if `do_single_average` returns `true`) or
    - `return` (in case `do_single_reference` returns `false`).
- Apart from that the OUTER loop should remain unchanged.

------------------------------------------------------------------

TODO (optional - meant for further self-study only):

- Show that instead of calling `do_single_average` with a first
  `std::string` argument it would also be possible to forward
  the single line to process as an `std::istream` reference.
- If the modified function would not return a `bool`-result to
  help the caller decide whether the OUTER loop is to be continued
  or terminated, how could it still decide whether to end or
  not if an empty line is read?\
  (HINT: a test whether the line just read – which available as an
  `std::string` in the local variable `line` - contains no values
  at all can be made with `line.empty()`.)
- If you followed the hint from above, what would happen if as
  input just some spaces (but no number) ist typed by the
  interactive user?
- What solutions are available to test whether an `std::string`
  contains nothing but a sequence of "white-space" characters?
