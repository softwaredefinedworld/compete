#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>&arr ,int l, int r)
{
    int i=l;
    int j=l-1;
    int x=arr[r];

    while(i<r)
    {
        if (arr[i]<=x)
        {
            j++;
            swap(arr[i], arr[j]);
        }
        i++;
    } 
    swap(arr[r], arr[j+1]);
    return j+1;  
}

int findMedian(vector<int>& arr)
{
    int l =0;
    int r=arr.size()-1;
    int k=arr.size()/2;
    while(l<=r)
    {
        int j = partition(arr, l,r);
        if (j == (k+l))
        {
            return j;
        }
        else if (j<(k+l))
        {
            k=k-(j-l)-1;
            l=j+1;
        }
        else
        {
            r=j-1;
        }
    }

    return -1;
}


int main()
{
    int n;
    cin >>n;
    vector<int> arr;
    int t;
    for(int i=0;i<n; i++)
    {
        cin >>t;
        arr.push_back(t);
    }
    
    int i= findMedian(arr);

    cout <<arr[i]<<endl;
    //sort(arr.begin(), arr.end());
    //cout <<arr[arr.size()/2]<<endl;
    //cout <<arr[arr.size()/2+1]<<endl;
    //cout <<arr[arr.size()/2-1]<<endl;
}
