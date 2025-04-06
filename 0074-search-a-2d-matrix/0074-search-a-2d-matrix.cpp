class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0 , right = rows*cols - 1;

        int mid = right + ( left-right )/2 ;

        while( left <= right ){
            int mid = left + (right-left)/2;
            
            int midValue = matrix[mid / cols][mid % cols];

            if( midValue == target ){
                return true;
            }

            else if ( target < midValue ){
                right = mid -1;
            }
            else if( target > midValue ){
                left = mid + 1;
            }

        }

        return false;


    }
};