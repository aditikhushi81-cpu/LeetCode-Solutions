class Solution {
public:
    bool isPossible(vector<int>& nums) {

        unordered_map<int, int> freq;
        unordered_map<int, int> need;

        // Count frequency of every number
        for (int num : nums) {
            freq[num]++;
        }

        // Process every number
        for (int num : nums) {

            // This number was already used
            if (freq[num] == 0) {
                continue;
            }

            // Case 1: Extend an existing sequence
            if (need[num] > 0) {

                freq[num]--;
                need[num]--;
                need[num + 1]++;
            }

            // Case 2: Start a new sequence
            else if (freq[num + 1] > 0 &&
                     freq[num + 2] > 0) {

                freq[num]--;
                freq[num + 1]--;
                freq[num + 2]--;

                need[num + 3]++;
            }

            // Cannot use this number
            else {
                return false;
            }
        }

        return true;
    }
};