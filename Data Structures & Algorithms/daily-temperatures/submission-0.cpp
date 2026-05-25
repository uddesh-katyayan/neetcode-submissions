class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        // stack stores pair of temp, index
        stack<pair<int, int>> st;
        vector<int> res(temps.size(),0);
        for(int i=0;i<temps.size();i++){
            int current_temp = temps[i];
            while(!st.empty()){
                if(st.top().first < current_temp){
                    int ind = st.top().second;
                    st.pop();
                    res[ind] = i - ind;
                }
                else{
                    break;
                }
            }
            st.push(make_pair(current_temp, i));
        }
        return res;
    }
};
