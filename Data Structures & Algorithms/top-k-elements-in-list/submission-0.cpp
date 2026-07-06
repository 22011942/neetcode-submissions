
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;

        std::ranges::sort(nums);

        int total = 0;

        for (size_t indx = 0; indx < nums.size() - 1; indx++) {
            total++;
            if (nums[indx] != nums[indx + 1]) {
                minHeap.push({total, nums[indx]});
                total = 0;
            }
        }

        total++;
        minHeap.push({total, nums[nums.size() - 1]});

        while (minHeap.size() != k) {
            minHeap.pop();
        }

        std::vector<int> frequent;

        for (int indx = 0; indx < k; indx++) {
            frequent.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return frequent;
    }
};
