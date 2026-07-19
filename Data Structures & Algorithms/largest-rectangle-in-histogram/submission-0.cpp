class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max = 0;

        std::stack<int> areas;

        for (int indx = 0; indx < heights.size(); indx++) {
            int val = heights[indx];
            int total = val;

            for (int i = indx + 1; i < heights.size(); i++) {
                if (heights[i] < val) {
                    break;
                } 

                total += val;
            }

            for (int j = indx - 1; j >= 0; j--) {
                if (heights[j] < val) {
                    break;
                }

                total += val;
            }

            if (max < total) {
                max = total;
            }
        }

        return max;
    }
};
