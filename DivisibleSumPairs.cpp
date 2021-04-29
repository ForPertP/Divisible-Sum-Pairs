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

int divisibleSumPairs2(int n, int k, vector<int> ar)
{
    vector<int> bucket(k);
    int count = 0;
    int mod = 0;
    
    for_each (ar.begin(), ar.end(),
        [&, k, ar](auto i)
        {
            mod = i % k;
            count += bucket[(k-mod)%k];
            bucket[mod]++;
        }
    );
    
    return count;
}
