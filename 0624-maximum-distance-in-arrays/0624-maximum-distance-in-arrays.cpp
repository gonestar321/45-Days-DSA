
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minVal = arrays[0].front();  // Initialize to the first element of the first array
        int maxVal = arrays[0].back();   // Initialize to the last element of the first array
        int maxDistance = 0;
        
        for (int i = 1; i < arrays.size(); ++i) {
            // Compare and calculate distance
            maxDistance = max(maxDistance, max(abs(arrays[i].back() - minVal), abs(maxVal - arrays[i].front())));
            
            // Update min and max values
            minVal = min(minVal, arrays[i].front());
            maxVal = max(maxVal, arrays[i].back());
        }
        
        return maxDistance;
    }
};