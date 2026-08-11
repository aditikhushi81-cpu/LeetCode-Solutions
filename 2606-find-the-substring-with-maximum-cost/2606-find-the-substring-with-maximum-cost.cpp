class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {

        vector<int> value(26);

        // Normal values: a=1, b=2, ..., z=26
        for (int i = 0; i < 26; i++) {
            value[i] = i + 1;
        }

        // Replace normal values with custom values
        for (int i = 0; i < chars.length(); i++) {
            value[chars[i] - 'a'] = vals[i];
        }

        // Kadane's Algorithm
        int current = 0;
        int ans = 0;

        for (char ch : s) {

            int cost = value[ch - 'a'];

            current = max(cost, current + cost);

            ans = max(ans, current);
        }

        return ans;
    }
};