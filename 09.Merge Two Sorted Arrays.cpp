#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
		// int i=m;      //index at which the zeros start
        // int j=0;      //to iterate the nums2
        // while(i<arr1.size())       
        // {
        //     arr1[i]=arr2[j];       //zeros of nums1 get replaced by the element of nums1
        //     i++;
        //     j++;
        // }
        // sort(arr1.begin(),arr1.end());

		int i = 0;
		int j = 0;
		vector<int> x;
		while (i < m && j < n) {
			if (arr1[i] < arr2[j]) {
			x.push_back(arr1[i++]);
			} else {
			x.push_back(arr2[j++]);
      }
		}
		while (i < m) {
		  x.push_back(arr1[i++]);
		}
		while (j < n) {
			x.push_back(arr2[j++]);
		}
		return x;
}
