#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s)
{
    int l=0;
    int r=s.size()-1;
    while(l<r)
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }

    return true;
}
int palindromeIndex(string s)
{
    int l=0;
    int r=s.size()-1;

    // find if the string is a palindrome
    while(l<r)
    {
        if (s[l] != s[r])
            break;
        l++;
        r--;
    }
    // string is palindrome so return -1
    if (l>=r)
       return -1; 
    // first mismatch occurs at l and r, ignore the lth character and check if string is palindrome
    if (isPalindrome(s.substr(0,l)+s.substr(l+1)))
        return l;

    // first mismatch occurs at l and r, ignore the rth character and check if string is palindrome
    if (isPalindrome(s.substr(0,r)+s.substr(r+1)))
        return r;
    
    return -1; 
}

int main()
{
    int T;
    cin >>T;
    for (int i=0; i<T; i++)
    {
        string str;
        cin >>str;
        cout << palindromeIndex(str)<<endl;
    }

}
