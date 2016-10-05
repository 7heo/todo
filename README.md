todo
====

Simple ToDo script to print out the list of the things to do.

usage
-----
Write your todo items in files named after your project, in the ~/.TODO/
directory.

Then invoke with:

    $ todo

Notes
-----

- If placed in the `$PATH`, and if the `todo` script name is appended to your
  `${SHELL}rc`, you will have a reminder about the tasks to do every time you
  open a shell.
- If you want to hide a ToDo item, simply hide it from the system (prefix it
  with a `.` (dot)).
- If you want to order your ToDo items, simply prefix them with a numeric
  prefix, followed by a single dash. The will be displayed in the order your
  shell globs numbers.
- Empty `.TODO/*` files are ignored.
