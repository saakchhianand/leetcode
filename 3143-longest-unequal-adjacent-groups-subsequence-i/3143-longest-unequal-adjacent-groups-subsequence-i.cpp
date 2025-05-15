class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        if (words.empty()) return result;

        result.push_back(words[0]);          // Start with the first word
        int lastGroup = groups[0];           // Remember its group

        for (int i = 1; i < words.size(); ++i) {
            if (groups[i] != lastGroup) {
                result.push_back(words[i]);  // Add word if group differs from last
                lastGroup = groups[i];       // Update lastGroup
            }
        }

        return result;
    }
};
