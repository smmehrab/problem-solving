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
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int numberOfAsteroids = asteroids.size();
        vector<int> remainingAsteroids;
        for(int i=0; i<numberOfAsteroids; i++){
            if(remainingAsteroids.empty() || asteroids[i]>0 || remainingAsteroids.back()<0)
                remainingAsteroids.push_back(asteroids[i]);
            else if(remainingAsteroids.back() <= -asteroids[i]){
                if(remainingAsteroids.back() < -asteroids[i]) i--;
                remainingAsteroids.pop_back();
            }
        }
        return remainingAsteroids;
    }
};