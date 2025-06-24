class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int n = nums.size();
        
        // First, store all indices where nums[i] == key
        vector<int> keyIndices;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                keyIndices.push_back(i);
            }
        }

        // Now, for each index i in the array, check if it's within k distance of any key index
        for (int i = 0; i < n; ++i) {
            for (int j : keyIndices) {
                if (abs(i - j) <= k) {
                    result.push_back(i);
                    break; // Don't need to check further for this i
                }
            }
        }

        return result;
    }
};
