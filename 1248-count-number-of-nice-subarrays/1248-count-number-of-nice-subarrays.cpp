class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int odd = 0;
        int count = 0;

        for (int x : nums) {
            if (x % 2 != 0) {
                odd++;
            }

            if (mp.find(odd - k) != mp.end()) {
                count += mp[odd - k];
            }

            mp[odd]++;
        }

        return count;
    }
};