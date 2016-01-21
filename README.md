#Web-Analyzer-Project-2
In Project 1, we computed some statistics on the resources that are served. In this Project, we incorporate client-requests, and compute related statistics.

For this project, we have inputs from 3 sources. (1) Web-resources that are served are input from a file, as in Project 1. (2) A command-line argument is provided, which we call a bias (discussed below).(3) Client-requests are provided as user-input, to be read in by the program as it runs. 

Input file: The input file is named ece150-input.txt. Its format is the same as Project 1. The input file comprises rows. A line of data comprisese three fields. The fields in a line are separated by one or more spaces. A string URI (Universal Resource Identifier), a positive integer size, and a non-negative integer priority.

Command-line argument: Your programs takes a command-line argument called a bias. It is a non-negaive integer. It is used to model the variability in the transmission delay the server incurs. The bias represents the number of bits in a random integer that your program generates. 

User input: When your program runs, it takes user-input, which is a sequence of strings. This part of the input are the client-requests. Each string in this input is one of two kinds. (1) a URI, or, (2) the string 'exit'. An input of 'exit' means that your program shoudl imediately stop, and output statistics related to the prior inputs.

An example of user-input is the following sequence of lines:

1. ftp://ftpserver.abc.edu:8080 
2. http://example.com/object1 
3. http://example.another.com/repo/objects/1
4. http://example.another.com/repo/objects/1 
5. http://example.another.com/repo/objects/1 
6. http://example.another.com/repo/objects/1 
7. exit 

In this example, we have 6 client-requests. The last 4 are for the same URI.

The following statistics are computed:

1. Average: 
Given n values x1, ... , xn, the average of those values is: (1/n) times the sum from i = 1 to n of xi.

2. Median:
Given n values x1, ..., xn, the median of those values is the middlemost value when the values are in sorted order an n is odd. If n is even, it is the average of the middle two values when the values are in sorted order.

3. Standard Deviation:
Given n values x1, ... , xn, let their average be x bar. then the standard devaition is the square root of [(1/n) times the sum from i = 1 to n of (xi - x bar)].

4. Average Absolute Deviation:
Given n values x1, ... , xn, let their median be m. Then, the average absolute deviation is: (1/n) times the sum from i = 1 to n of the absolute value of (xi - m).

These statistics are computed for the following things:

1. The size of the URI served: average, median, standard deviation, and average absolute deviation.

2. The prioity of URI served: average, median, standard deviation and average absolute deviation.

3. The transmission delay in seconds: average, median, standard deviation and average absolute deviation. We assume, as in Project 1, that the server can transmit at 10 Megabits per second. Suppose we have n client request for URIs u1, ..., un, where the size of ui is si. Then, the command-line input, bias, causes the size of ui to be treated as si + ri, for some random r which is defined for all (-2^bias, 2^bias)

Bias: We use the bias parameter to inject a random component into the transmission delay. If the bias is b, then we incorporate an integer value represented by a b-bit value, as the random component. That is, rather than assuming that the size of a URI served is s, we first generate a random number r between -2^b and 2^b, excluding those end-pooints -2^b and 2^b. We assume that the size of the URI is s+r when computing the transmission delay.

The code is modularized as follows:

1. ece150-proj2-main.cpp: this file contains main().

2. ece150-proj2-stats.cpp: this file contains the average, standard deviation, median, and absolute standard deviation functions.

3. ece150-proj2-helper.cpp: this file contains the random number generator.

