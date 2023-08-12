class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n, 0); // Single 1D vector for memoization

        dp[0] = 1; // Initial value for the start cell
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0; // Reset to 0 if there's an obstacle in the current cell
                } else if (j > 0) {
                    dp[j] += dp[j - 1]; // Calculate the current cell's value based on left cell
                }
            }
        }

        return dp[n - 1]; // The last element contains the result for the destination cell
    }
};