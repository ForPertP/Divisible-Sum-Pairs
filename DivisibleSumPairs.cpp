#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int divisibleSumPairs(int n, int k, vector<int> ar)
{
    int count = 0;
    
    for (int i = 0; i < n-1; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            if ((ar[i]+ar[j]) % k == 0)
            {
                count++;
            }
        }
    }
    
    return count;
}


// (a + b) % k = (a % k + b % k) % k
// a = 1, b = 2, k = 3
// (1 + 2) % 3 = (1 % 3 + 2 % 3 ) % 3
// 3 % 3 = (1 + 2 ) % 3

int divisibleSumPairs2(int n, int k, vector<int> ar)
{
    vector<int> bucket(k);
    int count = 0;
    int mod = 0;
    
    for_each (ar.cbegin(), ar.cend(),
        [&, k, ar](auto i)
        {
            mod = i % k;
            count += bucket[(k-mod)%k];
            bucket[mod]++;
        }
    );
    
    return count;
}
