class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for (auto it : mp) {
            buckets[it.second].push_back(it.first);
        }

        vector<int> ans;

        for (int freq = nums.size(); freq >= 1; freq--) {

            for (int num : buckets[freq]) {

                ans.push_back(num);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};