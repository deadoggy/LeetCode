//The algriothm is the best. Why it run slow may not be the responsibility of algriothm
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        if(3 == nums.size())
        {
            return nums[0] + nums[1] + nums[2];
        }
        
        int FirIndex, SecIndex, ThiIndex;
        int Dis = 1000000;
        int ret = 0;
        for(FirIndex = 0; FirIndex < nums.size()-2; FirIndex++)
        {
            if(FirIndex != 0 && nums[FirIndex] == nums[FirIndex-1])
            {
              continue;  
            }
            
            SecIndex = FirIndex + 1;
            ThiIndex = nums.size() - 1;
            while(SecIndex < ThiIndex)
            {
                int tempDis = target - nums[FirIndex] - nums[SecIndex] - nums[ThiIndex];
                if(tempDis < 0)
                {
                    tempDis = -tempDis;
                }
                
                if(tempDis < Dis)
                {
                    Dis = tempDis;
                    ret = nums[FirIndex] + nums[SecIndex] + nums[ThiIndex];
                    if(0 == Dis)
                       break;
                }
                else if(nums[FirIndex] + nums[SecIndex] + nums[ThiIndex] > target)
                {
                    ThiIndex--;
                    while(nums[ThiIndex] == nums[ThiIndex+1])
                    {
                        ThiIndex--;
                    }
                }
                else
                {
                    SecIndex++;
                    while(nums[SecIndex] == nums[SecIndex-1])
                    {
                        SecIndex++;
                    }
                }
            }
        }
        return ret;
    }
};
