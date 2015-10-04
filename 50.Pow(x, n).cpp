/*
Implement pow(x, n).
*/

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        if(n < 0){
            return 1.0/pow(x,-n);
        }
        return x*pow(x,n - 1);
    }
};