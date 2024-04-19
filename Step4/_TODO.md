# TODO STEP 4

Currently the arguments handed over to `do_average` are pointers.

- Do all the changes necessary to turn them into references.

-----------------------------------------------------------------

TODO (optional - meant for further self-study only):

- Inform yourself (eg. using `cppreference.com`) about the
  purpose of the header file `<iosfwd>`.
- In which place were its use more appropriate than the currently
  used `<iostream>`?
- Why hadn't that change been possible in the version handing
  over the arguments as pointers, using `&std::cin` and
  `&std::cout` as default values?
- Why in the current versions wouldn't that change be possible
  if the overload with no arguments were defined as `inline`
  function?
