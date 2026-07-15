class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        std::stack<std::pair<int, int>> tempPositions;

        std::vector<int> temps(temperatures.size(), 0);

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

                    temps[valIndice] = difference;
                    tempPositions.pop();
                }

            }

        }

        return temps;
    }
};
