#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        int n = nums.size();

        while (true) {
            unordered_set<int> seen;
            bool hasDuplicate = false;

            for (int num : nums) {
                if (seen.count(num)) {
                    hasDuplicate = true;
                    break;
                }
                seen.insert(num);
            }
            if (!hasDuplicate) break;

            // Perform the operation - remove first 3 elements (or all if < 3)
            int toRemove = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + toRemove);
            ops++;
        }

        return ops;
    }
};
