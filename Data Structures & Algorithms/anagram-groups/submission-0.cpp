class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        if (strs.empty()) return {};
        if (strs.size() < 2) {
            return {{strs[0]}};
        }

        std::vector<vector<string>> groups;

        std::map<std::array<int, 26>, std::vector<string>> angrams;

        for (size_t i = 0; i < strs.size(); i++) {
            std::array<int, 26> letters;
            letters.fill(0);
            for (size_t j = 0; j < strs[i].length(); j++) {
                int pos = strs[i][j] - 'a';
                letters[pos]++;
            }
            angrams[letters].push_back(strs[i]);
        }

        for (auto const& [key, val] : angrams) {
            groups.push_back(val);
        }

        return groups;
    }
};
