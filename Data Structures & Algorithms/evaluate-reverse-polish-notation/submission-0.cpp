class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> evaluator;
        int sum = 0;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] == "+" || 
                tokens[i] == "-" ||
                    tokens[i] == "*" ||
                        tokens[i] == "/"){
                            int op2 = stoi(evaluator.top());
                            evaluator.pop();
                            int op1 = stoi(evaluator.top());
                            evaluator.pop();
                            int val;
                            if(tokens[i] == "+"){
                                val = op1+op2;
                            }
                            else if(tokens[i] == "-"){
                                val = op1-op2;
                            }
                            else if(tokens[i] == "*"){
                                val = op1*op2;
                            }
                            else if(tokens[i] == "/"){
                                val = op1/op2;
                            }
                            evaluator.push(to_string(val));
                        }
            else {
                evaluator.push(tokens[i]);
            }
        }
        return stoi(evaluator.top());
    }
};
