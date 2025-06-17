class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        set<int> s;


        for( int i = 0 ; i < n ; i++ ){
            s.emplace(nums[i]);

        }
        
        if( s.size() < nums.size()) return true;
        else return false;
    }
};