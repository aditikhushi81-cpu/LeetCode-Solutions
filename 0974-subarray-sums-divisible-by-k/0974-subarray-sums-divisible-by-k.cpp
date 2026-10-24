class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for (int x : nums) {
            sum += x;
            int rem = ((sum % k) + k) % k;

            count += mp[rem];
            mp[rem]++;
        }

        return count;
    }
};