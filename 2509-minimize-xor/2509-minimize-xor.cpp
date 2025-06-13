class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = __builtin_popcount(num2); // Number of set bits required
        int result = 0;

        // First, try to set bits of result in positions where num1 has bits set (from MSB to LSB)
        for (int i = 31; i >= 0 && count > 0; --i) {
            if ((num1 >> i) & 1) {
                result |= (1 << i);
                count--;
            }
        }

        // If we still need to set more bits, set them from LSB upwards (where num1 has 0)
        for (int i = 0; i <= 31 && count > 0; ++i) {
            if (((num1 >> i) & 1) == 0) {
                result |= (1 << i);
                count--;
            }
        }

        return result;
    }
};
