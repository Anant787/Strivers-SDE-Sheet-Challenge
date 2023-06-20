// int minTimeToRot(vector<vector<int>>& grid, int n, int m)
// {
//     // Write your code here. 
// }
#include <queue>

bool valid_Constraints(int cr, int cc, int row, int col) {
    // this utility function will helps us avoid from trying to access any invalid index of our matrix.
    return (cr >= 0 && cr < row && cc >= 0 && cc < col);
}

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // n - row, m - col
    // queue is used for optimal approach i.e. BFS
    queue<pair<int, int>> q; 
    int rot_matrix[n][m], count_fresh_O = 0, timeFrames = -1;
    // 2d rot_matrix is declared which will be a copy of grid because we don't want to modified the original grid data.
    // count_fresh_O stores the count of fresh oranges in the matrix.
    // timeFrames keep track of the time.
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // copy the data of grid array to rot_Matrix
            rot_matrix[i][j] = grid[i][j];
            if(grid[i][j] == 2) {
                // push all the rotten oranges to queue.
                q.push({i, j});
            }
            // count the fresh oranges.
            if(grid[i][j] == 1) count_fresh_O++;
        }
    }
    // If there is no fresh oranges simply return 0 no need to check furthur.
    if(count_fresh_O == 0) return 0;
    // if q is empty it means there is no rotten oranges so return -1 as per the statement given.
    if(q.empty()) return -1;
    
    // otherwise if q is not empty continue below
    while(!q.empty()) {
        int s = q.size();
        for(int i = 0; i < s; i++) {
            auto front = q.front();
            q.pop();
            // current adjacent row index
            int cr = front.first; 
            // current adjacent col index
            int cc = front.second;
            // rot the oranges below if possible
            if(valid_Constraints( cr + 1, cc, n, m ) && rot_matrix[cr + 1][cc] == 1) {
                // decrement the count of the fresh oranges because one of them has been rotten.
                count_fresh_O--;
                // set the current row, col value to 2 (indicates rotting)
                rot_matrix[cr + 1][cc] = 2;
                // push to queue
                q.push({cr + 1, cc});
            }
            // rot the oranges above if possible
            if(valid_Constraints( cr - 1, cc, n, m ) && rot_matrix[cr - 1][cc] == 1) {
                // decrement the count of the fresh oranges because one of them has been rotten.
                count_fresh_O--;
                // set the current row, col value to 2 (indicates rotting)
                rot_matrix[cr - 1][cc] = 2;
                // push to queue
                q.push({cr - 1, cc});
            }  
            // rot the right oranges if possible
            if(valid_Constraints( cr, cc + 1, n, m ) && rot_matrix[cr][cc + 1] == 1) {
                // decrement the count of the fresh oranges because one of them has been rotten.
                count_fresh_O--;
                // set the current row, col value to 2 (indicates rotting)
                rot_matrix[cr][cc + 1] = 2;
                // push to queue
                q.push({cr, cc + 1});
            }  
            // rot the left oranges if possible
            if(valid_Constraints( cr, cc - 1, n, m ) && rot_matrix[cr][cc - 1] == 1) {
                // decrement the count of the fresh oranges because one of them has been rotten.
                count_fresh_O--;
                // set the current row, col value to 2 (indicates rotting)
                rot_matrix[cr][cc - 1] = 2;
                // push to queue
                q.push({cr, cc - 1});
            }  
            
        }
        // increment the timeFrames after the first level traversal
        timeFrames++; 
    }
    // return the timeFrames if there is no more fresh oranges otherwise return -1.
    return (count_fresh_O == 0)?  timeFrames : -1; 
}
