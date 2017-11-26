package com.dp.q64;

class Solution {
    public int minPathSum(int[][] grid) {

        int width = grid[0].length;
        int height = grid.length;
        int[][] dp = new int[height][width];
        dp[0][0] = grid[0][0];
        for(int i=0; i<width; i++){
            for(int j=0; j<height; j++){
                if(i==0 && j==0) continue;
                if(i == 0){
                    dp[j][i] = dp[j-1][i] + grid[j][i];
                }else if(j == 0){
                    dp[j][i] = dp[j][i-1] + grid[j][i];
                }else{
                    dp[j][i] = dp[j-1][i] + grid[j][i] < dp[j][i-1] + grid[j][i] ?
                            dp[j-1][i] + grid[j][i] : dp[j][i-1] + grid[j][i];
                }
            }
        }
        return dp[height-1][width-1];

    }
}