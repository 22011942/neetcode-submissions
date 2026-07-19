class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        std::vector<int> ans;
        
        int j = numbers.size() - 1;
        int i = 0;

        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                ans.push_back(++i);
                ans.push_back(++j);
                break;
            }

            if (numbers[i] + numbers[j] > target) {
                j--;
                continue;
            }

            if (numbers[i] + numbers[j] < target) {
                i++;
                continue;
            }
        }

        return ans;
    }
};
