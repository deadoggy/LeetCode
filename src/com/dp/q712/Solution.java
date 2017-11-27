package com.dp.q712;

class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        char[] s1c = s1.toCharArray();
        char[] s2c = s2.toCharArray();
        int[][] dp = new int[s1c.length+1][s2c.length+1];
        int sum = 0;
        for(char ch : s1c) sum += ch;
        for(char ch : s2c) sum += ch;

        for(int i=1; i<=s1c.length; i++){
            for(int j=1; j<=s2c.length; j++){
                if(s1c[i-1] == s2c[j-1]){
                    dp[i][j] = dp[i-1][j-1] + s1c[i-1] + s2c[j-1];
                }else{
                    dp[i][j] = dp[i][j-1] > dp[i-1][j] ? dp[i][j-1] : dp[i-1][j];
                }
            }
        }

        return sum - dp[s1c.length][s2c.length];
    }
}
