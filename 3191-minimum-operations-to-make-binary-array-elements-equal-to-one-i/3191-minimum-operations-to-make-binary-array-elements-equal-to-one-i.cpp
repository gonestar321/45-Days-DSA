#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;

        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {
                // Flip the next three elements
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                operations++;
            }
        }

        // Check if any zero remains
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) return -1;
        }

        return operations;
    }
};
