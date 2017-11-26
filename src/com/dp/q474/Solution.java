package com.dp.q474;

class Solution {

    private static int[] count(String str){
        int[] ret = new int[2];
        for(char ch : str.toCharArray()){
            if(ch == '0') ret[0]++;
            else ret[1]++;
        }
        return ret;
    }

    public int findMaxForm(String[] strs, int m, int n) {
        int[][][] dp = new int[strs.length+1][m+1][n+1];
        for(int k=1; k<=strs.length; k++){
            for(int i=0; i<=m; i++){
                for(int j=0; j<=n; j++){
                    int[] chCounter = count(strs[k-1]);
                    int a = i-chCounter[0];
                    int b = j-chCounter[1];
                    if(a < 0 || b < 0) dp[k][i][j] = dp[k-1][i][j];
                    else dp[k][i][j] = dp[k-1][i][j] > dp[k-1][a][b] + 1?  dp[k-1][i][j] :  dp[k-1][a][b] + 1;
                }
            }
        }
        return dp[strs.length][m][n];
    }
}