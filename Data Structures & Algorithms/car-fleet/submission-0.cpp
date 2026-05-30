class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pos_speed;
        for(int i=0;i<position.size();i++){
            pos_speed.push_back(make_pair(position[i], speed[i]));;
        }
        sort(pos_speed.begin(), pos_speed.end());
        int n = position.size();
        int fleets = 0;
        double cur_duration = 0;
        for(int i=n-1;i>=0;i--){
            int cur_pos = pos_speed[i].first;
            int cur_speed = pos_speed[i].second;
            double duration = ((target - cur_pos) * 1.0) / cur_speed;
            if(duration > cur_duration){
                fleets++;
                cur_duration = duration;
            }
        }
        return fleets;
    }
};
