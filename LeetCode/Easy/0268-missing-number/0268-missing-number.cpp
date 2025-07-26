class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> s( nums.begin() , nums.end() );

        for( int i = 0 ; i <= n ; i++ ){
            auto it = s.find(i);
            if( it == s.end() ){
                return i ;
            }
        }
        return 0;
    }
};