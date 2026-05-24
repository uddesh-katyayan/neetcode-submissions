class Solution {
public:
    bool isHappy(int n) {
        set<int> squared_sums;
        int i = 0;
        while(true){
            int new_sum = sumOfSquareOfDigits(n);
            cout << new_sum <<endl;
            if(new_sum == 1){
                return true;
            }
            else{
                if(squared_sums.find(new_sum)!=squared_sums.end()){
                    return false;
                }
                else{
                    squared_sums.insert(new_sum);
                    n = new_sum;
                }
            }
        }
        return true;
    }
private: 
    int sumOfSquareOfDigits(int n){
        int sum = 0;
        int temp = n;
        while(n > 0){
            int dig = n%10;
            sum += dig*dig;
            n /= 10;
        }
        return sum;
    }
};
