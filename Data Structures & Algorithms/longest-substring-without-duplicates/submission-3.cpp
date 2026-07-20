class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        std::set<char> chars;
        int anchor = 0;
        int length = 0;
        int size;

        for (int indx = 0; indx < s.size(); indx++) {
            if (chars.empty()) {
                chars.insert(s[indx]);
                anchor = indx;
                continue;
            }

            while (chars.contains(s[indx])) {
                chars.erase(s[anchor]);
                anchor++;
            }

            chars.insert(s[indx]);
            size = chars.size();

            length = std::max(length, size);
        }

        size = chars.size();

        length = std::max(length, size);

        return length;
    }
};
