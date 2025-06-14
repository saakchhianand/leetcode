class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        // For maximum: replace first non-'9' digit with '9'
        string maxS = s;
        for (char ch : s) {
            if (ch != '9') {
                replace(maxS.begin(), maxS.end(), ch, '9');
                break;
            }
        }

        // For minimum: replace first digit that's not '0' with '0'
        string minS = s;
        for (char ch : s) {
            if (ch != '0') {
                replace(minS.begin(), minS.end(), ch, '0');
                break;
            }
        }

        int maxNum = stoi(maxS);
        int minNum = stoi(minS);

        return maxNum - minNum;
    }
};

