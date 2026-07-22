class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int currentMax = nums[0];
        int currentMin = nums[0];
        int answer = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            int tempMax = max({
                nums[i],
                currentMax * nums[i],
                currentMin * nums[i]
            });

            int tempMin = min({
                nums[i],
                currentMax * nums[i],
                currentMin * nums[i]
            });

            currentMax = tempMax;
            currentMin = tempMin;

            answer = max(answer, currentMax);
        }

        return answer;
    }
};