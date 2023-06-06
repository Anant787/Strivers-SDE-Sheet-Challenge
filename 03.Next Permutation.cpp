#include <bits/stdc++.h> 

// vector<int> nextPermutation(vector<int> &permutation, int n)
// {
    //  Write your code here.
//     if(n==1)
//         return permutation;

//     for(int j=n-2;j>=0;j--){

//       if(permutation[n-1]>permutation[j]){

//         swap(permutation[n-1],permutation[j]);

//         sort(permutation.begin()+j+1,permutation.end());

//         return permutation;
//       }
//     }
//     reverse(permutation.begin(),permutation.end()); 
//     return permutation;

// }

vector<int> nextPermutation(vector<int> &nums, int n)
{
    //  Write your code here.
    
    next_permutation(nums.begin(),nums.end());
    return nums;

    // int k,l;
    // for(int k=n-2;k>=0;k--)
    // {
    //   if (nums[k] < nums[k + 1]) 
    //   {
    //     break;
    //   }
    // } 

    // if(k<0)
    // {
    //     reverse(nums.begin(),nums.end());
    // }
    // else
    // {
    //     for(l = n-1 ; l>=k;l--)
    //     {
    //         if(nums[l] > nums[k])
    //         {
    //             break;
    //         }
    //     }

    //     swap(nums[k],nums[l]);

    //     reverse(nums.begin()+k+1 , nums.end());
    // }
    // return nums;
}
