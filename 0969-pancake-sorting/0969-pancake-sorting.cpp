class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr)
    {
        vector<int> ans;

        for(int size = arr.size(); size > 1; size--)
        {
            int maxIndex = 0;

            for(int i = 1; i < size; i++)
            {
                if(arr[i] > arr[maxIndex])
                {
                    maxIndex = i;
                }
            }

            if(maxIndex == size - 1)
            {
                continue;
            }

            reverse(arr.begin(), arr.begin() + maxIndex + 1);
            ans.push_back(maxIndex + 1);

            reverse(arr.begin(), arr.begin() + size);
            ans.push_back(size);
        }

        return ans;
    }
};