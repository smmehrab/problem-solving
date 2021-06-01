/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
class Solution {
private:
    double radius, x_center, y_center;

    double random() {
        return (double) rand()/RAND_MAX;
    }
    
public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
        
        srand(time(0));
    }
    
    vector<double> randPoint() {
        vector<double> point(2);
        double r = sqrt(random()) * radius;
        double theta = 2 * M_PI * random();
        point[0] = x_center + (r*cos(theta));
        point[1] = y_center + (r*sin(theta));
        return point;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */