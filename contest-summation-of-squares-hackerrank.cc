/*
Little Ashish is doing internship at multiple places. Instead of giving parties to his friends he decided to donate candies to children. He likes solving puzzles and playing games. Hence he plays a small game. Suppose there are N children. The rules of the game are:

The ith child gets i2 candies (1≤i≤N).

The yth child cannot get a candy until and unless all the children before him (1≤i<y) gets candies according to rule number 1.

One of his jealous friends, Pipi, asks him "Given X (the number of candies) how many children will you be able to serve?". Little Ashish fears calculations and cannot solve this problem so he leaves this problem to the worthy programmers of the world. Help little Ashish in finding the solution.

Input Format 
The first line contains T i.e. number of test cases. 
T lines follow, each line containing an integer X.

Output Format 
For each testcase, print the output that little Ashish wants in one line.

Constraints 
1≤T≤10000 
1≤X≤1016

Note: If the ith child doesn't get i2 number of candies then it's not counted as a successful donation

Sample Input

3
1
5
13
Sample Output

1  
2  
2  
Explanation

For X=1. Only the 1st child can get the candy (i.e. 12 candy) and no other child.
For X=5. Both the 1st(12 candies) and the 2nd(22 candies) children can get the candies.
For X=13. Since the 3rd child will get only 8 candies following the rule it won't be counted as a successful donation. Only the 1st and the 2nd children can get 1 and 4 candies respectively.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >>T;
    //n*n*n/3 +n*n/2 +n/6
        
    for(int i=0; i<T; i++)
    {
        unsigned long int x;
        cin >>x;
        unsigned long int csum=1;
        unsigned long int j=1;
        while(csum<=x)
        {
            j++;
            csum = (j*(j+1)*(2*j+1))/6;
        }
        cout <<j-1<<endl;
    }
    return 0;
}
