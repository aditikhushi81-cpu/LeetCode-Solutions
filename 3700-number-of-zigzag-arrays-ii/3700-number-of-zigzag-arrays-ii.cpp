class Solution {
public:
    static const long long MOD = 1000000007;

    // Matrix multiplication
    vector<vector<long long>> multiply(
        vector<vector<long long>>& A,
        vector<vector<long long>>& B
    ) {
        int n = A.size();

        vector<vector<long long>> C(
            n, vector<long long>(n, 0)
        );

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {

                if (A[i][k] == 0)
                    continue;

                for (int j = 0; j < n; j++) {

                    if (B[k][j] == 0)
                        continue;

                    C[i][j] = (
                        C[i][j] +
                        A[i][k] * B[k][j]
                    ) % MOD;
                }
            }
        }

        return C;
    }

    // Matrix exponentiation
    vector<vector<long long>> power(
        vector<vector<long long>> A,
        long long p
    ) {
        int n = A.size();

        // Identity matrix
        vector<vector<long long>> result(
            n, vector<long long>(n, 0)
        );

        for (int i = 0; i < n; i++) {
            result[i][i] = 1;
        }

        while (p > 0) {

            if (p & 1) {
                result = multiply(result, A);
            }

            A = multiply(A, A);

            p >>= 1;
        }

        return result;
    }

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        // U[i][j] = 1 if j < i
        vector<vector<long long>> U(
            m, vector<long long>(m, 0)
        );

        // D[i][j] = 1 if j > i
        vector<vector<long long>> D(
            m, vector<long long>(m, 0)
        );

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < i; j++) {
                U[i][j] = 1;
            }

            for (int j = i + 1; j < m; j++) {
                D[i][j] = 1;
            }
        }

        // Two steps: increasing -> decreasing
        vector<vector<long long>> UD =
            multiply(U, D);

        // We already consider the first element
        n--;

        // Apply two steps at a time
        vector<vector<long long>> mat =
            power(UD, n / 2);

        // If one step remains
        if (n & 1) {
            mat = multiply(mat, U);
        }

        long long answer = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                answer = (
                    answer + mat[i][j]
                ) % MOD;
            }
        }

        // Two possibilities:
        // starts increasing OR starts decreasing
        answer = (answer * 2) % MOD;

        return answer;
    }
};