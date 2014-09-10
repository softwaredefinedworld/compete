/*
 *
 *
Markov takes out his Snakes and Ladders game and stares at the board, and wonders: If he had absolute control on the die, and could get it to generate any number (in the range 1-6) he desired, what would be the least number of rolls of the die in which he’d be able to reach the destination square (Square Number 100) after having started at the base square (Square Number 1)?

Snakes And Ladders Board
------------------------

Rules
-----
Markov has total control over the die and the face which shows up every time he tosses it. You need to help him figure out the minimum number of moves in which he can reach the target square (100) after starting at the base (Square 1).

A die roll which would cause the player to land up at a square greater than 100, goes wasted, and the player remains at his original square. Such as a case when the player is at Square Number 99, rolls the die, and ends up with a 5.

If a person reaches a square which is the base of a ladder, (s)he has to climb up that ladder, and he cannot come down on it. If a person reaches a square which has the mouth of the snake, (s)he has to go down the snake and come out through the tail - there is no way to climb down a ladder or to go up through a snake.

Input Format
------------
The first line contains the number of tests, T. T testcases follow.

For each testcase, there are 3 lines.

The first line contains the number of ladders and snakes, separated by a comma.
The second is a list of comma separated pairs indicating the starting and ending squares of the ladders. The first point is the square from which a player can ascend and the second point is his final position. 
The third is a list of comma separated pairs indicating the starting and ending (mouth and tail) squares of the snakes. the first point is the position of the mouth of the snake and the second one is the tail.
Multiple comma separated pairs of snakes and ladders are separated by a single space.

Constraints
-----------
The board is always of the size 10 x 10
1 <= T <= 10
1 <= Number of Snakes <= 15
1 <= Number of Ladders <= 15
Squares are always numbered 1 to 100 and the order can be seen in the image above.

Output Format
------------
For each of the T test cases, output one integer, each of a new line, which is the least number of moves (or rolls of the die) in which the player can reach the target square (Square Number 100) after starting at the base (Square Number 1). This corresponds to the ideal sequence of faces which show up when the die is rolled.

Sample Input
------------
3
3,7
32,62 42,68 12,98
95,13 97,25 93,37 79,27 75,19 49,47 67,17
5,8
32,62 44,66 22,58 34,60 2,90
85,7 63,31 87,13 75,11 89,33 57,5 71,15 55,25
4,9
8,52 6,80 26,42 2,72
51,19 39,11 37,29 81,3 59,5 79,23 53,7 43,33 77,21
Sample Output

3
3
5
Explanation

For the first test: To traverse the board via the shortest route, the player first rolls the die to get a 5, and ends up at square 6. He then rolls the die to get 6. He ends up at square 12, from where he climbs the ladder to square 98. He then rolls the die to get ‘2’, and ends up at square 100, which is the target square. So, the player required 3 rolls of the die for this shortest and best case scenario. So the answer for the first test is 3.

For the second test: Rolls the die to get 1, reaches square 2. Then, climbs the ladder to square 90. Rolls the die to get 4, reaches square 94. Rolls the die to get 6, reaches square 100, which is the target square. So the answer for the second test is also 3.
Asked:
FlipKart, MSFT
*/


#include <iostream>
#include <map>
#include <sstream>

using namespace std;
const int BOARD_SIZE=101;
const int MAX_DICE=6;

void display(int m[BOARD_SIZE])
{
    cout<<endl;
    for(int i=1; i<BOARD_SIZE; i++)
    {
        cout<<m[i]<<"    ";
        if (i%10 == 0)
            cout<<endl;
    }
    cout<<endl;
}

int minimum(int a, int b)
{
    return a<b?a:b;
}

int solveBoard(int snakes[BOARD_SIZE], int ladders[BOARD_SIZE])
{
    //min[i]=smallest number of dice roles to reach square i from square 1
    int min[BOARD_SIZE];

    //initialize all of them to some infinity
    for(int i=0; i<BOARD_SIZE; i++)
        min[i]= 200;

    min[1]=0;
    for(int i=2; i<BOARD_SIZE; i++)
    {
        // if there is a snake, we ignore it
        if (snakes[i] != -1 )
            continue;
        
        // for every square i, we go back from i-1 ..... i-6 and evaluate
        // if ladders[i] != -1 which means there is a ladder starting at i
        //      min[ladders[i]] = Min(min[i-1], min[i-2], min[i-3], min[i-4], min[i-5], min[i-6])+1
        // else no ladder case
        //      min[i] = Min(min[i-1], min[i-2], min[i-3], min[i-4], min[i-5], min[i-6])+1
        //
        for(int j=i-1; j>=1&&j>=i-6; j--)
        {
            //if there is a ladder, min roles of dice to reach end of ladder(denoted by ladder[i])
            if (ladders[i] != -1)
            {
                min[ladders[i]] = minimum(min[j]+1, min[ladders[i]]);
                //this is critical, mark min[i]= infinity since we can never reach square i since there is 
                //a ladder starting at i
                min[i]=200; 
            }
            else
                min[i] = minimum(min[j]+1,min[i]); //normal case when no ladder
        }
    }
        //display(min);
    return min[BOARD_SIZE-1];
}
int main()
{
    int T;
    cin >>T;

    int countLadders;
    int countSnakes;
    cin.clear();
    cin.ignore();                //ignore /n and eof etc
    for(int i=0; i<T; i++)
    {
        string inp1;
        getline(cin, inp1);

        stringstream ss(inp1);
        string ld, sk;
        getline(ss, ld, ',');
        getline(ss, sk, ' ');
        countLadders = stoi(ld);
        countSnakes= stoi(sk);

        //ladders[i] is a ladder starting from square i to square ladders[i] OR
        //ladders[i]=-1 if there is no ladder at square starting at i
        int ladders[BOARD_SIZE];    
        //snakes[i] is a snake starting from square i to square snakes[i] OR
        //snakes[i]=-1 if there is no snake at square starting at i
        int snakes[BOARD_SIZE];
        for(int j=0;j<BOARD_SIZE;j++)
        {
            snakes[j]=-1;
            ladders[j]=-1;
        }
        getline(cin, inp1);
        stringstream ss1(inp1);
        for(int i=0; i< countLadders; i++)
        {
            string num1,num2;
            getline(ss1, num1, ',');
            getline(ss1, num2, ' ');
            ladders[stoi(num1)]=stoi(num2);
        }
        getline(cin, inp1);
        stringstream ss2(inp1);
        for(int i=0; i< countSnakes; i++)
        {
            string num1,num2;
            getline(ss2, num1, ',');
            getline(ss2, num2, ' ');
            snakes[stoi(num1)]=stoi(num2);
        }

        //solve the board
        int minMoves = solveBoard(snakes,ladders);
        cout <<minMoves<<endl;
    }

}
