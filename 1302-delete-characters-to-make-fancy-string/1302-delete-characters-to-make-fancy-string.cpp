class Solution {
public:
    string makeFancyString(string s) {
        string res;
        int count = 0;
        char prev = '#'; // dummy

        for (char c : s) {
            if (c == prev) {
                count++;
            } else {
                count = 1;
                prev = c;
            }

            if (count <= 2) {
                res += c;
            }
        }
        return res;
    }
};
