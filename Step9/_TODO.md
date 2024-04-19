# TODO STEP 9

- Turn the explicit initialization of `struct sum_count sc` into a
  direct member initialization.
- Overload `operator<<` for it so that it shows the quotient of
  the members `sum` and `count`.
- Add a member function `operator+=` to it with a right-hand
  operand of type `float` which
  - adds that value the `sum` element and
  - increments the `count` element.

-----------------------------------------------------------------

TODO (optional - meant for further self-study only):

Meticulously verify the correct behavior of the part that
recognizes "bad" (= non-`float`) parts of a input line by adding
more tests.

- Try bad input at each position of an input line:
  - right at its begin
  - somewhere in the middle
  - at the very last element
- Identify a strange quirk of "reading" a `float` value from an
  `std::istream` which shows up as handling bad input consisting
   of characters `'a'` to `'f'` only differently from bad input
   containing any other characters.

Hint: for the kind of scrutiny necessary to do this "deep dive"
into the behavior of `std::operator>>` (for floating point values
you best write a little program which in a loop reads `float`-s
from an `std::istream` and for each run through the loop shows
this:

- the value returned from the `std::istream` member function
  `good()`;
- the value returned from the `std::istream` member function
  `fail()`;
- the value returned from the `std::istream` member function
  `eof()`;
- the value resulting from an automatic  conversion of the
  `std::istream` object a `bool`-ean;
