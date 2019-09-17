class Solution {
public:
    double myPow(double x, long long n) {
        if(n == 0){
            return 1.0;
        }
        if ( n == -1){
            return 1.0/x;
        }
        double ans = myPow(x, n/2);
        int np = abs(n);
        if(np%2 == 1){
            double m = n > 0 ? x : (1.0 / x);
            return m * ans * ans;
        }
        else{
            return ans * ans;
        }
    }
};