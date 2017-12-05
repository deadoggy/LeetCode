package com.dp.q688;

/*
* Let f[r][c][steps] be the probability of being on square (r, c) after steps steps. Based on how a knight moves, we have the following recursion:

f[r][c][steps] =∑(dr,dc)   f[r+dr][c+dc][steps−1]/8.0

where the sum is taken over the eight (dr, dc)(dr,dc) pairs (2, 1),(2,1), (2, -1),(2,−1), (-2, 1),(−2,1), (-2, -1),(−2,−1), (1, 2),(1,2), (1, -2),(1,−2), (-1, 2),(−1,2), (-1, -2)(−1,−2).
* */

class Solution {
    public double knightProbability(int N, int K, int r, int c) {


        double[][][] dp = new double[2][N][N];
        int last = 0;
        int[][] step = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2}};
        dp[last][r][c] = 1.0;

        for(int k=0; k<K; k++){
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    for(int s=0; s<8; s++){
                        int newi=i+step[s][0];
                        int newj=j+step[s][1];
                        if(newi>=0 && newi<N && newj>=0&&newj<N){
                            dp[1-last][newi][newj] += dp[last][i][j] / 8.0;
                        }
                    }
                    dp[last][i][j] = 0.0; //  attention
                }
            }
            last = 1 - last;
        }

        double ret = 0.0;
        for(int i=0; i<N; i++){
            for(double p : dp[last][i]){
                ret += p;
            }
        }
        return ret;
    }
}
