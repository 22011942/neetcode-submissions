class Solution {
public:
    int trap(vector<int>& height) {
        
        int area = 0;
        int n = height.size();
        
        std::vector<int> prefix(n);
        std::vector<int> suffix(n);

        int max = 0;

        for (size_t indx = 0; indx < n; indx++) {
            if (height[indx] > max) {
                max = height[indx];
            }

            prefix[indx] = max;
        }

        max = 0;

        for (int indx = n - 1; indx >= 0; indx--) {
            if (height[indx] > max) {
                max = height[indx];
            }

            suffix[indx] = max;
        }

        for (size_t indx = 0; indx < n; indx++) {
            area += std::min(prefix[indx], suffix[indx]) - height[indx];
        }


        return area;
    }
};
