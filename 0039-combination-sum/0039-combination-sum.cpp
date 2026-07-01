class Solution {
public:

    void solve(int index,
               vector<int>& candidates,
               vector<int>& temp,
               vector<vector<int>>& ans,
               int target)
    {
        // Base Case
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }

        // Target exceeded
        if(target < 0)
            return;

        // Try every number from current index
        for(int i = index; i < candidates.size(); i++)
        {
            // Take current number
            temp.push_back(candidates[i]);

            // Stay on same index because we can reuse the same number
            solve(i,
                  candidates,
                  temp,
                  ans,
                  target - candidates[i]);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, candidates, temp, ans, target);

        return ans;
    }
};