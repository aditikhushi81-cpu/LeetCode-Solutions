class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int moves = 0;
        int next = 0;

        for (int num : nums) {

            if (num < next) {
                moves += next - num;
                num = next;
            }

            next = num + 1;
        }

        return moves;
    }
};