class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0 ,  ten = 0; 

        for( int bill : bills){
            if(bill == 5){
                five++;
            }else if( bill == 10){
                if(five == 0) return false;
                five -- ;
                ten++;
            }else{ // 20 dollar bill
                if( ten >=1 && five >=1){
                    ten--;
                    five--;
                }
                else if(five >= 3){
                    five = five - 3;
                }
                else{ return false;}
            }
        }
        return true;
    }
};