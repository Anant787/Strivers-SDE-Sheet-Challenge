int removeDuplicates(vector<int> &nums, int n) {
	// Write your code here.
	if(n == 0) return 0;
        int left = 0;
        for(int right =1; right< n; right++){
           if(nums[left] != nums[right])
               left++;
               nums[left] = nums[right];
           }
    return left+1;
        
}
