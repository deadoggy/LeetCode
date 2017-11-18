package com.dp.q198;

class Solution {
    public int rob(int[] nums) {
        if(0 == nums.length) return 0;

        int[] dp = new int[2];
        int last_position = 0;
        int max = nums[0];
        dp[0]=0; dp[1]=nums[0];

        for(int i=1; i<nums.length; i++){
            if(last_position == i-1){
                if(nums[i] + dp[0] > dp[1]){
                    max = nums[i] + dp[0];
                    last_position = i;
                }else{
                    max = dp[1];
                }
            }else{
                max = nums[i] + dp[1];
                last_position = i;
            }
            dp[0]=dp[1];
            dp[1]=max;
        }

        return max;
    }
}
