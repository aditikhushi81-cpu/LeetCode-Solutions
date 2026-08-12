class Solution {
public:

    long long kadane(vector<int>& arr) {

        long long current = arr[0];
        long long best = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            current = max((long long)arr[i],
                          current + arr[i]);

            best = max(best, current);
        }

        return best;
    }

    int kConcatenationMaxSum(vector<int>& arr, int k) {

        const long long MOD = 1000000007;

        if (k == 1) {
            return max(0LL, kadane(arr)) % MOD;
        }

        long long total = 0;

        for (int num : arr) {
            total += num;
        }

        vector<int> twice;

        for (int num : arr) {
            twice.push_back(num);
        }

        for (int num : arr) {
            twice.push_back(num);
        }

        long long bestTwo = kadane(twice);

        long long answer;

        if (total > 0) {
            answer = bestTwo + (long long)(k - 2) * total;
        }
        else {
            answer = bestTwo;
        }

        return max(0LL, answer) % MOD;
    }
};