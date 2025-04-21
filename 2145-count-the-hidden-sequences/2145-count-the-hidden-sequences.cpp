class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long prefix = 0;
        long long minPrefix = 0;
        long long maxPrefix = 0;

        for (int diff : differences) {
            prefix += diff;
            minPrefix = min(minPrefix, prefix);
            maxPrefix = max(maxPrefix, prefix);
        }

        long long minX = lower - minPrefix;
        long long maxX = upper - maxPrefix;

        return max(0LL, maxX - minX + 1);
    }
};
