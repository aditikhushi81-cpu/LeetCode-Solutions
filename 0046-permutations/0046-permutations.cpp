class Solution {
public:

    void solve(vector<int>& nums,
               vector<int>& temp,
               vector<vector<int>>& ans,
               vector<bool>& used)
    {
        // Base Case
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        // Try every element
        for(int i = 0; i < nums.size(); i++)
        {
            // Skip if already used
            if(used[i])
                continue;

            // Choose
            used[i] = true;
            temp.push_back(nums[i]);

            // Recursive Call
            solve(nums, temp, ans, used);

            // Backtrack
            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;

        // Initially, no element is used
        vector<bool> used(nums.size(), false);

        solve(nums, temp, ans, used);

        return ans;
    }
};