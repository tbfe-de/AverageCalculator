TODO:

- Move the INNER loop of `do_averages` into a function of its
  own, called `do_single_average`. Its argument should be
  - an `std::stream` reference, by which the `std::istringstream`
    holding the single line just read is forwarded) and
  - an `std::ostream` reference by which `out` is forwarded.
  The return value of `do_single_average` should be a `bool`-ean
  to indicate whether the OUTER loop (in `do averages`) should
    - `continue` (if `true` is returned) or
    - or `return` (if `false` is returned)
  (Apart from that The OUTER loop should remain unchanged.)

------------------------------------------------------------------

TODO (optional - meant for further self-study only):

- Show that instead of calling `do_single_average` with a first
  `std::string` argument it would also be possible to forward
  the single line top process as an `std::istream` reference?
- If the new function would not return a `bool`-result to help
  the caller decide whether the OUTER loop should be continued
  or terminated, how could it still decide whether to end or
  not if an empty line is read.\
  (HINT: a test whether the line read available in the local
  variable `line` can be made with `line.empty()`)
- If you followed the hint just given, what would happen if as
  input just some spaces (but no number) were used?
- What solutions are there to test whether an `std::string`
  contains nothing but a sequence of "white-space" characters.
