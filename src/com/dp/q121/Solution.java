package com.dp.q121;

class Solution {
    public int maxProfit(int[] prices) {
        if(0 == prices.length) return 0;

        int minBefore=prices[0];
        int maxProfit=0;
        int tempProfit;
        for(int i=1; i<prices.length; i++){
            tempProfit = prices[i]-minBefore > 0 ? prices[i] - minBefore : 0;
            if(tempProfit > maxProfit){
                maxProfit = tempProfit;
            }

            if(minBefore > prices[i]){
                minBefore = prices[i];
            }
        }
        return maxProfit;
    }
}