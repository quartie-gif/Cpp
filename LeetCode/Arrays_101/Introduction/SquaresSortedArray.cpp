/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.

*/


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> square {};
        
        for(auto& it: nums)
        {
            square.push_back(it * it);
        }
        // square = for_each(nums.begin(), nums.end(), [](int &n){ n*n; });
        sort(square.begin(), square.end(), [](int a, int b) -> bool { return a < b; });
        
        return square;
    }
};