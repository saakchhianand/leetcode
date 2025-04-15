#include <vector>
using namespace std;

class BIT {
public:
    vector<int> tree;
    int size;

    BIT(int n) {
        size = n + 2;
        tree.resize(size, 0);
    }

    void update(int index, int val) {
        index++;  // 1-based indexing
        while (index < size) {
            tree[index] += val;
            index += index & -index;
        }
    }

    int query(int index) {
        index++;  // 1-based indexing
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n);
        for (int i = 0; i < n; ++i)
            pos[nums2[i]] = i;

        vector<int> mapped(n);
        for (int i = 0; i < n; ++i)
            mapped[i] = pos[nums1[i]];

        BIT bitLeft(n), bitRight(n);
        vector<int> rightCount(n, 0);

        for (int i = n - 1; i >= 0; --i) {
            rightCount[i] = bitRight.query(n - 1) - bitRight.query(mapped[i]);
            bitRight.update(mapped[i], 1);
        }

        long long result = 0;
        for (int i = 0; i < n; ++i) {
            int left = bitLeft.query(mapped[i] - 1);
            int right = rightCount[i];
            result += (long long)left * right;
            bitLeft.update(mapped[i], 1);
        }

        return result;
    }
};
