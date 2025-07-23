class Solution {
public:
    int findLucky(vector<int>& arr) {
        // lucky integer = which has frequency equal to it's value

        unordered_map<int,int> freq;

        for( int i = 0 ; i < arr.size() ; i++ ){
            freq[arr[i]]++;
        }
    
    int largest = -1;
        for( auto it = freq.begin() ; it != freq.end() ; it++ ){
            
            if( it->first == it->second && it->first > largest ){
                largest = it->first;
            }

        }
        return largest;
    }
};