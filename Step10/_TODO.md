# TODO STEP 10

- Turn the `struct sum_count` into a `class Averager`
  - by making `operator<<` and `operator+=` friends and
  - providing a member function `getCount` to return the `count_`
    member in the two places where it is currently
    accessed directly.

-----------------------------------------------------------------

TODO (optional - meant for further self-study only):

- Turn `operator+=` for the `Averager` (currently implemented as
  free standing function) into a member function of that class.
- To class `Averager` add a helper member function `print` to do
  what the overloaded `operator<<` currently does.
  - It does not need to return a result, but
  - needs an argument of type `std:ostream&`.
  - Call that function as implementation of `operator<<` for the
    `Averager` class.
  - Now that `Averager`-s output operator shouldn't any longer
    need to be a `friend` of that class.
- To the class `Averager` add the member function shown below and
  use it where currently the `count_` member is accessed via its
  getter function.

```cpp
class Averager {
    …
public:
    …
    explicit operator bool() const { return (count_ != 0); }
    …
};
```

- Class `Averager`-s member function` is now not used any longer
  and may be removed.
