# What did I do?

I was looking into how to swap values around with no temporary variable
I did a simple C program with 4 ways of swapping:

- Temporary variable swapping
- XOR variable swapping
- Arithmetics variable swapping
- Pointer shanenigans swapping

After that I wanted to compare how one method stacked up to another
so I timed all methods individually and to avoid the pain of running
them individually multiple times and calculating the median I wrote
a simple bash script to do that for me.

Unless something was off with my code or testing method I found:

- XOR and Arithmetics swapping are the slower of the four
- Temporary and Pointer are the faster of the two, and pretty equal in speed
- Pointer gains a point on Temporary for using less memory

## What did I learn

- Bash scripting basics
- Multiple methods of swapping values around
