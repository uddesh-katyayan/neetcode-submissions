class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> max_heap;
        unordered_map<char, int> freq;
        for(char& ch: s){
            freq[ch]++;
        }
        for(auto& [ch, fr]: freq){
            max_heap.push({fr, ch});
        }
        string ans = "";
        char last_char;
        int last_freq = 0;
        while(!max_heap.empty()){
            auto [fr, ch] = max_heap.top();
            cout << fr <<" " << ch << endl;
            max_heap.pop();
            ans += ch;
            cout << ans << endl;
            if(last_freq>0){
                cout << "pushing: " << last_freq << " " << last_char << endl;
                max_heap.push({last_freq, last_char});
            }
            if(fr-1>0){
                last_freq = fr-1;
                last_char = ch;
            } else{
                last_freq = 0;
            }
        }
        if(last_freq == 0){
            return ans;
        }
        return "";
    }
};