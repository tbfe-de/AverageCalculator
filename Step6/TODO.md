# TODO

- Modify the parameterization of `do_single_average` to **return**
  the result via a reference argument `struct sum_count` with two
  elements:
  - one for the **count** of values found in an input line and
  - one for the **sum** of all values in that input line.

------------------------------------------------------------------

TODO (optional - meant for further self-study only):

- Discuss the advantages and disadvantages it would have to turn
  the current `struct sum_count` into a class with private data
  and public "getter"-s and "setter"-s?\
  Like that:

```cpp
class sum_count {
    float sum_{};
    int count_{};
public:
    auto getSum() const { return sum_; }
    auto setSum(float value) { sum_ = value; }
    auto getCount() const { return count_; }
    auto setCount(int value) { count_ = value; }
}
```

- Might it make more sense instead of the above getters and setters
  to put more of the required "processing" INTO MEMBER FUNCTIONS?\
  Like that:

```cpp
class sum_count {
    float sum_{};
    int count_{};

public:
    auto processNextInput(float value) { sum_ += value; ++count_; }
    auto haveSeenSomeInput() const { return (count_ > 0); }
    auto andTheAverageIs() const { return sum_/count_; }
};
```
