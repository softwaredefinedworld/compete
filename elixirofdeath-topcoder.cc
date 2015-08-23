/*
TCHS SRM 2 DIV 1
Statement
        A Fountain of Life is a special fountain that produces the elixir of life at a constant speed of elixir liters per second. A dark mage managed to cast a Curse of Death on the Fountain so in addition to the elixir it now produces a deadly poison at a constant speed of poison liters per second. Both the poison and elixir are collected in an infinitely large pool around the Fountain and form a mixture. The mixture will become deadly once the percentage of poison in the mixture is at least 50%. Your task is to calculate the time at which the mixture will become deadly. At the beginning (0-th second) the pool contains pool liters of 100% elixir.



Your program must return a double, the time in seconds at which the mixture becomes deadly. If the mixture never becomes deadly, return -1.0.
 
Definition
        
Class:  FountainOfLife
Method: elixirOfDeath
Parameters: int, int, int
Returns:    double
Method signature:   double elixirOfDeath(int elixir, int poison, int pool)
(be sure your method is public)
    
 
Notes
-   The returned value must be accurate to within a relative or absolute value of 1E-9.
 
Constraints
-   elixir will be between 1 and 10000, inclusive.
-   poison will be between 1 and 10000, inclusive.
-   pool will be between 1 and 10000, inclusive.
 
Examples
0)  
        
1
2
2
Returns: 2.0
At t = 0s there are 2 liters of 100% elixir.

At t = 1s there are 3 liters of elixir and 2 liters of poison for a total volume of 5 liters. 2 liters of poison is 40% of 5 liters so the mixture is still not deadly.

At t = 2s there are 4 liters of elixir and 4 liters of poison for a total volume of 8 liters. 4 liters of poison is exactly 50% of the mixture so it is now deadly.

1)  
        
200
100
1
Returns: -1.0
With 200 liters of elixir per second and only 100 liters of poison per second, the mixture never becomes deadly.
2)  
        
9999
10000
10000
Returns: 10000.0
It might take a long time for the mixture to become deadly.
3)  
        
1
10000
1
Returns: 1.0001000100010001E-4
On the other hand, it might take a short time for the mixture to become deadly.
4)  
        
40
43
41
Returns: 13.666666666666666
*/
#include <iostream>

using namespace std;
class FountainOfLife
{
    public:
        //method 1
        long double elixirOfDeath(int elixir, int poison, int pool)
        {
            long double t=0.0;

#if 0
            use scratch pad to solve the equation
                2= (totalElixir+totalPoison )/totalPoison;
            = (pool+t*elixir + t*poison)/ (t*poison);
            => 2*t*poison = pool+t*elixir + t*poison
                => t = pool/(2*poison-elixir-poison)
#endif
            long double den = 2.0*poison-elixir - poison;
            if (den<0)
                return -1.0;
            t = pool/den;

            return t;
        } 

        //method 2
        double elixirOfDeath1(int elixir, int poison, int pool)
        {
            long double t=0.0;
            int totalElixir = pool;
            int totalPoison = 0;
            double percentagePoison = (1.0*totalPoison/(totalElixir+totalPoison)) *100.0;
            while(percentagePoison<50.0)
            {
                t++;
                totalElixir +=elixir;
                totalPoison +=poison;
                percentagePoison = (1.0*totalPoison/(totalElixir+totalPoison)) *100.0;
            }   

            return t;
        }
};

int main()
{
    FountainOfLife f;
    cout.precision(9);
    cout <<f.elixirOfDeath(1,2,2)<<endl;
    cout <<f.elixirOfDeath(9999,10000,10000)<<endl;
    cout <<f.elixirOfDeath(1,10000,1)<<endl;
    cout <<f.elixirOfDeath(40,43,41)<<endl;
    cout <<f.elixirOfDeath(200,100,1)<<endl;
}
