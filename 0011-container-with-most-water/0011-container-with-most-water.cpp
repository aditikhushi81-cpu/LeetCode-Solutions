class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int left = 0;
        int right = height.size() - 1;

        int maximumArea = 0;

        while(left < right)
        {
            int width = right - left;

            int currentHeight = min(height[left], height[right]);

            int currentArea = width * currentHeight;

            maximumArea = max(maximumArea, currentArea);

            if(height[left] <= height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maximumArea;
    }
};