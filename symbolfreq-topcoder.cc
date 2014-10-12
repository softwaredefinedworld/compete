/*
 * TCHS SRM 1
 *
 * 500 Pointer
 */
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <cmath>

#include <iostream>

using namespace std;
class SymbolFrequency
{
    public:
        double language(vector<string> frequencies, vector<string> text);
    
};

double SymbolFrequency::language(vector<string> frequencies, vector<string> text)
{
    double minDev = 99999999;
    int passageCount =0;
    int actualCount[26];
    for(int j=0; j<26; j++)
        actualCount[j]=0;

    for(int j=0;j<text.size(); j++)
    {
        string line = text[j];
        for(int k=0; k<line.size(); k++)
        {
            if (line[k]>='a' &&line[k]<='z' )
            {
                actualCount[line[k]-'a']++;
                passageCount ++;
            }
        }
    }
    for (int i=0; i<frequencies.size(); i++)
    {
        double dev=0.0;
        string freq = frequencies[i];
        int freqTable[26];
        for(int j=0;j<26; j++)
            freqTable[j]=0;
        //cout <<freq<<endl;
        for(int j=0; j<=freq.size()-3; j+=3)
        {
            int c=freq[j]-'a';
            int count = stoi(freq.substr(j+1, 2), NULL);
            freqTable[c] = count;
            //cout <<count<<endl;
        }


        for(int j=0; j<26; j++)
        {
            double expectedCount = (freqTable[j]*passageCount)/100.0;
            double diff = expectedCount -actualCount[j];
            dev+=(diff*diff);
        }
        if (dev<minDev )
            minDev = dev;
    }
    
    return minDev;
}
void TEST(const char *freq[], size_t freqTableSize, const char *text[], size_t textTableSize,  double expectedResult)
{
    vector<string> fre(freq, freq+ freqTableSize);
    vector<string> tex(text, text+textTableSize);

    SymbolFrequency f;
    double result = f.language(fre, tex);
    cout <<result <<endl;
    assert(result == expectedResult);
}
int main()
{
    TEST((const char *[]){"a30b30c40","a20b40c40"}, 2,  (const char*[]){"aa","bbbb", "cccc"}, 3, 0);
    TEST((const char *[]){"a30b30c40","a20b40c40"}, 2,  (const char*[]){"aaa","bbbb", "ccc"}, 3, 2);
    TEST((const char *[]){"a30b30c40","a20b40c40"}, 2,  (const char*[]){"aaa","bbbb", "ccc"}, 3, 2);
    TEST((const char *[]){"a09b01c03d05e20g01h01i08l06n08o06r07s09t08u07x01" , "a14b02c05d06e15g01h01i07l05n07o10r08s09t05u04x01"}, 2,
             (const char *[]){"this text is in english" ,"the letter counts should be close to" ,"that in the table"}, 3, 130.6578);

    TEST((const char *[]){"a09b01c03d05e20g01h01i08l06n08o06r07s09t08u07x01" ,"a14b02c05d06e15g01h01i07l05n07o10r08s09t05u04x01"}, 2,
             (const char *[]) {"en esta es una oracion en castellano" ,"las ocurrencias de cada letra" ,"deberian ser cercanas a las dadas en la tabla"} , 3, 114.9472);

    TEST((const char *[]){"z99y01", "z99y01", "z99y01", "z99y01", "z99y01", "z99y01", "z99y01", "z99y01", "z99y01", "z99y01"}, 10,
             (const char *[]) {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
               "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                   "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                     "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                       "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"}, 10, 495050);


}
