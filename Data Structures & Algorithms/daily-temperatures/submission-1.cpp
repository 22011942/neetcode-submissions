class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        std::stack<std::pair<int, int>> tempPositions;

        for (int indx = 0; indx < temperatures.size() - 1; indx++) {

            if (temperatures[indx] >= temperatures[indx + 1]) {
                tempPositions.push({indx, temperatures[indx]});
            } else {
                tempPositions.push({indx, temperatures[indx]});

                while (!tempPositions.empty()) {

                    if (tempPositions.top().second >= temperatures[indx + 1]) {
                        break;
                    }

                    int valIndice = tempPositions.top().first;
                    int difference = (indx + 1) - valIndice;

                    temperatures[valIndice] = difference;
                    tempPositions.pop();
                }

            }

        }

        while (!tempPositions.empty()) {
            int indx = tempPositions.top().first;

            temperatures[indx] = 0;
            tempPositions.pop();
        }

        temperatures[temperatures.size() - 1] = 0;

        return temperatures;
    }
};
