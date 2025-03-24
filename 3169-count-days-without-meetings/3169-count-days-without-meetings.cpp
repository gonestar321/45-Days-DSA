#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) {
            return days;
        }
        
        // Sort meetings based on start time
        sort(meetings.begin(), meetings.end());
        
        // Merge overlapping or adjacent intervals
        vector<vector<int>> merged;
        for (const auto& meeting : meetings) {
            if (merged.empty() || meeting[0] > merged.back()[1] + 1) {
                merged.push_back(meeting);
            } else {
                merged.back()[1] = max(merged.back()[1], meeting[1]);
            }
        }
        
        // Calculate total busy days
        int busyDays = 0;
        for (const auto& interval : merged) {
            busyDays += interval[1] - interval[0] + 1;
        }
        
        // Free days are total days minus busy days
        return max(days - busyDays, 0);
    }
};