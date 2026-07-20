#include<vector>
#include<iostream>

class Solution {
public:
// two trivial cases
// all positive numbers just return the whole arrray
// all negative numbers, return the max number only subarray
// non-trivial case = mix of +ve and -ve numbers
// can be done with dvnq(Onlgn On) dp(On) but we don't need now
    int maxSubArray(std::vector<int>& nums) {
        int sum = nums[0];
        int maxSum = nums[0];
        int start_index = 0;
        int end_index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum == 0) start_index = i;
            sum += nums[i];
            if (sum > maxSum) {
                maxSum = sum;
                end_index = i;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        std::cout << start_index << " " << end_index<<"\n";
        return maxSum;
    }
};