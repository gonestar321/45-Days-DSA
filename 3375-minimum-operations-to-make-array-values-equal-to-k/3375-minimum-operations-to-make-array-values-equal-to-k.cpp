class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> unique;
        for (int num : nums) {
            if (num > k) {
                unique.insert(num);
            } else if (num < k) {
                // If there's any value < k, it's impossible to make all elements == k
                return -1;
            }
        }
        return unique.size(); // One op per unique value > k
    }
};
