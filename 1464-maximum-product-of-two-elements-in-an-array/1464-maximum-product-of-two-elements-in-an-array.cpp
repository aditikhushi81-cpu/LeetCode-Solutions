class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        int largest = nums[nums.size() - 1];
        int secondLargest = nums[nums.size() - 2];

        return (largest - 1) * (secondLargest - 1);
    }
};