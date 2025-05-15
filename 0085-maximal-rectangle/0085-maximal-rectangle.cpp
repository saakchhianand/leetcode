class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int maxArea = 0;
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);

        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col] == '1') {
                    heights[col] += 1;
                } else {
                    heights[col] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0); // Add a sentinel to flush the stack at the end
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            s.push(i);
        }

        heights.pop_back(); // Clean up the sentinel
        return maxArea;
    }
};
