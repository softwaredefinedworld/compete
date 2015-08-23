/* 
 
TCHS SRM 2 DIV 1 Level 2
ApocalypseSomeday 

Problem Statement
        The number 666 is considered to be the occult "number of the beast" and is a well used number in all major apocalypse themed blockbuster movies. However the number 666 can't always be used in the script so numbers such as 1666 are used instead. Let us call the numbers containing at least three contiguous sixes beastly numbers. The first few beastly numbers are 666, 1666, 2666, 3666, 4666, 5666...



Given a 1-based index n, your program should return the n-th beastly number.
 
Definition
        
Class:  ApocalypseSomeday
Method: getNth
Parameters: int
Returns:    int
Method signature:   int getNth(int n)
(be sure your method is public)
    
 
Constraints
-   n will be between 1 and 10000, inclusive
 
Examples
0)  
        
2
Returns: 1666
1)  
        
3
Returns: 2666
2)  
        
6
Returns: 5666
3)  
        
187
Returns: 66666
4)  
        
500
Returns: 166699

*/
#include <iostream>
#include <string>


using namespace std;

class ApocalypseSomeday
{
    public:
        int getNth(int n)
        {
            int start=666;
            int count =1;
            while(count <n)
            {
                do
                {
                    start++;
                }
                while(to_string(start).find("666") == string::npos);
                count++;    
            }

            return start;
        }
};

int main()
{
    ApocalypseSomeday a;
    cout <<a.getNth(2)<<endl;
    cout <<a.getNth(3)<<endl;
    cout <<a.getNth(6)<<endl;
    cout <<a.getNth(187)<<endl;
    cout <<a.getNth(500)<<endl;
}
