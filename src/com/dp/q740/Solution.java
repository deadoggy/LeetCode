package com.dp.q740;

import java.util.Arrays;
import java.util.HashMap;

class Solution {
    public int deleteAndEarn(int[] nums) {
        if(0 == nums.length) return 0;

        HashMap<Integer, Integer> numMap = new HashMap<Integer, Integer>();
        for(int i=0; i<nums.length; i++){
            if(numMap.containsKey(nums[i])){
                numMap.put(nums[i], nums[i] + numMap.get(nums[i]));
            }else{
                numMap.put(nums[i], nums[i]);
            }
        }

        Object[] disNum = numMap.keySet().toArray();
        Arrays.sort(disNum);

        int[] dp = new int[disNum.length+1];
        dp[0] = 0; dp[1] = numMap.get(disNum[0]);
        for(int i=2; i<=disNum.length; i++){
            int numI = i-1;
            if((Integer)disNum[numI] == (Integer)disNum[numI-1]+1){
                dp[i] = dp[i-1] > dp[i-2] + numMap.get(disNum[numI]) ? dp[i-1] : dp[i-2] + numMap.get(disNum[numI]);
            }else{
                dp[i] = dp[i-1] + numMap.get(disNum[numI]);
            }
        }
        return dp[disNum.length];
    }
}
