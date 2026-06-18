class Solution {
public:
    double angleClock(int hour, int minutes) {

        double org_dist = (hour % 12) * 5.0 - minutes;
        double diff = minutes / 12.0;

        double ans = abs(org_dist + diff) * 6.0;

        return min(ans, 360.0 - ans);
    }
};