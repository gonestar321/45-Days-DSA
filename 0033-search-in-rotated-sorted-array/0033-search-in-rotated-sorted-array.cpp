class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int upp = n-1;

        while( low <= upp ){
            // check for middle
            
            // compare target with middle 
            // compare target with low
            // if target is less than low
            // low = mid+1;
            // if target is greater than low
            // right = mid - 1;

            int mid = low + (upp - low)/2;

            if( nums[mid] == target){
                return mid;
            }
            // if( nums[mid] > nums[low]){
            //     if(target < nums[low]){
            //         low = mid ;
            //     }else{
            //         upp = mid -1;
            //     }
            // }else{
            //     low = mid + 1;
            // }

            //When mid is in left sorted part 
            if( nums[mid] >= nums[low]){
                
                if(target >= nums[low] && target < nums[mid]){
                    
                     upp = mid -1;

                }else{
                    low = mid + 1;  
                }
            }
            else{
                // when mid is in right sorted part
                if( target > nums[mid] && target <= nums[upp]){
                        low = mid +1;
                }else{
                    // when target > nums[ mid] && target > nums[upp]
                    upp = mid-1;
                }
            }
        }
        return -1;
    }
};