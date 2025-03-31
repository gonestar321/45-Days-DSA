class Solution {
public:
    double myPow(double x, int n) {

        double ans =1 ;
        long long pow = abs((long long)n);

        while(pow > 0){
            if( pow % 2 ==1 ){
                ans = ans * x;
                pow = pow-1;
            }
            else{
                pow = pow/2;
                x = x*x;
            }
            
        }
        if(n<0){
                ans = 1/ans;
            }
            return ans;


















        //brute approachh

        // double prod =1;

        // // when power is 0
        // if( n == 0){
        //     return prod;
        // }
        // else if ( n >=1){
        //     for( double i = 1 ; i<=n ; i++){
        //         prod = prod * x;
        //     }
        //     return prod;
        // }
        // else { // power is negative
        //     int poww = abs(n);
        //     double inverse = 1/x;

        //     for( int i = 1 ; i<= poww ; i++){
        //         prod = prod * inverse;
        //     }
        //     return prod;

        // }
    }
};