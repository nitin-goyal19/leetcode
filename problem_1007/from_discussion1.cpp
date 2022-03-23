//https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/discuss/1865373/C%2B%2B-oror-2-Approaches-oror-Explained-With-Algorithm-oror-Easy-and-Simple
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int i;
        int minSwaps = INT_MAX;
        vector<int> topCount(7), bottomCount(7), same(7);
        int n = tops.size();
        for(i = 0; i < n; ++i){
            topCount[tops[i]]++;
            bottomCount[bottoms[i]]++;
            if(tops[i] == bottoms[i]){
                same[tops[i]]++;
            }
        }
        
        for(i = 1; i <= 6; ++i) {
            if(topCount[i] + bottomCount[i] - same[i] == n){
                minSwaps = min(minSwaps, min(topCount[i], bottomCount[i]) - same[i]);
            }
        }
        
        return minSwaps == INT_MAX ? -1 : minSwaps;
    }
};