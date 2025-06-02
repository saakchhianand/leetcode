class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q; // {square, moves}
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [s, moves] = q.front();
            q.pop();
            if (s == n * n) return moves;

            for (int i = 1; i <= 6 && s + i <= n * n; ++i) {
                int next = s + i;
                auto [r, c] = getCoordinates(next, n);
                if (board[r][c] != -1) {
                    next = board[r][c];
                }
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }

private:
    pair<int, int> getCoordinates(int s, int n) {
        int row = n - 1 - (s - 1) / n;
        int col = (s - 1) % n;
        if ((n - 1 - row) % 2 == 1) {
            col = n - 1 - col;
        }
        return {row, col};
    }
};
