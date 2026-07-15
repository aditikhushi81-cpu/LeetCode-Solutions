class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        unordered_map<int,int> freq;

        for(int i = 0; i < arr1.size(); i++)
        {
            freq[arr1[i]]++;
        }

        vector<int> ans;

        for(int i = 0; i < arr2.size(); i++)
        {
            while(freq[arr2[i]] > 0)
            {
                ans.push_back(arr2[i]);
                freq[arr2[i]]--;
            }
        }

        vector<int> remaining;

        for(int i = 0; i < arr1.size(); i++)
        {
            if(freq[arr1[i]] > 0)
            {
                remaining.push_back(arr1[i]);
                freq[arr1[i]]--;
            }
        }

        sort(remaining.begin(), remaining.end());

        for(int i = 0; i < remaining.size(); i++)
        {
            ans.push_back(remaining[i]);
        }

        return ans;
    }
};