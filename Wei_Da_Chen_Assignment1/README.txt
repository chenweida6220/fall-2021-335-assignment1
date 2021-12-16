i.) All parts of Assignment 1 have been completed and compiles successfully.
ii.) Majority of the bugs I encountered were runtime errors from not accessing
the right elements and objects.
iii.)
To compile on terminal type
  make clean
  make all

To delete executables and object file type
  make clean

To run:

./test_points2d

^^In that case you will provide input from standard input.

To run with a given file that is redirected to standard input:

./test_points2d < test_input_file.txt
iv.)
Input: 3 7 4 3 5 19 71
4 100 101 2 3 40 50 11 33
3 2.1 20.3 11.11 12.45 13.1 14.2
2 1.1 100.0 20.1 30.2

Output:
0 0
(7, 10)
Enter a sequence of points (integer)

Output1:
(7, 4) (3, 5) (19, 71)
Enter a sequence of points (integer)

Output2:
(100, 101) (2, 3) (40, 50) (11, 33)
After copy constructor1 c{a}:
(7, 4) (3, 5) (19, 71)
(7, 4) (3, 5) (19, 71)
After assignment a = b
(100, 101) (2, 3) (40, 50) (11, 33)
After e = move(c)
(7, 4) (3, 5) (19, 71)
()
After a = move(e)
(7, 4) (3, 5) (19, 71)
(100, 101) (2, 3) (40, 50) (11, 33)
Enter a sequence of points (double)

(2.1, 20.3) (11.11, 12.45) (13.1, 14.2)
Enter a sequence of points (double)

(1.1, 100) (20.1, 30.2)

Result of a + b
(3.2, 120.3) (31.21, 42.65) (13.1, 14.2)

Result of d = a + b
(3.2, 120.3) (31.21, 42.65) (13.1, 14.2)
Second element in a:
11.11, 12.45

<-------------------------------------------------------------------->

You will use this exact Makefile for your Homework 1.
Failure to do so will result in deduction of points.

To compile on terminal type
  make clean
  make all

To delete executables and object file type
  make clean

To run:

./test_points2d

^^In that case you will provide input from standard input.

To run with a given file that is redirected to standard input:

./test_points2d < test_input_file.txt
