#include <algorithm>
#include <cmath> // For ceil function
class Solution {
public:

    bool checkformid(vector<int>& piles , int mid , int h){
            int hour_to_eat = 0;
            for( int i=0; i<piles.size(); i++){
                 hour_to_eat += (piles[i] + mid - 1) / mid;
                if(hour_to_eat <= h){
      
                }else{return false;}
            }
            return true;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1;
        int high = *max_element(piles.begin(),piles.end());
        
        while( low <= high){
            int mid = low +(high-low)/2;

            if(checkformid(piles, mid , h)) {
                high = mid-1;
            }
            else{low = mid+1;}
        }
        return low;
    }
};