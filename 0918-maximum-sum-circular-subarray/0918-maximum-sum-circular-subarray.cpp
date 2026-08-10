class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int totalSum = 0;

        int maxSum = nums[0];
        int currentMax = 0;

        int minSum = nums[0];
        int currentMin = 0;

        for (int num : nums) {

            totalSum += num;

            currentMax = max(num, currentMax + num);
            maxSum = max(maxSum, currentMax);

            currentMin = min(num, currentMin + num);
            minSum = min(minSum, currentMin);
        }

        // All numbers are negative
        if (maxSum < 0) {
            return maxSum;
        }

        int circularSum = totalSum - minSum;

        return max(maxSum, circularSum);
    }
};