package com.dp.q698;

import java.util.Arrays;

/**
 *
 *
 * Let used have the i-th bit set if and only if nums[i] has already been used. Our goal is to use nums in some order so that placing them into groups in that order will be valid. search(used, ...) will answer the question: can we partition unused elements of nums[i] appropriately?

 This will depend on todo, the sum of the remaining unused elements, not crossing multiples of target within one number. If for example our target is 10, and our elements to be placed in order are [6, 5, 5, 4], this would not work as 6 + 5 "crosses" 10 prematurely.

 If we could choose the order, then after placing 5, our unused elements are [4, 5, 6]. Using 6 would make todo go from 15 to 9, which crosses 10 - something unwanted. However, we could use 5 since todo goes from 15 to 10; then later we could use 4 and 6 as those placements do not cross.

 It turns out the maximum value that can be chosen so as to not cross a multiple of target, is targ = (todo - 1) % target + 1. This is essentially todo % target, plus target if that would be zero.

 Now for each unused number that doesn't cross, we'll search on that state, and we'll return true if any of those searches are true.

 Notice that the state todo depends only on the state used, so when memoizing our search, we only need to make lookups by used.

 In the solutions below, we present both a top-down dynamic programming solution, and a bottom-up one. The bottom-up solution uses a different notion of state.
 *
 * */

class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {

        /*
        * dp[0011(2)] = dp[0010(2)] + nums[0] cross target ? false : true;
        * */
        int sum = Arrays.stream(nums).sum();
        if(sum % k != 0){
            return false;
        }
        int target = sum / k;
        int N = nums.length;
        boolean[] dp = new boolean[1 << N];//如果有4个数，每个数要或者不要， 正好是 2^4， 用二进制表示就是0000， 0001， 0010，.....
        int[] total = new int[1 << N];
        dp[0] = true;

        for(int i=0; i < (1<<N); i++){
            if(!dp[i]) continue; // eg : [0000(2)] 时已经计算过了所有只取一个数字的情况， 符合条件的已经是true了, False的一定不可以了
            for(int j=0; j<N; j++){
                int future = i | (1 << j);
                if(dp[future] || i == future) continue;

                if((total[i]%target) + nums[j] <= target ) /*cross the target*/{
                    dp[future] = true;
                    total[future] = total[i] + nums[j];
                }
            }
        }
        return dp[(1<<N)-1];
    }
}