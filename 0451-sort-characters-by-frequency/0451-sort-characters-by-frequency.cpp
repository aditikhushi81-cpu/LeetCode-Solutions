class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;

        // Count frequency
        for (char ch : s) {
            mp[ch]++;
        }

        // Store character and frequency
        vector<pair<char, int>> freq;

        for (auto it : mp) {
            freq.push_back({it.first, it.second});
        }

        // Sort by frequency in descending order
        sort(freq.begin(), freq.end(),
             [](pair<char, int>& a, pair<char, int>& b) {
                 return a.second > b.second;
             });

        string ans = "";

        // Build answer
        for (auto it : freq) {
            ans.append(it.second, it.first);
        }

        return ans;
    }
};