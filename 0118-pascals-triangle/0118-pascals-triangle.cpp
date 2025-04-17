class Solution {
public:

    void nCr( int n , int r , vector<vector<int>>& triangle ){
        long long res = 1;

        for ( int i = 0 ; i < r ; i++){
            res = res*( n - i );
            res = res/(i + 1);

        }

        triangle[n].push_back(res);

        
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);

      for( int i = 0 ; i < numRows ; i++ ){
        for( int j = 0 ; j <= i ; j++ ){
                nCr(i , j , triangle);
        }
      }

      return triangle;
    }
};