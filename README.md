todo
====

Simple ToDo script to print out the list of the things to do.

usage
-----
Write your todo items in files named after your project, in the ~/.TODO/
directory (configurable in the script).

Then invoke with:

    $ todo

Notes
-----

- If placed in the `$PATH`, and if the `todo` script name is appended to your
  `${SHELL}rc`, you will have a reminder about the tasks to do every time you
  open a shell.
- If you want to hide a ToDo file, use the `_filter_regex` configuration in the
  script.
- If you want to order your ToDo file, either change the `_sort` configuration
  in the script or name your files in a way that results in your desired order
  when ran through [`sort(1)`][1] (the sorting command used in the script by
  default).
- Empty `.TODO/*` files are ignored.

[1]: https://pubs.opengroup.org/onlinepubs/9799919799/utilities/sort.html
