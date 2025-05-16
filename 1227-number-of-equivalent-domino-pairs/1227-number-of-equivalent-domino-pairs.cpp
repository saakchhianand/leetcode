class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> count;
        int result = 0;

        for (const auto& d : dominoes) {
            // Normalize the key: smaller value comes first
            int a = d[0], b = d[1];
            int key = min(a, b) * 10 + max(a, b); // Since 1 <= a,b <= 9, 10-based key is safe
            result += count[key];
            count[key]++;
        }

        return result;
    }
};
