class Solution {
public:
    void swap(int& a , int& b){
        int c = a;
        a = b;
        b= c;
    }
    void moveZeroes(vector<int>& nums) {
            int n = nums.size();


            for( int i =0 ; i< n ; ++i){

                if( nums[i] == 0 ){
                    for( int j = i ; j<n ; ++j){
                        if(nums[ j] != 0){
                            swap(nums[i], nums[j]);
                            break;
                        }
                    }
                }
            }
    }
};