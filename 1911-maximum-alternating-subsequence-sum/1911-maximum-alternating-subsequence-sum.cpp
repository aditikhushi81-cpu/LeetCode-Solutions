class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        long long even = 0;
        long long odd = 0;

        for (int num : nums) {

            long long oldEven = even;
            long long oldOdd = odd;

            even = max(oldEven, oldOdd + num);
            odd = max(oldOdd, oldEven - num);
        }

        return even;
    }
};