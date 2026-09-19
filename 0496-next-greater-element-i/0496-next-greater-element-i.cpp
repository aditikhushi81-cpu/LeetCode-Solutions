class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> st;

        for (int num : nums2) {
            while (!st.empty() && st.back() < num) {
                mp[st.back()] = num;
                st.pop_back();
            }

            st.push_back(num);
        }

        vector<int> ans;

        for (int num : nums1) {
            if (mp.find(num) != mp.end())
                ans.push_back(mp[num]);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};