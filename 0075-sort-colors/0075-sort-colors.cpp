class Solution {
public:
    void sortColors(vector<int>& nums) {

        // red -0 white -1 blue -2
        int low= 0 , mid = 0 , high = nums.size()-1;

        while( mid<= high){
            switch(nums[mid]){

                case 0 :
                    swap(nums[mid++] , nums[low++]);
                    break;
                
                case 1 :
                    mid++;
                    break;

                case 2 : 
                    swap(nums[mid] , nums[high--]);
                    break;
            }

        }

        
        }
        void inline swap(int& a , int& b){
                
                int temp = b;
                b=a;
                a = temp;
    }
};