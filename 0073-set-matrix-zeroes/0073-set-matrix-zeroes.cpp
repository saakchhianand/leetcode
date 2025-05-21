class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRow = false, firstCol = false;

        // Check if the first row should be zeroed
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                firstRow = true;
                break;
            }
        }

        // Check if the first column should be zeroed
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        }

        // Use first row and column as markers for rows and columns to be zeroed
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set matrix elements to 0 based on markers
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero the first row if needed
        if (firstRow) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }

        // Zero the first column if needed
        if (firstCol) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
