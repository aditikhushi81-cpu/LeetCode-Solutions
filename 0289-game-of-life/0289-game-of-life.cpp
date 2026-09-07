class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int rows = board.size();
        int cols = board[0].size();

        int directions[8][2] = {
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0, -1},
            {0, 1},
            {1, -1},
            {1, 0},
            {1, 1}
        };

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                int alive = 0;

                // Check 8 neighbors
                for (auto& dir : directions) {

                    int ni = i + dir[0];
                    int nj = j + dir[1];

                    if (ni >= 0 && ni < rows &&
                        nj >= 0 && nj < cols) {

                        if (board[ni][nj] == 1 ||
                            board[ni][nj] == 2) {
                            alive++;
                        }
                    }
                }

                // Alive cell
                if (board[i][j] == 1) {

                    if (alive < 2 || alive > 3) {
                        board[i][j] = 2;
                    }
                }

                // Dead cell
                else if (board[i][j] == 0) {

                    if (alive == 3) {
                        board[i][j] = 3;
                    }
                }
            }
        }

        // Convert temporary values
        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                if (board[i][j] == 2) {
                    board[i][j] = 0;
                }
                else if (board[i][j] == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};