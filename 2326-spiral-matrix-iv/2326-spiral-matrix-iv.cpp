class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (head != NULL && top <= bottom && left <= right) {

            // Move right
            for (int j = left; j <= right && head != NULL; j++) {
                ans[top][j] = head->val;
                head = head->next;
            }
            top++;

            // Move down
            for (int i = top; i <= bottom && head != NULL; i++) {
                ans[i][right] = head->val;
                head = head->next;
            }
            right--;

            // Move left
            for (int j = right; j >= left && top <= bottom && head != NULL; j--) {
                ans[bottom][j] = head->val;
                head = head->next;
            }
            bottom--;

            // Move up
            for (int i = bottom; i >= top && left <= right && head != NULL; i--) {
                ans[i][left] = head->val;
                head = head->next;
            }
            left++;
        }

        return ans;
    }
};