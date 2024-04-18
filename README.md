# AverageCalculator

*Step by Step Exercise* accompanying an introductory C++ Training.

## Step 1

Review some C code supplied as single source file as "warm up".
(Prior knowledge of the C language is expected. Participants
without such knowledge may skip skip this step.)

## Step 2

Compare some C code (from the previous step) to equivalent C++
code, describing the recognized advantages and disadvantages.
(This step is also meant to learn using VSCODE's "Diff Folders"
Plugin which you should installed before. Or if a different IDE
some other an appropriate diff-viewer.)

## Step 3

(a) Split a single source file into header and an implementation.
(b) Replace default arguments with a function overload.

## Step 4

Turn pointer arguments into references.

## Step 5

Move a nested `while`-loop into a function of its own.

## Step 6

Modify the parameterization a function to return a result
consisting of two values via a (non-`const`) reference to a
`struct` with two elements.

## Step 7

Give a function a result type `bool` and return `false` if some
of the inputs in the current line wasn't a `float` value, or
`true` if all input was accepted.

## Step 8

Instead of indicating the conversion problems inside function via
a `boolean` return value (like in the previous step) do it by
`throw`-ing an exception which the caller then has to `catch`.
