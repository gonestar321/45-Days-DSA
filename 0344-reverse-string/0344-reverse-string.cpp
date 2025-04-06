class Solution {
public:

    void swap(int a , int b , vector<char>& s){
        int c = s[a];
        s[a] = s[b];
        s[b] = c ;
    }

    // void reverseString(vector<char>& s) {
    //    //basic for loop se hua ye tohh
    //     int n = s.size();
    //     for( int i = 0 ; i < s.size() ; i++){
    //         if( i >= s.size()/2 ){ break ; }
    //         swap( i , n-i-1 , s);
    //     }
    // }

    void letsRev(vector<char>& s ,int i, int n){

        if( i >= n/2) return;

        swap( i , n-i-1 , s);
        letsRev( s , i+1 ,n);
    }

     void reverseString(vector<char>& s) {
        int n = s.size();
        
        letsRev( s , 0 , n );
     }
};