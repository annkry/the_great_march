# the_great_march
The main part of New Manhattan is built on a rectangular plan with a height of m and width of n. Squares are located at lattice points, where point S = (0, 0) represents the square located furthest northwest, while point F = (m, n) represents the square located furthest southeast. Some squares are connected by tunnels. All tunnels lead southward, eastward, or southeastward. No pair of tunnels intersect, and passage from one tunnel to another is possible only on a square.

The program will count how many different paths there are for a procession to go from point S to point F.  

`input specification`  
The first line of input contains three integers m, n ∈ [1, 109] and t ∈ [1, 500 000], which represent the height and width of the city and the number of tunnels, respectively. In seven marked test cases, it additionally holds that m * n <= 106.
Each of the following t lines contains a description of a single tunnel, consisting of four integers separated by single spaces: a1, b1, a2, and b2, such that a1 <= a2 and b1 <= b2. These numbers indicate that there is a tunnel from the square with coordinates (a1, b1) to the square with coordinates (a2, b2). There are no tunnels leading from a square to itself. There is at most one tunnel between a pair of squares.  

`output specification`  
In the first and only line of the output, your program should print the number k mod 999 979, where k is the number of different paths leading from square S to square F.  

To compile: `g++ -std=gnu++17 -static -DSPRAWDZACZKA main.cpp`  
To run: `./a.out`  
