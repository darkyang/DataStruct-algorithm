/*
    给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

    你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

*/


/*
    思路1:双循环遍历数组，对每个下标为i的整数，在剩下的n-i-1个整数中寻找是否有满足要求的整数，时间复杂度O（n2）

    思路2：只需要遍历一遍即可，使用辅助hashmap，转换思路，不再从每个元素后方寻找，而是从已经遍历过的元素当中寻找
    是否存在满足条件的整数
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            int tmp = target - nums.at(i);
            if(map.find(tmp) != map.end()){
                result.push_back(map[tmp]);
                result.push_back(i);
            }else{
                map[nums[i]] = i;
            }
        }
        return result;
    }
};