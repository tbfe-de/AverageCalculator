# Project AverageCalculator

A *Step by Step Exercise* to accompany an introductory C++ Training.

Each of these steps is provided as a set of files including a
`_TODO_.md` file, describing what should be achieved in this
step. Usually, there is a *Mandatory Part*, meant to be done
by the students during the time slots left for practical
exercises.

It is followed by an optional part, meant either as a challenge
for students with above-average prior knowledge, or to do as
homework, or during a later self-study recapitulation of the
course content.

Solutions for the mandatory parts are typically provided as the next
step, i.e., the code presented in "Step 2" is what was the expected 
result of solving "Step 1", "Step 3" for "Step 2", etc. Solutions
to optional parts are not included as source code but may be discussed during the training, depending on available time and
whether sufficient interest is expressed by the students to see
the solution. 

## Step 1

Review some C code supplied as a single source file as a "warm-up".
(Prior knowledge of the C language is expected. Participants
without such knowledge may skip this step.)

## Step 2

Compare some C code (from the previous step) to equivalent C++
code, describing the recognized advantages and disadvantages.
(This step is also meant to learn using VS Code's "Diff Folders"
Plugin which you should install before. Or if using a different IDE,
some other appropriate diff-viewer.)

## Step 3

(a) Split a single source file into a header and an implementation.
(b) Replace default arguments with a function overload.

## Step 4

Turn pointer arguments into references.

## Step 5

Move a nested `while`-loop into a function of its own.

## Step 6

Modify the parameterization of a function to return a result
consisting of two values via a (non-`const`) reference to a
`struct` with two elements.

## Step 7

Give a function a result type `bool` and return `false` if some
of the inputs in the current line weren't `float` values, or
`true` if all input was accepted.

## Step 8

Instead of indicating the conversion problems inside the function via
a `boolean` return value (like in the previous step), do it by
`throw`-ing an exception which the caller then has to `catch`.

## Step 9

Replace explicit `struct` initialization with direct initialization
of its members, and provide overloads for two operators involving
that `struct`.

## Step 10

Turn a `struct` into a `class` with access protection, using two
different ways to provide access to non-member functions so that
these can do what they need to do.

## Step 11

Move a class into files of its own, properly separating between 
"Header" and "Implementation" files.

## Step 12

This code is only provided as a solution to the prior step.

The final optional steps suggest to make the last version
easily extensible by implementing this architecture:

                     +--------------------------+
                     |       <<interface>>      |
                     |      IValueProcessor     |
                     |--------------------------|
  do_processing - - >| + reset()                |
                     | + operator+=()           |
                     | + print() {readonly}     |
                     | + hasValues() {readonly} |
                     +--------------------------+
                                   ^
                    <<implements>> |
                                   |
                     +-------------+-------------+
                     |                           |
            +-----------------+         +-----------------+
            |    Averager     |         |     MinMaxer    |                           
            +-----------------+         +-----------------+
