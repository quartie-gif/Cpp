/*
Given an array nums of integers, return how many of them contain an even number of digits.

Example:
Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.


Constraints:

1 <= nums.length <= 500
1 <= nums[i] <= 10^5

*/


class Solution {
public:
    int findNumbers(vector<int>& nums) 
    {
        unsigned count = 0, div = 0;
        
        
        
        for(auto it: nums)
        {
            while(it != 0)
            {
                it /= 10;
                ++div;
            }
            if(div % 2 == 0)
                ++count;
            div = 0;
        }
        return count;
            
    }
};