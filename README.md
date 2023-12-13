# AverageCalculator

Practical *Step by Step Exercise* Accompanying an introductory

## Step 1

Review some C code supplied as single source file.  (Prior
knowledge of the C language is expected so that step should be
skipped by participants without such knowledge.)

## Step 2

Compare the C code from Step 1 to equivalent C++ code and describe
advantages.

## Step 3

Split the single source used so far into a header and an
implementation; also replace default arguments with an additional
overload.

## Step 4

Turn pointer arguments into references.

## Step 5

Inner while look to be moved into a separate function `do_single_average`.

## Step 6

Parameterization of `do_single_average` modified to return the
result via a `struct sum_count` reference argument.

## Step 7

Having `do_single_average` return a boolean to indicate that the
input contained something which was not convertible into a `float`
value.

## Step 8

Turn indication indication of conversion problems inside
`do_single_reference` a `bool`-ean return value into throwing an
exception.
