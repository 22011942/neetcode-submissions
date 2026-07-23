class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }

        std::vector<int> first(26, 0);
        std::vector<int> second(26, 0);

        for (size_t indx = 0; indx < s1.size(); indx++) {
            first[s1[indx] - 'a']++;
            second[s2[indx] - 'a']++;
        }

        if (first == second) {
            return true;
        }

        int l;

        for (size_t r = s1.size(); r < s2.size(); r++) {

            second[s2[r] - 'a']++;

            l = r - s1.size();
            second[s2[l] - 'a']--;

            if (first == second) {
                return true;
            }
        }

        return false;
    }
};
