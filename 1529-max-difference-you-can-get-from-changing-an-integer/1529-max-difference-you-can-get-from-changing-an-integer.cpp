class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        
        // MAX: Replace first digit not 9 with 9
        string maxS = s;
        for (char c : s) {
            if (c != '9') {
                char from = c;
                for (char &ch : maxS) {
                    if (ch == from) ch = '9';
                }
                break;
            }
        }
        
        // MIN: Replace first digit with 1 or any digit (except leading zero)
        string minS = s;
        if (s[0] != '1') {
            char from = s[0];
            for (char &ch : minS) {
                if (ch == from) ch = '1';
            }
        } else {
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    char from = s[i];
                    for (int j = 0; j < s.size(); ++j) {
                        if (minS[j] == from) minS[j] = '0';
                    }
                    break;
                }
            }
        }

        int a = stoi(maxS);
        int b = stoi(minS);
        return a - b;
    }
};
