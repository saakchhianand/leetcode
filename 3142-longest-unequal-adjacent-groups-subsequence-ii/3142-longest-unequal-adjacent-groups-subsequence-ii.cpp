class Solution {
public:
    int hammingDistance(const string& a, const string& b) {
        int dist = 0;
        for (int i = 0; i < a.size(); ++i)
            dist += (a[i] != b[i]);
        return dist;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1); // Length of longest subsequence ending at i
        vector<int> parent(n, -1); // To reconstruct the path

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[j] != groups[i] &&
                    words[j].size() == words[i].size() &&
                    hammingDistance(words[j], words[i]) == 1) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
        }

        // Find the index of the last element in the longest sequence
        int max_len = 0, last_idx = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > max_len) {
                max_len = dp[i];
                last_idx = i;
            }
        }

        // Reconstruct the path
        vector<string> result;
        while (last_idx != -1) {
            result.push_back(words[last_idx]);
            last_idx = parent[last_idx];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
