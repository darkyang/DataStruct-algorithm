/*
    给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

    说明：你不能倾斜容器，且 n 的值至少为 2。

*/


/*
    思路1：暴力法，使用max记录当前最大值，双循环遍历，计算每一个i所能容纳的最多的水

    思路2：使用双指针缩减搜索空间，从两个最远的柱子开始，当前容纳水量n*min（a1, an），假设移动较大的数值的柱子，
            可以发现无论后续遍历到的柱子的数值比较小的柱子 大or小，都不可能找到比当前更大的储水量， delta为x轴的差，
            delta < n， 假设a1 较小，当前找到为ak， delta * min(a1, ak) < n * min(a1, an), 所以 a1 对应的解空间就全部被排除了,
            移动较小值的指针，继续寻找是否有比当前更大的储水量。 
*/


class Solution {
public:
    int maxArea(vector<int>& height) {
    int max = 0;
    int i = 0;
    int j = height.size() - 1;
    while (i < j) {
        int area = (j - i) * min(height[i], height[j]);
        max = max(max, area);
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
        return res;
    }
};