#include <bits/stdc++.h>

int findMajorityElement(int nums[], int n) {
	// Write your code here.
		int el;
        int count=0;

        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                count=1;
                el = nums[i];
            }
            else if(nums[i] == el)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        int count1 = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == el)
            {
                count1++;
            }
        }
        if(count1 > (n / 2))
        {
            return el;
        }

        return -1;
}
