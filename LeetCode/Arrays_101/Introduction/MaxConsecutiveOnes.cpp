/* Given a binary array nums, return the maximum number of consecutive 1's in the array.


Example:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.


Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.


*/ 

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        unsigned max = 0, temp = 0;
        
        for(const auto &it: nums)
        {
            if(it == 1)
            {
                temp ++;   
                max = std::max(temp, max);
            }
            else{
                temp = 0;
            }
        }
        return max;
    }
};