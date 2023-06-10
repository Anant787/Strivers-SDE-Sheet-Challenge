#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int,int>> v;

    int n=start.size();

    for(int i=0;i<n;i++){

        v.push_back({finish[i],start[i]});

    }

    sort(v.begin(),v.end());

    int end=v[0].first;

    int ans=1;

    for(int i=1;i<v.size();i++){

        if(end<=v[i].second){

            ans+=1;

            end=v[i].first;

        }

    }

    return ans;
}
