class Solution {
    const unsigned int M = 1000000007;
public:
    int countOrders(int n) {
        if(n == 1){
            return 1;
        }
        long count = countOrders(n-1)%M;
        count = (count * n * (2 * n - 1))%M;
 //       return (((countOrders(n-1)%M) * ((n*(2*n-1))))%M);
        return count;
    }
};

/*
count(n+1) = count(n) * (2 * n + 1 + 2*n + .... + 1)

*/