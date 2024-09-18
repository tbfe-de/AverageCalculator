# TODO STEP 12

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

- Generalize the `Averager` class into a "value processor" so
  that instead of calculating averages other things may be done,
  like eg. to determine the minimum and maximum value in a line.
  - If you feel comfortable with writing template classes you may
    generalize the type of values to be processed right from the
    start, but it is easier to postpone the "templatization"
    until a simple (non-template) class is available and only
    prepare that step with a type alieas (eg. `value_type`).
  - Define an interface `IValueProcessor` with the virtual
    functions `operator+=` and `print`. (The latter is useful as
    a helper for the implementation of `operator<<`).
    The definition of the type alias can go here too.
  - Have the current `Averager` implement that interface and now,
    when everything is in place re-compile and run the tests.

- Review the current design under the point of view what is
  still missing to fully generalize `do_averages` to process the
  values in a line eg. in regard to their minima and maxima.
  - The final goal is to add another argument to `do_averages`
    that determines the "ValueProcessor" to be used, which can
    be any class implementing the `IValueProcessor` interface.
  - If you try to do that you will notice that this interface
    needs to have another method, to query if there have been
    some values seen.
  - Also, if other ways of "value processing" are added, the
    the functions `do_averages` and `do_single_averages` become
    misnomers and should propably be renamed. 

- Add a third argument of type `IValueProcessor&` to the
    function once named `do_averages` and provide an `Averager`
    object in the `main` (interactive and/or for automated testing).
  - To demonstrate the independance from just doing the "average"
    and another implementation of `IValueProcessor` to determine
    minima and maxima of a line.
  - Maybe test "interactive" only but preferably provide automated
    tests for it … lots of tests.

- Based on an `std::vector<Averager>` "pivot" the current output:
  - averages should be calculated in columns (instead per line)
  - and a final line with the average (or the minima and maxima)
    of each column added.

**Note:** This file will probably be extended with new ideas now
and then. You are welcome to return from time to time if you are
looking for more "programming challenges" based on this example.

SO STAY TUNED.
