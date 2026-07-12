class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        std::vector<int> prefix;
        std::vector<int> suffix;

        std::vector<int> result;

        int n = nums.size();

        int j = n - 1;

        int prefixTot = 1;
        int suffixTot = 1;

        for (int indx = 0; indx < n - 1; indx++) {

            prefix.push_back(prefixTot);
            suffix.push_back(suffixTot);

            prefixTot *= nums[indx];
            suffixTot *= nums[j];

            j--;
        }

        prefix.push_back(prefixTot);
        suffix.push_back(suffixTot);

        j = n - 1;

        for (size_t indx = 0; indx < n; indx++) {
            int ans = prefix[indx] * suffix[j];

            j--;

            result.push_back(ans);
        }

        return result;
    } 
};
