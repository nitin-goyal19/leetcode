class Solution {
    
public:
    string getSmallestString(int n, int k) {
        char* characters = "abcdefghijklmnopqrstuvwxyz";
        if(n == 1) {
            return string(1,characters[k-1]);
        }
        
        // string result;
        // result.resize(n);
        char* result = new char[n];
        int pos;
        for(int i = n; i > 0; --i){
            pos = k - (i - 1);
            if(pos > 26){
                result[i-1] = 'z';
                k = k - 26;
            } else {
                result[i-1] = characters[pos - 1];
                k = k - pos;
            }
            
        }
        
        return string(result);
    }
};