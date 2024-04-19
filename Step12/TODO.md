# TODO

[nothing more - this step is only provided as solution]

-----------------------------------------------------------------

TODO (optional - meant for further self-study only):

Here are some ideas for more programming exercises based what has
been achieved so far. These steps are mostly independent of each
other so you make "pick and chose" according to what matches your
interest best.

- Put every class and function developed as part of this code
  - either into an anonymous namespace (if it only needs to be
    visible in a single translation unit);
  - or into the namespace `my` (if it needs to be visible across
    translation units)

- Turn the helper function `do_single_average` into a local named
  lambda defined inside `do_averages`.

- Generalize the `Averager` class into a `ValueProcessor` so
  that instead of calculating averages other things may be done,
  like eg. to determine the minimum and maximum value in a line.
  - If you feel comfortable with writing template classes you may
    generalize the type of values to be processed right from the
    start, but the "templatization" step may also be postponed
    until a simple (non-template) class is available.
  - Define an interface `IValueProcessor` with the virtual
    functions `operator+=` and `print`. (The latter is useful as
    a helper for the implementation of `operator<<`.
  - Have the current `Averager` implement that interface.
  - Add a third argument of type `IValueProcessor const&` to the
    function `do_averages` and provide an `Averager` object in the
    `main` (interactive and/or for automated testing).
  - As alternative to the `Averager` provide a `MinMaxer` as
    second implementation of `IValueProcessor`.
  - Maybe test "interactive" only but preferably provide automated
    tests for it … lots of tests.

- Based on an `std::vector<Averager>` "pivot" the current output:
  - averages should be calculated in columns (instead per line)
  - and a final line with the average of each column added.

**Note:** This file will probably be extended with new ideas now
and then. You are welcome to return from time to time if you are
looking for more "programming challenges" based on this example.

SO STAY TUNED.
