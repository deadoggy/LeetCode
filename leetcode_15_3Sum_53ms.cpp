//fist sort nums from smaller ones to biger ones, to make sure answer is in non-descending order
//fix nums[FirIndex], SecIndex begin at FirIndex+1, ThiIndex begin at the end of nums,
//if nums[FirIndex] + (nums[SecIndex] + nums[ThiIndex]) > 0, that means (nums[SecIndex] + nums[ThiIndex]) is 
//too large. Considering SecIndex can not move to left, so move ThiIndex to left to make their sum smaller
//if nums[FirIndex] + (nums[SecIndex] + nums[ThiIndex]) < 0, that means (num[SecIndex] + nums[ThiIndex]) is
//too small, and ThiIndex can not move to right, so SecIndex moves to right side.
// How to remove duplication is showed in the code
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
            //remove duplication
            if(FirIndex != 0 && nums[FirIndex - 1] == nums[FirIndex])
            {
                continue;
            }
            //reduce compute times
            if(nums[FirIndex] > 0)
              break;
            sum = sum - nums[FirIndex];
            SecIndex = FirIndex + 1;
            ThiIndex = nums.size() - 1;
            while(SecIndex < ThiIndex)
            {
                if(nums[FirIndex] + nums[SecIndex] + nums[ThiIndex] < 0)
               {
                   SecIndex++;
               }
               else if(nums[FirIndex] + nums[SecIndex] + nums[ThiIndex] > 0)
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
                   //remove duplication
                   while(nums[SecIndex] == nums[SecIndex-1])
                   {
                       SecIndex ++;
                   }
                   ThiIndex--;
                   //remove duplication
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
