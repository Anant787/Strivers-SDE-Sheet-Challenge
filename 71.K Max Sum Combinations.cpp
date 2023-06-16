 #include <bits/stdc++.h> 
// vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
// 	// Write your code here.
// }
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){

    // Write your code here.

    //sort desc order

    sort(a.begin(),a.end(),greater<int> ());

    sort(b.begin(),b.end(),greater<int> ());

 

    vector<int> ans;

    set<pair<int,int> > visited;//elements coordinates

 

    priority_queue<pair<int,pair<int,int> > > pq;//value,elements coordinates

    pq.push({a[0]+b[0],{0,0}});//0,0

 

    for(int i=0;i<k;i++)

    {

        pair<int,pair<int,int> > element = pq.top();

        pq.pop();

 

        ans.push_back(element.first);

 

        if(element.second.first+1<n &&

            visited.find({element.second.first+1,element.second.second})==visited.end() )//1,0

 

            {

                pq.push({a[element.second.first+1]+b[element.second.second],

                    {element.second.first+1,element.second.second}});

 

                visited.insert({element.second.first+1,element.second.second});

            }

 

        if(element.second.second+1<n &&

            visited.find({element.second.first,element.second.second+1})==visited.end() )//0,1

 

            {

                pq.push({a[element.second.first]+b[element.second.second+1],

                    {element.second.first,element.second.second+1}});

                    

                visited.insert({element.second.first,element.second.second+1});

            }   

    }

    return ans;

}

