class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        std::vector<std::pair<int, int>> posSpeed;

        std::stack<double> fleets;

        for (size_t indx = 0; indx < position.size(); indx++) {
            posSpeed.push_back({position[indx], speed[indx]});
        }

        std::sort(posSpeed.begin(), posSpeed.end(), [](const auto& a, const auto& b){
           return a.first > b.first;
        });

        double time;

        for (size_t indx = 0; indx < position.size(); indx++) {
            time = (double)(target - posSpeed[indx].first) / posSpeed[indx].second;

            if (fleets.empty()) {
                fleets.push(time);
                continue;
            }

            if (time > fleets.top()) {
                fleets.push(time);
            }
            
        }

        return fleets.size();
    }
};
