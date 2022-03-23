class Solution {
public:
    vector<int> partitionLabels(string s) {
        if(s.size() == 1){
            return vector<int>(1, 1);
        }else if(s[0] == 2 && s[0] != s[1]){
            return vector<int>(2, 1);
        } else if(s[0] == s[s.size() - 1]){
            return vector<int>(1, s.size());
        }
        
        int lastIndex[26]{-1};
        int stringLength = s.size();
        int i;
        vector<int> result;
        for(i = 0; i < stringLength; ++i) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        int start, end;
        start = end = 0;
        for(i = 0; i < stringLength; ++i){
            end = max(end, lastIndex[s[i] - 'a']);
            if(i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        
        return result;
    }
};