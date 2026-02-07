# ProjectEuler0018
My work on

problem #18 of projecteuler.net:

Maximum Path Sum I

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is $23$.

**3**<br>
**7** 4<br>
2 **4** 6<br>
8 5 **9** 3<br>

That is, $3 + 7 + 4 + 9 = 23$.

Find the maximum total from top to bottom of the triangle below:

75<br>
95 64<br>
17 47 82<br>
18 35 87 10<br>
20 04 82 47 65<br>
19 01 23 75 03 34<br>
88 02 77 73 07 63 67<br>
99 65 04 28 06 16 70 92<br>
41 41 26 56 83 40 80 70 33<br>
41 48 72 33 47 32 37 16 94 29<br>
53 71 44 65 25 43 91 52 97 51 14<br>
70 11 33 28 77 73 17 78 39 68 17 57<br>
91 71 52 38 17 14 91 43 58 50 27 29 48<br>
63 66 04 68 89 53 67 30 73 16 69 87 40 31<br>
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23<br>

**NOTE:** As there are only $16384$ routes, it is possible to solve this problem by trying every route. However, [Problem 67](https://github.com/yuretzius/ProjectEuler0067), is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)

Completed on Thu, 25 Feb 2021, 06:37

#######################################################################################
Please note: Project Euler's policy allows publication of solutions for the first 100 problems,
that's why I am sharing my work here for reference and educational purposes.
#######################################################################################

This is the same solution as in [Problem 67](https://github.com/yuretzius/ProjectEuler0067), only with different input. I've created a data file for this triangle too: [0018_triangle.txt](https://github.com/yuretzius/ProjectEuler0018/blob/main/0018_triangle.txt).
However, in the python code I just included the data directly in the code.

As noted above, trying the paths from top to bottom is extremely inefficient here. But if we go *from the bottom to the top* in the way of dynamic programming,
the task becomes very simple. And since it does not matter in what order we add the numbers, the answer is the same. Let's see how it is done using the example triangle:

3<br>
7 4<br>
2 4 6<br>  
8 5 9 3<br>

Assume we are already at the line before the last. If we are at $2$, we have to choose between $8$ and $5$, and the maximum choice is $8$, so we can record $8 + 2 = 10$.
At $4$ we choose between $5$ and $9$, and the larger choice is $9$, so we record $9 + 4 = 13$. Finally, at $6$ we choose between $9$ and $3$, the larger choice is $9$, so
we record $9 + 6 = 15$. We write the answers as a new, smaller triangle:

03<br>
07 04<br>
10 13 15<br>  

Repeating the same logic starting at the next row, we get the next iteration:

03<br>
20 19<br>

Finally, from the top we have to choose only one of two numbers, the maximum is $20$, so the answer is $23$. The triangle "collapsed" into the maximal path automatically.

An implementation of this algorithm takes just a couple of lines with two enclosed cycles.
