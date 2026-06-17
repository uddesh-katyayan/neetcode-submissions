class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int small = 0;
        int large = n-1;
        int count = 0;
        sort(people.begin(), people.end());
        while(small<large){
            if(people[small]+people[large]<=limit){
                large--;
                small++;
            } else{
                large--;
            }
            count++;
        }
        if(small==large){
            count++;
        }
        return count;
    }
};