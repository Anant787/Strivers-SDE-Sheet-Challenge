#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &s, vector<int> &e) {
    // Write your code here.
    int n = s.size();
    map<pair<int,int>, int>m;
    for(int i=0; i<n; i++){
        m[{e[i],i+1}] = s[i];
    }

    auto endtime = m.begin()->first.first;    

    vector<int>ans;
    ans.push_back(m.begin()->first.second);
    for(auto it = m.begin()++; it!=m.end(); it++){
        if(it->second > endtime){
            ans.push_back(it->first.second);
            endtime = it->first.first;
        }
    }

    return ans;
}
