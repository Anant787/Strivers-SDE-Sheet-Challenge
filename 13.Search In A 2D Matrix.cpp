bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(!matrix.size())    //edge case
        {
            return false;
        }

        int n = matrix.size();  //row size
        int m = matrix[0].size();   //column size

        //Binary search 

        int lo = 0 , hi = n*m-1;

        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;       //calculate mid element

            //[mid/m] gives the index of row or i
            //[mid%m] gives the index of column or j

            if(matrix[mid/m][mid%m] == target)
            {
                return true;
            }
            if(matrix[mid/m][mid%m] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return false;
        
}
