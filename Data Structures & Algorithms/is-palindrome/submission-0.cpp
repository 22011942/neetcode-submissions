class Solution {
public:

    bool isPalindrome(string s) {

        int start = 0;
        int end = s.size() - 1;

        while (start <= end) {
            if (!std::isalnum(static_cast<unsigned char>(s[start]))) {
                start++;
                continue;
            }

            if (!std::isalnum(static_cast<unsigned char>(s[end]))) {
                end--;
                continue;
            }

            if ( static_cast<char>(std::tolower(s[start])) !=  static_cast<char>(std::tolower(s[end]))) {
                return false;
            }

            start++;
            end--;
        }
        
        return true;
    }
};
