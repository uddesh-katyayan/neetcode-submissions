class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string> S;
        if(operations.size()==0){
            return 0;
        }
        int score = 0;
        for(auto& ops: operations){
            if(ops == "+"){
                string a = S.top();
                S.pop();
                string b = S.top();
                S.push(a);
                S.push(to_string(stoi(a)+stoi(b)));
            } else if(ops == "D"){
                int a = stoi(S.top());
                S.push(to_string(2*a));
            } else if (ops == "C"){
                S.pop();
            } else{
                S.push(ops);
            }
        }
        while(!S.empty()){
            score += stoi(S.top());
            S.pop();
        }
        return score;
    }
};