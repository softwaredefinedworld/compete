/*
 * You are given a square n×n map. Each cell of the map has a value in it denoting the depth of the appropriate area. We will call a cell of the map a cavity if and only if this cell is not on the border of the map and each cell adjacent to it has strictly smaller depth. Two cells are adjacent if they have a common side.

You need to find all the cavities on the map and depict them with character X.

Input Format

The first line contains an integer n (1≤n≤100), denoting the size of the map. Each of the following n lines contains n positive digits without spaces. A digit (1-9) denotes the depth of the appropriate area.

Output Format

Output n lines, denoting the resulting map. Each cavity should be replaced with character X.

Sample Input

4
1112
1912
1892
1234
Sample Output

1112
1X12
18X2
1234
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >>n;

    vector<string> a(n);    //initialize the initial size to n strings

    for(int i=0;i<n; i++)
    {
        cin >>a[i];
    }

    //copy the original map since placing X will destroy it
    vector<string> b=a;
    
    const int dx[]={0, 0,  1, -1};
    const int dy[]={1, -1, 0,  0};
    for(int i=1; i<(n-1); i++)
    {
        for(int j=1; j<(n-1); j++)
        {
            bool cavity = true;
            for(int dir = 0; dir <4; dir++)
            {
                int x=i+dx[dir];
                int y=j+dy[dir];
                if (a[x][y]>=a[i][j])
                {
                    cavity = false;
                    break;
                }
            }
            if (cavity)
                b[i][j] = 'X';
        }
    }
    
    for(int i=0; i<n; i++)
        cout<<b[i]<<endl;

}
