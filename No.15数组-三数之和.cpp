/*
    给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

    注意：答案中不可以包含重复的三元组。

*/

/*
    思路1：暴力解法 时间复杂度 O(n3)

    思路2：类比两数之和，缩减解空间，对于处于位置i的元素，问题就转变成了两数之和等于当前位置元素的相反数，
    三数之和问题就转变成了两数之和，使用双指针来寻找两数之和有O（n）的解法，总体时间复杂度O（n2），空间复杂度O（n）

    思路3：有没有时间复杂度O（n2），空间复杂度O（1）的方法
            首先，无序数组排序，可以缩小每个元素的解空间的整体大小，
            第二，如果有重复元素，跳过重复元素也会缩小解空间
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> result;
        int vecSize = int(nums.size());
        if (vecSize <= 2){
            return result;
        }
        int possibleSize = vecSize - 2;
        sort(nums.begin(), nums.end());

        for (int index = 0; index < possibleSize; index++)
        {
            if (nums[index]>0)
            {
                break;
            }

            int low = index + 1;
            int high = vecSize - 1;

            while (low < high)
            {
                int lowValue = nums[low];
                int highValue = nums[high];
                if(lowValue + highValue == -nums[index]){
                    vector<int> tmpVec{nums[index], nums[low], nums[high]};
                    result.push_back(tmpVec);

                    while (low < high && nums[low] == lowValue)
                    {   
                        low++;
                    }
                    while(low < high && nums[high] == highValue)
                    {
                        high--;
                    }
                }else if(lowValue + highValue < -nums[index]){
                    low++;
                }else{
                    high--;
                }
            }

            while(index+1 < possibleSize && nums[index] == nums[index+1]){
                index++;
            }
        }
        return result;
    }
};