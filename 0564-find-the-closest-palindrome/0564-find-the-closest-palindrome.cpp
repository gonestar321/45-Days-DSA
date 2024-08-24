class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        long long selfNumber = stoll(n);
        
        // Edge cases
        if (selfNumber == 1) return "0"; // Single digit edge case
        
        // Candidate set
        set<long long> candidates;
        
        // Case 1: 100...001 (e.g., 1000 -> 999, 100 -> 99)
        candidates.insert(pow(10, len) + 1); // 100...001
        candidates.insert(pow(10, len - 1) - 1); // 999...999

        // Case 2: Mirror the current number and handle +1 and -1 on the first half
        long long prefix = stoll(n.substr(0, (len + 1) / 2));
        
        vector<long long> variations = {prefix - 1, prefix, prefix + 1};
        for (long long var : variations) {
            string candidate = to_string(var);
            string mirrored = candidate + string(candidate.rbegin() + (len & 1), candidate.rend());
            candidates.insert(stoll(mirrored));
        }
        
        candidates.erase(selfNumber); // Remove the number itself from candidates
        
        // Find the closest candidate
        long long closest = -1;
        for (long long candidate : candidates) {
            if (closest == -1 ||
                abs(candidate - selfNumber) < abs(closest - selfNumber) ||
                (abs(candidate - selfNumber) == abs(closest - selfNumber) && candidate < closest)) {
                closest = candidate;
            }
        }
        
        return to_string(closest);
    }
};

