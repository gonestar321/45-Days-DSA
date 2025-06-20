class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        //. O(Nlog(N)) approach
        
        // int n = nums.size();

        // set<int> s( nums.begin() , nums.end());

        // for( int i = 0 ; i <= n ; i++ ){

        //     if( s.find(i) == s.end()){
        //         return i ;
        //     }
        // }
        // return 0;

        // simpler approach. O n(log(n))

        sort( nums.begin() , nums.end() ); //O(n(log(n)))

        int n = nums.size();

        for( int i = 0 ; i < n ; i++ ){
            
            if( i < nums[i] ){
                return i ;
            }

            if( i == n-1 && i == nums[i]){
                return i + 1;
            }

        }

        return 0;


    }
};