/*
    给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

    不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

*/

/*
    思路：由于限定额外使用的空间为O（1），使用一个新数组直接遍历一遍的简单思路不可行。将元素直接删除的操作当然是不可能的，联想到单链表中删除某个节点时，将next节点值复制到当前节点，再将next节点
        删掉的思路，使用双指针，当前指针和next值相同时，current++，将远端指针的值复制到current，远端指针移动直到找到下一个不相同的元素。
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int vecSize = int(nums.size());
        if(vecSize < 2) return vecSize;
        sort(nums.begin(), nums.end());
        int slow = 0;
        int fast = 1;
        while(fast < vecSize){
            if(nums[fast] != nums[slow]){
                nums[++slow] = nums[fast];
            }
            fast++;
        }
        return (slow + 1);
    }
};