/*
    给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
注意：
    答案中不可以包含重复的四元组。

*/

/*
    思路1：就不考虑暴力解法了

    思路2：考虑有没有可能像三数之和一样，转化成两数之和的解法，思路一致，转化成判断是否存在两个两数之和的和为0的情况，可以考虑先遍历获得所有两数之和O(n2/2),考虑去重的问题，
    记录两数之和以及对应的两数index，然后双指针遍历，参照两数之和的实现

    思路3：考虑在三数之和的基础上，当找到三数之和为0时，看target是否包含在数组中，如果借用hashmap可以直接O（1），也就可以在O（n2）的时间复杂度内完成，如果不额外使用空间，多遍历一次数组
    即可在O（n3）时间复杂度内完成
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int vecSize = int(nums.size());
        if (vecSize <= 3){
            return result;
        }
         sort(nums.begin(), nums.end());

        for(int j=0; j<vecSize-3;j++){
            if(j>0 && nums[j] == nums[j-1]) continue;
            if(nums[j]+nums[j+1]+nums[j+2]+nums[j+3] > target) break;

            for (int index = j+1; index < vecSize-2; index++)
            {
                if (index>j+1 && nums[index] == nums[index-1]) continue;

                int low = index + 1;
                int high = vecSize - 1;
                
                while (low < high)
                {
                    int sum = nums[j] + nums[index] + nums[low] + nums[high];
                    if (sum > target)
                    {
                        while(low<high && nums[high] == nums[--high]);
                    }else if (sum < target)
                    {
                        while(low<high && nums[low] == nums[++low]);
                    }else if (sum == target)
                    {
                        vector<int> tmpVec{nums[j] ,nums[index], nums[low], nums[high]};
                        result.push_back(tmpVec);
                        while (low < high && nums[low] == nums[++low]);
                        while(low < high && nums[high] == nums[--high]);
                    }
                }
            }
        }
        return result;
    }
};