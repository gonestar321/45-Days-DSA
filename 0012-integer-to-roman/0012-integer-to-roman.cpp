class Solution {
public:
    string intToRoman(int num) {
        
        unordered_map<int , string> romanMap{
            { 1000, "M"},
            { 900, "CM"},
            {500, "D"}, {400, "CD"}, 
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, 
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}

        };

        vector<int> values;

        for( const auto&pair :romanMap){
            values.push_back(pair.first);
        }

        sort(values.rbegin() , values.rend());

        string result ="";
        //iterate through the sorted keys

        for(int value : values){
            while(num >= value){
                result += romanMap[value];
                num -=value;
            }
        }
        return result;

    }
};