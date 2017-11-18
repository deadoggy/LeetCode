package com.questions.q53;

class Solution {
    public int maxSubArray(int[] nums) {
        int upToNowMax = nums[0];
        int maxSum = nums[0];
        for(int i=1; i<nums.length; i++){
            upToNowMax = upToNowMax > 0 ? upToNowMax + nums[i] : nums[i];
            maxSum = maxSum > upToNowMax? maxSum : upToNowMax;
        }
        return maxSum;
    }
}
