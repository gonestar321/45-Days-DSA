class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin() , s.end());
        // sort(t.begin() , t.end());


        // return s == t;
        // THIS WAS THE O(log(n)) TC solution

        // let's do the hashmap- frequency method that takes O(n) TC 
        
        unordered_map< char , int > umap;

        if(s.size() != t.size()){
            return 0 ;
        }

        for( int i = 0 ; i < s.size() ; i++ ){
            char x = s[i];

            umap[x]++;
        }


        for( int i = 0 ; i < t.size() ; i++ ){
            char x = t[i];

            if(umap.count(x)){

                umap[x]--;

            }else{
                return 0;
            }

        }
        

        for (auto pair : umap) {
            if (pair.second != 0) {
                return 0;
            }
        }
    
    return 1;





    }
};