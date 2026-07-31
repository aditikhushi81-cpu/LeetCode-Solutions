class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> mp;

        // Prefix sum 0 exists before the array starts
        mp[0] = -1;

        int prefixSum = 0;
        int maxLength = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Convert 0 to -1 and 1 to +1
            if (nums[i] == 0)
                prefixSum += -1;
            else
                prefixSum += 1;

            // If this prefix sum appeared before
            if (mp.find(prefixSum) != mp.end()) {

                maxLength = max(maxLength, i - mp[prefixSum]);

            }
            else {

                // Store only the first occurrence
                mp[prefixSum] = i;
            }
        }

        return maxLength;
    }
};