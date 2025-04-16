class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        // Step 1: Map value to index in nums2
        vector<int> posInNums2(n);
        for (int i = 0; i < n; ++i)
            posInNums2[nums2[i]] = i;
        
        // Step 2: Map nums1 into the positions array from nums2
        vector<int> mapped(n);
        for (int i = 0; i < n; ++i)
            mapped[i] = posInNums2[nums1[i]];

        // Step 3: Count of increasing pairs to the left of current index
        vector<int> BIT(n + 2, 0);

        auto update = [&](int i, int val) {
            for (++i; i <= n + 1; i += i & -i)
                BIT[i] += val;
        };

        auto query = [&](int i) {
            int res = 0;
            for (++i; i > 0; i -= i & -i)
                res += BIT[i];
            return res;
        };

        vector<int> leftCount(n);  // Number of elements less than current on the left
        for (int i = 0; i < n; ++i) {
            leftCount[i] = query(mapped[i] - 1);
            update(mapped[i], 1);
        }

        // Reset BIT for right side count
        fill(BIT.begin(), BIT.end(), 0);

        long long res = 0;
        for (int i = n - 1; i >= 0; --i) {
            int right = query(n) - query(mapped[i]);
            res += (long long)leftCount[i] * right;
            update(mapped[i], 1);
        }

        return res;
    }
};
