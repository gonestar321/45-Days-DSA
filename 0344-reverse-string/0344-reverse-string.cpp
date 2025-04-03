class Solution {
public:

    void swap(int a , int b , vector<char>& s){
        int c = s[a];
        s[a] = s[b];
        s[b] = c ;
    }

    void reverseString(vector<char>& s) {
        //recursion se krte hain
        int n = s.size();
        for( int i = 0 ; i < s.size() ; i++){
            if( i >= s.size()/2 ){ break ; }
            swap( i , n-i-1 , s);
        }
    }
};