#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
     sort(arr.begin(),arr.end());
    for(int i=0;i<n-3;i++){
        for(int j= i+1;j<n-2;j++){
            int start = j+1;
            int end = n-1;
            while(start<end){
                int sum = arr[i]+arr[j]+arr[start]+arr[end];
                if(sum == target) return "Yes";
                else if(sum<target) start++;
                else end--;
            }
        }
    }
    return "No";
}
