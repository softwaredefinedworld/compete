/*
 *
 * Bill Gates is on one of his philanthropic journeys to a village in Utopia. He has N packets of candies and would like to distribute one packet to each of the K children in the village (each packet may contain different number of candies). To avoid a fight between the children, he would like to pick K out of N packets such that the unfairness is minimized.
 *
 * Suppose the K packets have (x1, x2, x3,….xk) candies in them, where xi denotes the number of candies in the ith packet, then we define unfairness as
 *
 * max(x1,x2,…xk) - min(x1,x2,…xk)
 *
 * where max denotes the highest value amongst the elements and min denotes the least value amongst the elements. Can you figure out the minimum unfairness and print it?
 *
 * Input Format
 * The first line contains an integer N.
 * The second line contains an integer K. N lines follow each integer containing the candy in the ith packet.
 *
 * Output Format
 * A single integer which will be the minimum unfairness.
 *
 * Constraints
 * 1<=N<=105
 * 1<=K<=N
 * 0<= number of candies in any packet <=109
 *
 * Sample Input #00
 *
 * 7
 * 3
 * 10
 * 100
 * 300
 * 200
 * 1000
 * 20
 * 30
 * Sample Output #00
 *
 * 20
 * Explanation #00
 * Here K = 3. We can choose packets that contain 10,20,30 candies. The unfairness is
 *
 * max(10,20,30) - min(10,20,30) = 30 - 10 = 20
 * Sample Input #01
 *
 * 10
 * 4
 * 1
 * 2
 * 3
 * 4
 * 10
 * 20
 * 30
 * 40
 * 100
 * 200
 * Sample Output #01
 *
 * 3
 * Explanation #01
 * Here K = 4. We can choose the packets that contain 1,2,3,4 candies. The unfairness is
 *
 * max(1,2,3,4) - min(1,2,3,4) = 4 - 1 = 3
 *
 * Approach :
 * In this problem, we are given a list of N numbers out of which K numbers are to be chosen such that the anger coefficient is minimized.
 * Where anger co-efficient, D = max of chosen K numbers - min of chosen K numbers.
 * First, we claim that k such numbers can only be obtained if we sort the list and chose k continues numbers. This can easily be proved. Suppose we choose numbers X1, X2, X3,....Xr, Xr+1,....,XK (all are in increasing order but not continuous in the sorted list) i.e. there exists a number p which lies between Xr and Xr+1. So, if we include this number and exclude X1, the new value of D will become \|XK-X2\| whereas the old value was \|XK-X1\|. As we know X1<=X2<=XK, the value of D decreases or remains same. Hence, if the chosen K points are not consecutive in the sorted list then we can apply these insertions one or more times to reduce the value of K.
 * So, the problem reduces to chosing K consecutive numbers in a sorted list for which the value of D is minimum. Which can be easily done by sorting the given number in O(NlogN) and calculating D for each group of K consecutive number in O(N-K) time.
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() 
{
    /* The code required to enter n,k, candies is provided*/

    long long N, K;
    cin >> N >> K;
    long long  candies[N];
    for (int i=0; i<N; i++)
        cin >> candies[i];

    vector<long long >lVec(candies, candies +N);
    sort(lVec.begin(), lVec.end());
    long long minUnfairness=-1;
    for(long long i=0; i<N-K;i++)
    {
        long long unfairness = lVec[i+K-1]- lVec[i];
        if (minUnfairness == -1)
            minUnfairness = unfairness;
        else if (unfairness < minUnfairness)
            minUnfairness = unfairness;
    }


    cout << minUnfairness << "\n";
    return 0;
}
