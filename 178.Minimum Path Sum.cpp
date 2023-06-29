#include <bits/stdc++.h>

 

int solve(vector<vector<int>> &grid, int i, int j, int n, int m, vector<vector<int>> &dp) {

    if(i > n-1 || j > m-1){

        return 1e9;

    }

    if(i == n-1 && j == m-1){

        return grid[i][j];

    }

    if(dp[i][j] != -1){

        return dp[i][j];

    }

 

    int downAns = grid[i][j] + solve(grid,i+1,j,n,m,dp);

    int rightAns = grid[i][j] + solve(grid,i,j+1,n,m,dp);

 

    return dp[i][j] = min(downAns, rightAns);

} 

 

int solveTab(vector<vector<int>> &grid,int n, int m){

    vector<vector<int>> dp(n, vector<int>(m, 0));

    

    for(int i = n-1; i >= 0; i--){

        for(int j = m-1; j >= 0; j--){

            if(i == n-1 && j == m-1){

                dp[i][j] = grid[i][j];

            }

            else{

                int downAns = 1e9, rightAns = 1e9;

                if(i+1 != n) downAns = grid[i][j] + dp[i+1][j];

                if(j+1 != m) rightAns = grid[i][j] + dp[i][j+1];

                dp[i][j] = min(downAns, rightAns);

            }

        }

    }

    return dp[0][0];

}

 

int solveSO(vector<vector<int>> &grid,int n, int m){

    vector<int> temp(m, 0);

 

    for(int i = n-1; i >= 0; i--){

        vector<int> curr(m, 0);

        for(int j = m-1; j >= 0; j--){

            if(i == n-1 && j == m-1){

                curr[j] = grid[i][j];

            }

            else{

                int downAns = 1e9, rightAns = 1e9;

                if(i+1 != n) downAns = grid[i][j] + temp[j];

                if(j+1 != m) rightAns = grid[i][j] + curr[j+1];

                curr[j] = min(downAns, rightAns);

            }

        }

        temp = curr;

    }

    return temp[0];

}

 

int minSumPath(vector<vector<int>> &grid) {

    // Write your code here.

    int n = grid.size();

    int m = grid[0].size();

 

    vector<vector<int>> dp(n, vector<int>(m, -1));

 

    int ans = solveSO(grid,n,m);

    return ans;

}
