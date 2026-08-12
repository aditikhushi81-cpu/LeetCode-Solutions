class Solution {
public:

    int solve(vector<int>& nums, int firstLen, int secondLen) {

        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int maxFirst = 0;
        int ans = 0;

        for (int end = firstLen + secondLen; end <= n; end++) {

            int firstStart = end - secondLen - firstLen;
            int firstEnd = end - secondLen;

            int firstSum =
                prefix[firstEnd] - prefix[firstStart];

            maxFirst = max(maxFirst, firstSum);

            int secondStart = end - secondLen;
            int secondSum =
                prefix[end] - prefix[secondStart];

            ans = max(ans, maxFirst + secondSum);
        }

        return ans;
    }

    int maxSumTwoNoOverlap(vector<int>& nums,
                           int firstLen,
                           int secondLen) {

        return max(
            solve(nums, firstLen, secondLen),
            solve(nums, secondLen, firstLen)
        );
    }
};