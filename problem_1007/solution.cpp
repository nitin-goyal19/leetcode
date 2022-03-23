class Solution {
    const int INF = 20001;
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int i, j;
        int distinctTops, distinctBottoms;
        int minSwaps = INF;
        for(i = 1; i <= 6; ++i){
            distinctTops = distinctBottoms = 0;
            for(j = 0; j < tops.size(); ++j) {
                if(tops[j] != i && bottoms[j] != i){
                    distinctTops = distinctBottoms = -1;
                    break;
                } else if(tops[j] == bottoms[j]){
                    continue;
                } else if(tops[j] == i){
                    distinctTops++;
                }else{
                    distinctBottoms++;
                }
                
            }
            if(distinctTops != -1){
                minSwaps = min(minSwaps, min(distinctTops, distinctBottoms));
            }
        }
        
        if(minSwaps == INF){
            return -1;
        }
        
        return minSwaps;
    }
};