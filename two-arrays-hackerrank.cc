/*
 *
 * You are given two integer arrays, A and B, each containing N integers. The size of the array is <= 1000. You are free to permute the order of the elements in the arrays.
 *
 * Now for the real question - is there an arrangement of the arrays such that Ai+Bi>=K for all i where Ai denotes the ith element in the array A.
 *
 *
 * Input Format
 * The first line contains an integer T denoting the number of test-cases. T test cases follow. Each test case is given in the following format.
 *
 * The first line contains two integers, N and K. The second line contains N integers separated by a single space, denoting A array. The third line describes B array in a same format.
 *
 * Output Format
 * For each test case, if there is such arrangement exists output “YES”, otherwise “NO” (quotes for clarity).
 *
 *
 * Constraints
 * 1 <= T <= 10
 * 1 <= N <= 1000
 * 1 <= K <= 10^9
 * 0 <= Ai, Bi <= 10^9
 *
 *
 * Sample Input
 *
 * 2
 * 3 10
 * 2 1 3
 * 7 8 9
 * 4 5
 * 1 2 2 1
 * 3 3 3 4
 *
 * Sample Output
 *
 * YES
 * NO
 * Explanation
 *
 * The first input has 3 elements in Array A and Array B, we see that the one of the arrangements, 3 2 1 and 7 8 9 has each pair of elements (3+7, 2 + 8 and 9 + 1) summing upto 10 and hence the answer is “YES”.
 *
 * The second input has B array with three 3s. So, we need at least three numbers in A to be greater than 1. As its not the case, the answer is “NO”.
 *
 * Approach :
 * Problem: Two Arrays 
 * Difficulty: Easy 
 * Required Knowledge: Greedy, Sorting 
 * Time Complexity: O(n log n)
 * The problem expects us to print "YES" there exists a permutation of A and B such that
 * A[i] + B[i] >= k ∀ i
 * and print "N0" otherwise.
 * We can arrive at this by sorting one of the arrays in ascending order and the other in descending order and then for every i, check if the condition (A[i] + B[i] >= k ) holds true or not for each of the array indices i. Think
 * It can be easily seen that, if the condition fails on the sorted arrays, then there exists no permutation of A and B such that the condition holds good.
 * It will mean that there is an index i such that: 
 * A_a[i] + B_d[i] < K (Where A_a is A sorted in ascending order, B_d is B sorted in descending order). 
 * Assume, that a new permutation of B is created which is nearly the same as B_d except that the values at indices i and j are swapped.
 * Case 1: i < j and the element at the i-th index in B in now B_d[j]
 * Now, A_a[i] + B_d[j] < K (since B_d[i] > B_d[j] as B is sorted in descending order, and we already know that A_a[i] + B_d[i] < K)
 * Case 2: i > j and the element at the i-th index in B in now B_d[j]
 * Now, A_a[j] + B_d[i] < K (since A_d[i] > A_d[j] as A is sorted in ascending order, and we already know that A_a[i] + B_d[i] < K)
 * So, in either case, we observe, that if the condition doesn't hold true for these sorted arrays for even one position, it won't hold true in any of the permutations either - there will always be an index j where the condition is violated in any permutation as well.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >>T;
    for(int t=0; t<T; t++)
    {
        int N;
        long long K;
        cin >>N>>K;;
        vector<long long> A;
        vector<long long> B;
        A.reserve(N);
        B.reserve(N);
        for(int i=0;i<N;i++)
        {
            long long n;
            cin>>n;
            A.push_back(n);
        }
        for(int i=0;i<N;i++)
        {
            long long n;
            cin>>n;
            B.push_back(n);
        }

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        bool yes=true;
        for(int i=0;i<N;i++)
        {
            long long sum = A[i]+B[N-i-1];
            if (sum <K)
            {
                yes=false;
            }
        }
        if (yes)
            cout <<"YES"<<endl;
        else
            cout <<"NO"<<endl;
    }
}
