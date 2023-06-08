#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    //Write your code here
    int i=0,j=0;
        unordered_map<char,int>mp;
        int ans = INT_MIN;
        
        if(s.size() == 0)
        {
            return 0;
        }

        while(j<s.size())
        {
            mp[s[j]]++;

            if(mp.size() == j-i+1)
            {
                ans = max(ans,j-i+1);
                j++;
            }
            else if(mp.size() < j-i+1)
            {
                while(mp.size() < j-i+1)
                {
                    mp[s[i]]--;

                    if(mp[s[i]] == 0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
}
