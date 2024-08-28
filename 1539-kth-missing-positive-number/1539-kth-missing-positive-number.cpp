#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Modified method to take 'arr' as a parameter
    int findKthPositive(vector<int>& arr, int k) {
//         vector<int> newarr;

//         // Find maximum and minimum elements
//         int maxele = *max_element(arr.begin(), arr.end());

//         // Collect positive integers not in arr up to maxele
//         for (int i = 1; i <= maxele; ++i) {
//             if (notfound(arr, i)) {
//                 newarr.push_back(i);
//             }
//         }

//         // Continue collecting elements beyond maxele if necessary
//         int current = maxele + 1;
//         while (newarr.size() < k) {
//             if (notfound(arr, current)) {
//                 newarr.push_back(current);
//             }
//             ++current;
//         }

//         // Return the k-th missing positive number
//         return newarr[k - 1];
//     }

// private:
//     bool notfound(const vector<int>& arr, int target) {
//         auto it = find(arr.begin(), arr.end(), target);
//         return it == arr.end();

//Optimal Approach

        int n = arr.size();
        int low = 0;
        int high = n-1;


        while( low<=high){

            int mid =  (high+low)/2;
            int miss_ele = arr[mid] - (mid+1);

            if(miss_ele < k){
                low = mid+1;

            }else{
                high = mid-1;
            }
        }
        return (k + high +1);
    }
};
