class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int rows = mat.size();
        int cols = mat[0].size();

        vector<int> ans;

        for (int d = 0; d < rows + cols - 1; d++) {

            vector<int> diagonal;

            // Find all elements belonging to this diagonal
            for (int i = 0; i < rows; i++) {

                int j = d - i;

                if (j >= 0 && j < cols) {
                    diagonal.push_back(mat[i][j]);
                }
            }

            // Alternate direction
            if (d % 2 == 0) {
                reverse(diagonal.begin(), diagonal.end());
            }

            for (int num : diagonal) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};