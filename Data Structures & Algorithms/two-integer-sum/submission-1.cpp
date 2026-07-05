class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        if (nums.size() < 2) {
            return {0, 1};
        }

        std::vector<pair<int, int>> values;

        for (int indx = 0; indx < nums.size(); indx++) {
            values.push_back({nums[indx], indx});
        }
        
        std::ranges::sort(values);

        int startPointer = 0;
        int endPointer = nums.size() - 1; 

        while (startPointer < endPointer) {

            if (values[startPointer].first + values[endPointer].first == target) {
                return {min(values[startPointer].second, values[endPointer].second), max(values[startPointer].second, values[endPointer].second)};
            } else if (values[startPointer].first + values[endPointer].first < target) {
                startPointer++;
            } else {
                endPointer--;
            }
        }

        return {};
    }
};
