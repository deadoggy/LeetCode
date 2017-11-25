package com.dp.q718;


/*
* 这里的dp[i][j]并不是A[0:i]和B[0:j]之间的最长公共子数组长度，
* 而是以A[i]和B[j]结尾的最长公共子数组的长度
* */
class Solution {
    public int findLength(int[] A, int[] B) {
        int ret = 0;
        int[][] dp = new int[A.length+1][B.length+1];
        for(int i=1; i<=A.length; i++){
            for(int j=1; j<=B.length; j++){
                if(A[i-1] == B[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    ret =ret < dp[i][j] ? dp[i][j] : ret;
                }
            }
        }
        return ret;
    }
}