class Solution {
// attempt1 : need to give more time on this.
public:
    double angleClock(int hour, int minutes) {
        double secondHand = minutes/5;
        double firstHand = (minutes==60)?hour:(hour==12?1:hour+1);
        double hour1 = abs(firstHand-secondHand) * 30;
        return (minutes/60) + hour1;
    }
};


class Solution {
//worked till 7 test cases
public:
    double angleClock(int hour, int minutes) {
        double secondHand = minutes/5;
        if(secondHand == hour){
            return ((double)minutes/60)*30;
        }
        double firstHand = (minutes==60)?hour:(hour==12?1:hour+1);
        double hour1 = abs(secondHand-firstHand) * 30;
        double res = (double)minutes/60;
        return hour1+res*30;
    }
};


class Solution {
public:
    double angleClock(int hour, int minutes) {
        float h = (hour%12 + (float)minutes/60) * 30; // 360/12
        float min = minutes*6;

        float angle = fabs(h-min);

        if(angle > 180){
            angle = 360 - angle;
        }
        return angle;
    }
};
