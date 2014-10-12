/* 
 * SRM 144 DIV 1
 * 300 Point
 */
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;
class BinaryCode
{
    public:
        vector<string> decode(string message);
};
vector<string> BinaryCode::decode(string message)
{
    vector<string> out;

    for(int i=0;i<2; i++)
    {
        string in(message.size(),0);
        in[0]=i+'0';
        in[1]=message[0] - in[0]+'0';
        if (in[1]<'0' || in[1]>'1')
        {
            in="NONE";
            out.push_back(in);
            continue;
        }
        for(int i=1;i<message.size(); i++)
        {
            in[i+1] = message[i] -in[i]- (in[i-1]-'0') + '0';
            if (in[i+1]<'0' || in[i+1]>'1')
            {
                in="NONE";
                break;

            }
        }

        out.push_back(in);
    }

    return out;
}

#if 1
int main()
{    
    BinaryCode c;
    assert(c.decode("123210122") == (vector<string>{ "011100011","NONE"}) );
    assert(c.decode("11") == (vector<string>{ "01","10"}) );
    assert(c.decode("123210120") == (vector<string>{ "NONE","NONE"}) );
    assert(c.decode("3") == (vector<string>{ "NONE","NONE"}) );
    assert(c.decode("12221112222221112221111111112221111") == (vector<string>{ "01101001101101001101001001001101001",
                 "10110010110110010110010010010110010" } ) );
}

#endif
