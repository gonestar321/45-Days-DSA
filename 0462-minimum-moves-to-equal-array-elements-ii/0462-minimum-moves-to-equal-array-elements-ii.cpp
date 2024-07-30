class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size= nums.size();
         int mid = size/2;

         long long int steps = 0 ;
         for( int i =0 ; i< size ; ++i){
            long long int diff = 0;
            diff = abs(nums[mid] - nums[i]);
            steps += diff;
         }
         return steps;

    }
};