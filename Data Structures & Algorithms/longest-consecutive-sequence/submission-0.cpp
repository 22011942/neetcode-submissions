class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        std::ranges::sort(nums);

        std::set<int> vals;

        for (const auto & num : nums) {
            vals.insert(num);
        }

        int countOld = 0;
        int countNew = 0;

        int prev = 0;

        for (const auto & val : vals) {

            if (val > prev + 1) {
                countOld = max(countNew, countOld);

                countNew = 0;
            }

            countNew++;

            prev = val;
        }

        countOld = max(countNew, countOld);

        return countOld;
    } 
};
