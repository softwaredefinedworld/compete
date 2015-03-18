/*
 * TCHS SRM1 
 * 1000 Pointer
 *
Problem Statement
        
People enjoy mazes, but they also get them dirty. Arrows, graffiti, and chewing gum are just a few of the souvenirs people leave on the walls. You, the maze keeper, are assigned to whiten the maze walls. Each face of the wall requires one liter of paint, but you are only required to paint visible faces. You are given a map of the maze, and you must determine the amount of paint needed for the job.

The maze is described by a String[] maze, where each character can be either '#' (a wall) or '.' (an empty space). All '.' characters on the perimeter of the map are considered entrances to the maze. Upon entering the maze, one can only move horizontally and vertically through empty spaces, and areas that are not reachable by these movements are not considered visible. Each '#' represents a square block with four wall faces (each side of the square is a face). A face is visible if it is not directly adjacent to another wall (and is in a reachable area of the maze). For example, two adjacent blocks can have at most six visible faces since two of their faces are directly adjacent to each other. All exterior faces on the perimeter are considered visible.

For example, the following picture represents a trivial maze with just one (wide) entrance and only four empty reachable spaces: 




To whiten this maze you must paint the faces highlighted in yellow above: 16 for its perimeter, plus 8 interior faces. Note that there are faces that are not visible and thus need not be painted.

 
Definition
        
Class:  TroytownKeeper
Method: limeLiters
Parameters: String[]
Returns:    int
Method signature:   int limeLiters(String[] maze)
(be sure your method is public)
    
 
Constraints
-   maze will contain between 1 and 50 elements, inclusive.
-   Each element of maze will contain between 1 and 50 characters, inclusive.
-   All elements of maze will have the same number of characters.
-   All characters in maze will be either '.' or '#'.
 
Examples
0)  
        
{"##..#"
,"#.#.#"
,"#.#.#"
,"#####"}
Returns: 24
Example from the problem statement.
1)  
        
{"##",
 "##"}
Returns: 8
Only the perimeter of the maze (which has no interior!) has to be painted.
2)  
        
{"######"
,"#....."
,"#.####"
,"#.#..#"
,"#.##.#"
,"#....#"
,"######"}
Returns: 56
3)  
        
{"######"
,"#....."
,"#..#.."
,"#....."
,"######"}
Returns: 36
4)  
        
{"#.#.#.#"
,".#.#.#."
,"#.#.#.#"
,".#.#.#."}
Returns: 36
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class TroytownKeeper
{
    private:
        int rows;
        int columns;
        bool new_maze[52][52];
        bool visited[52][52];

    void dfs(int i, int j)
    {
        if (i<0|| j<0||i>=rows || j>=columns || visited[i][j]|| new_maze[i][j])
            return ;

        visited[i][j] = true;
        dfs(i+1,j);
        dfs(i-1,j);
        dfs(i,j-1);
        dfs(i,j+1);
    }

public:
    int limeLiters(vector<string> maze)
    {
        //initialize visited
        for(int i=0; i<52; i++)
            for(int j=0; j<52; j++)
            {
                visited[i][j] = false;
                new_maze[i][j]= false;
            }

        // create a border around the maze so that the whole maze
        // becomes reachable from 0,0
        rows = maze.size()+2;
        columns = maze[0].size()+2;
        for(int i=0; i<maze.size(); i++)
        {
            for(int j=0; j<maze[0].size(); j++)
            {
                new_maze[i+1][j+1] = maze[i][j] == '#';
            }
        }

        //mark all reachable floor spaces
        dfs(0,0);
        
        int paint = 0;
        // if two neighboring cells have different values, there is a wall to paint
        for(int i=0; i<rows; i++)
            for(int j=0; j<columns-1; j++)
                if (visited[i][j] ^visited[i][j+1])
                    paint ++;

        for(int i=0; i<rows-1; i++)
            for(int j=0; j<columns; j++)
                if (visited[i][j] ^visited[i+1][j])
                    paint ++;
        return paint;
    }
};
int main()
{
    TroytownKeeper troy;

    vector<string> maze1 = 
    {"##..#"
    ,"#.#.#"
    ,"#.#.#"
    ,"#####"
    };
    assert(troy.limeLiters(maze1)  == 24);

    vector<string> maze2= 
    {"##",
     "##"};
    assert(troy.limeLiters(maze2) == 8);

    vector<string> maze3 = 
        {"######"
        ,"#....."
        ,"#.####"
        ,"#.#..#"
        ,"#.##.#"
        ,"#....#"
        ,"######"};
    assert(troy.limeLiters(maze3) == 56);

    vector<string> maze4 = 
    {"######"
    ,"#....."
    ,"#..#.."
    ,"#....."
    ,"######"};

    assert(troy.limeLiters(maze4) == 36);
    
    vector<string> maze5 =
        {"#.#.#.#"
        ,".#.#.#."
        ,"#.#.#.#"
        ,".#.#.#."};

    assert(troy.limeLiters(maze5) == 36);
}
