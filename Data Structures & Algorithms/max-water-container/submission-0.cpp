class Solution {
public:
    int maxArea(vector<int>& heights) {

        int maxVal = 0;
        int n = heights.size();
        int i = 0;
        int j = n - 1;
        int difference;

        while (i < j) {
            difference = abs(j - i);

            maxVal = max((difference * min(heights[i], heights[j])), maxVal);

            if (heights[i] <= heights[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxVal;
    }
};
