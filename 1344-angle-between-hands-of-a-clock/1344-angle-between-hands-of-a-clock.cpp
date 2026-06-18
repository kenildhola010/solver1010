class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double minangle = 6.0 * minutes;
        double houra = 30.0*(hour%12) + 0.5 * minutes;
        double diff = abs(houra-minangle);

        return min(diff, 360.0-diff);
    }
};