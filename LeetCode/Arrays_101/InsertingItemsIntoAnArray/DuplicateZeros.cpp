/*
Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.


Example:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

Note:

1 <= arr.length <= 10000
0 <= arr[i] <= 9
*/


class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        unsigned _size = arr.size(), i = _size - 1;
        while (i >= 0)
            {
                int temp = arr[i];
                if (!temp)
                {
                    arr.insert(arr.begin() + i, 0);
                    arr.pop_back();
                }
                --i;
            }
        }
};