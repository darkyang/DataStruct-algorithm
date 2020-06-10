/*
    给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
*/

/*
    思路：和三数之和为0思路相近，双指针缩小解空间
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int vecSize = int(nums.size());
        if (vecSize <= 3){
            int sum = 0;
            for(int i=0; i<vecSize; i++){
                sum += nums[i];
            }
            return sum;
        }
        int possibleSize = vecSize - 2;
        sort(nums.begin(), nums.end());
        int result =  nums[0] + nums[1] + nums[2];
        for (int index = 0; index < possibleSize; index++)
        {
            if (nums[index] + nums[index+1] + nums[index+2] == target)  return target;
            int low = index + 1;
            int high = vecSize - 1;
            while (low < high)
            {
                int sum = nums[low] + nums[high] + nums[index];
                if(abs(sum - target) < abs(result - target)){
                    result = sum;
                } 
                if (sum - target == 0) return target;                
                if(sum - target > 0) 
                    while(low<high && nums[high] == nums[--high]);
                else
                    while(low<high && nums[low] == nums[++low]);
            }
            while(index+1 < possibleSize && nums[index] == nums[index+1]){
                index++;
            };
        }
        return result;
    }
};