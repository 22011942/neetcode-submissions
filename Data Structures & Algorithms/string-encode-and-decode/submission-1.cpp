class Solution {
public:

    string encode(vector<string>& strs) {

        string encoded = "";
        

        for (size_t i = 0; i < strs.size(); i++) {
            encoded += to_string(strs[i].length()) + "#";
            for (size_t j = 0; j < strs[i].length(); j++) {
                encoded += strs[i][j];
            }
        }

        return encoded;
    }

    vector<string> decode(string s) {
        
        std::vector<string> message;

        int i = 0;
        while (i < s.length()) {
            int pos = s.find('#', i);
            int length = stoi(s.substr(i, pos - i));
            i = pos + 1;
            message.push_back(s.substr(i, length));
            i += length;
        }

        return message;
    }
};