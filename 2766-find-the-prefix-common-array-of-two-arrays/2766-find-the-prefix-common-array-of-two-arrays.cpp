class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_set<int> seenA, seenB, counted;
        vector<int> C(n);
        int count = 0;

        for (int i = 0; i < n; ++i) {
            seenA.insert(A[i]);
            seenB.insert(B[i]);

            if (seenB.count(A[i]) && !counted.count(A[i])) {
                count++;
                counted.insert(A[i]);
            }

            if (seenA.count(B[i]) && !counted.count(B[i])) {
                count++;
                counted.insert(B[i]);
            }

            C[i] = count;
        }

        return C;
    }
};
