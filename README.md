# AverageCalculator

*Step by Step Exercise* accompanying an introductory C++ Training.

## Step 1

Review some C code supplied as single source file as "warm up".
(Prior knowledge of the C language is expected. Participants
without such knowledge may skip skip this step.)

## Step 2

Compare the C code from Step 1 to equivalent C++ code and describe
the advantages and disadvantageous you recognize. (Note that this
step is also meant to learn to use VSCODE's "Diff Folders" Plugin,
which you should install now if it isn't already present. In case
you use a different IDE find an appropriate diff-viewer.)

## Step 3

Split the single source used so far into a header and an
implementation; also replace default arguments with an additional
overload.

## Step 4

Turn pointer arguments into references.

## Step 5

Move the innermost `while`-loop into a function of its own, named
`do_single_average`.

## Step 6

Modify the parameterization of `do_single_average` to return the
result via a reference argument  `struct sum_count` which has two
elements, one for element count and another one for the sum of all
elements.

## Step 7

Give `do_single_average` a result type `bool` and return return
`false` if some of the inputs wasn't a `float` value.

## Step 8

Instead of indicating conversion problems inside the function
`do_single_average` (ie. some input is not convertible to `float`)
via the result throw an exception.
