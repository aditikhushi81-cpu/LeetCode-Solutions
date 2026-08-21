class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {

        unordered_map<int, int> mp;

        for (int num : arr) {
            mp[num]++;
        }

        sort(arr.begin(), arr.end(),
             [](int a, int b) {
                 return abs(a) < abs(b);
             });

        for (int num : arr) {

            if (mp[num] == 0) {
                continue;
            }

            int doubled = num * 2;

            if (mp[doubled] == 0) {
                return false;
            }

            mp[num]--;
            mp[doubled]--;
        }

        return true;
    }
};