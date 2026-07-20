class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        std::set<std::vector<int>> sets;

        std::ranges::sort(nums);

        int i, j;

        for (size_t indx = 0; indx < nums.size() - 2; indx++) {
            i = indx + 1;
            j = nums.size() - 1;

            while (i < j) {
                if (-nums[indx] == nums[i] + nums[j]) {
                    sets.insert({nums[indx], nums[i], nums[j]});
                    j--;
                    continue;
                }

                if (nums[i] + nums[j] < -nums[indx]) {
                    i++;
                    continue;
                }

                if (nums[i] + nums[j] > -nums[indx]) {
                    j--;
                }
            }
        }

        std::vector<std::vector<int>> ans;

        for (const auto & vec : sets) {
            ans.push_back(vec);
        }

        return ans;
    }
};
