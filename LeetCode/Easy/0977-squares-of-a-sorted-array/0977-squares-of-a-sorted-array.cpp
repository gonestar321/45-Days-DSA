class Solution {
public:
    void swap( int  i , int  j , vector<int>&nums ){
        int b = nums[i];
        nums[i] = nums[j];
        nums[j] = b;

    }
    vector<int> sortedSquares(vector<int>& nums) {

        for( int i = 0 ; i < nums.size() ; i++){
            nums[i] *= nums[i];
        }

        
        int start = 0;
        for( int i = 0; i < nums.size() ; i++){
            int last = nums.size() - 1 ;
            while( start < last ){
                
                if( nums[start] > nums[last]){
                    swap(start , last , nums);
                }
                last--;
            }
            
        }
        return nums;
    }
};