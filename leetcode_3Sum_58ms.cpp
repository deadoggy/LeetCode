class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int FirIndex, SecIndex, ThiIndex;
        int sum = 0;
        vector<int> res;
        vector< vector<int> > ret;
        if(nums.size() < 3)
        {
            return ret;
        }
        sort(nums.begin(), nums.end());
        
        if(3 == nums.size() && 0 == nums[0] + nums[1] + nums[2])
        {
            res.push_back(nums[0]);
            res.push_back(nums[1]);
            res.push_back(nums[2]);
            ret.push_back(res);
            return ret;
        }
        
        
        for(FirIndex = 0; FirIndex < nums.size() - 2; FirIndex++)
        {
            if(FirIndex != 0 && nums[FirIndex - 1] == nums[FirIndex])
            {
                continue;
            }
            sum = sum - nums[FirIndex];
            SecIndex = FirIndex + 1;
            ThiIndex = nums.size() - 1;
            while(SecIndex < ThiIndex)
            {
                if(sum - nums[SecIndex] - nums[ThiIndex] > 0)
               {
                   SecIndex++;
               }
               else if(sum - nums[SecIndex] - nums[ThiIndex] < 0)
               {
                   ThiIndex--;
               }
               else
               {
                   res.push_back(nums[FirIndex]);
                   res.push_back(nums[SecIndex]);
                   res.push_back(nums[ThiIndex]);
                   ret.push_back(res);
                   res.clear();
                   SecIndex++;
                   while(nums[SecIndex] == nums[SecIndex-1])
                   {
                       SecIndex ++;
                   }
                   ThiIndex--;
                   while(nums[ThiIndex] == nums[ThiIndex+1])
                   {
                       ThiIndex--;
                   }
               }
            }

            sum = 0;
        }
        return ret;
    }
};