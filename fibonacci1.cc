/*
 * You are given an integer N, can you check if the number is an element of fibonacci series? The first few elements of fibonacci series are 0,1,1,2,3,5,8,13…. A fibonacci series is one where every element is a sum of the previous two ele  ments in the series. The first two elements are 0 and 1.
 *
 * Formally:
 *
 * fib0 = 0
 * fib1 = 1
 * fibn = fibn-1 + fibn-2 ∀ n > 1
 *
 * Input Format
 * First line contains T, number of test cases. 
 * T lines follows. Each line will contain an integer N.
 *
 * Output Format
 * Output “IsFibo” (without quotes) if N is a fibonacci number and “IsNotFibo” (without quotes) if it is not a fibonacci number, in a new line corresponding to each test case.
 *
 * Constraints
 * 1 <= T <= 105
 * 1 <= N <= 1010
 *
 * Sample Input
 *
 * 3
 * 5
 * 7
 * 8
 * Sample Output
 *
 * IsFibo
 * IsNotFibo
 * IsFibo
 * Explanation
 * 5 is a Fibonacci number given by fib5 = 3 + 2
 * 7 is not a Fibonacci number
 * 8 is a Fibonacci number given by fib6 = 5 + 3
 */

#include <iostream>
#include <map>
using namespace std;

// If x is a fibonacci number fibo[x]=true
map<unsigned long,bool >fibo;
bool isFib(unsigned long n)
{
    unsigned long n1=0;
    unsigned long n2=1;

    // test if n is a fibonacci number
    if (fibo[n])
        return true; 
    
    for(unsigned long i=0;i<=10000000000;i++)
    {
        // generate the next fibonacci number and store it
        unsigned long n3= n1+n2;
        fibo[n3]=true;

        // if the generated fibonacci is past the given number 
        // we are done and the given number is not fibonacci
        if (n3>n)
            return false;

        // if the generated fibonacci is same as given number
        // we are done and the given number is fibonacci
        if (n == n3)
            return true;
        n1=n2;
        n2=n3;
    }

    return false;
}

int main()
{
    // Init the first two fibonacci numbers
    fibo[0]=true;
    fibo[1]=true;
    int T;
    cin >>T;
    unsigned long *tests = new unsigned long[T];
    for(int i=0;i<T;i++)
    {
        unsigned long N;
        cin >>N;
        tests[i]=N;
    }
    for(int i=0;i<T;i++)
    {
        if (isFib(tests[i]))
            cout <<"IsFibo"<<endl;
        else
            cout<<"IsNotFibo"<<endl;
    }
}
