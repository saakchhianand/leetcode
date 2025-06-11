class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);

        // Step 1: Count frequencies
        for (char c : s) {
            freq[c - 'a']++;
        }

        int maxDiff = INT_MIN;

        // Step 2: Try all odd/even frequency pairs
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 == 1) {  // a1 has odd frequency
                for (int j = 0; j < 26; ++j) {
                    if (freq[j] % 2 == 0 && freq[j] > 0) {  // a2 has even frequency
                        maxDiff = max(maxDiff, freq[i] - freq[j]);
                    }
                }
            }
        }

        return maxDiff;
    }
};
