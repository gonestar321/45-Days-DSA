// class Solution {
// public:
//     int smallestDivisor(vector<int>& nums, int threshold) {
        
//         sort(nums.begin() , nums.end());

//         int low = 0;

//         int n = nums.size();
//         if (n > threshold) return -1;

//         int  high = *max_element(nums.begin(), nums.end());

//         int ans = -1;
        

//         while( low <= high){
            
//             int mid = low + (high-low)/2;

//             if(sumofdiv(nums , mid) <= threshold){
//                     ans = mid;
//                     high = mid-1;
//             }else{
//                 low = mid+1;
//             }
        
            
            
//         }
//         return ans;
//     }

//     int sumofdiv(vector<int>& arr , int divisor ){
//          double sum = 0;
//         for( int i = 0 ; i< arr.size() ; i++){
//             sum += ceil((double)(arr[i]) / (double)(divisor));
//         }
//         return sum;
//     }
// };

#include <vector>
#include <algorithm>
#include <cmath>  // for ceil

using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // Define the search range
        int low = 1;  // smallest possible divisor is 1
        int high = *max_element(nums.begin(), nums.end());  // largest possible divisor
        int ans = -1;

        // Perform binary search
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Calculate the sum using the current divisor
            if (sumofdiv(nums, mid) <= threshold) {
                ans = mid;  // update answer
                high = mid - 1;  // search for a smaller divisor
            } else {
                low = mid + 1;  // search for a larger divisor
            }
        }
        return ans;
    }

private:
    // Helper function to calculate the sum of divisions with ceiling
    int sumofdiv(const vector<int>& arr, int divisor) {
        int sum = 0;
        for (int num : arr) {
            sum += ceil(static_cast<double>(num) / divisor);
        }
        return sum;
    }
};
