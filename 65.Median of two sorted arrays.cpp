double median(vector<int>& v1, vector<int>& v2) {
	// Write your code here.
	int n1 = v1.size();
        int n2 = v2.size();

        if(n1>n2)
        {
            return median(v2,v1);
        }

        int low=0,high = n1;

        while(low<=high)
        {
            int cut1 = (low+high)/2;
            int cut2 = (n1+n2+1)/2 - cut1;

            double l1 = cut1 == 0 ? INT_MIN : v1[cut1-1];
            double l2 = cut2 == 0 ? INT_MIN : v2[cut2-1];

            double r1 = cut1 == n1 ? INT_MAX : v1[cut1];
            double r2 = cut2 == n2 ? INT_MAX : v2[cut2];

            if(l1<=r2  && l2<=r1)
            {
                if((n1 + n2) & 1)    //for odd
                {
                    return max(l1,l2);
                }
                else
                {
                    return (max(l1,l2) + min(r1,r2)) / 2.0;
                }
            }
            else if(l1>r2)
            {
                high = cut1-1;
            }
            else
            {
                low = cut1+1;
            }
        }
        return 0.0;
}
