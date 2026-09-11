class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;

        for (int w : weights) {
            low = max(low, w);
            high += w;
        }

        while (low < high) {
            int mid = low + (high - low) / 2;

            int day = 1;
            int currentWeight = 0;

            for (int w : weights) {
                if (currentWeight + w > mid) {
                    day++;
                    currentWeight = 0;
                }

                currentWeight += w;
            }

            if (day <= days) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};