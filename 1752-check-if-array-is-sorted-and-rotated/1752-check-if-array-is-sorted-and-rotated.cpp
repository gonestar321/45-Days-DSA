class Solution {
public:
    bool check(vector<int>& nums) {
    //     int n = nums.size();
    //  for( int i = 0 ; i < n ; i++ ){
    //     if (n <= 1) return 1;

    //     else if( nums[i+1] >= nums[i]){
    //         continue;
    //     }
    //     else{
    //         return false;
    //     }
    //  }
    //  return true;
//THIS WAS ONLY APPLICABLE TO THE IS SORTED PART
// FOR INCORPORATING THE IS ROTATED PART
// we'll do the following


       int n = nums.size();
        int break_points = 0;

        for (int i = 0; i < n; i++) {
            // Compare current element with the previous one
            if (nums[i] < nums[(i - 1 + n) % n]) { // Use modulo for circular indexing
                break_points++;
            }
        }

        // Check if last element is greater than the first (for rotation)
        return break_points <= 1;
        }
    
};