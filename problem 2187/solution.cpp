#include <vector>
using namespace std;
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long minTime, maxTime, mid;
        minTime = 1;
        maxTime = 100000000000000L;
        long long tripsCompleted;
        while (minTime < maxTime) {
            mid = minTime + ((maxTime - minTime) / 2);
            tripsCompleted = 0;
            for (int t : time) {
                tripsCompleted += mid / t; // add number of trips completed by current bus in 'mid' time
                if (tripsCompleted >= totalTrips) break;
            }
            if (tripsCompleted >= totalTrips) {
                maxTime = mid;
            } else {
                minTime = mid + 1;
            }
        }

        return minTime;
    }
};