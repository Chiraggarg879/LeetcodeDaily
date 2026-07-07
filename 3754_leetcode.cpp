// https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/description/?envType=daily-question&envId=2026-07-07

class Solution {
public:
    long long reverse(long long n){
        long long res = 0;
        while(n){
            int dig = n % 10;
            res = res * 10 + dig;
            n/=10;
        }
        return res;
    }
    long long sumAndMultiply(int num) {
        long long res = 0;
        int sm = 0;
        while(num){
            int dig = num %10;
            num/=10;
            if(dig == 0) continue;
            res = res * 10 + 1LL*dig;
            sm += dig;
        }
        res = reverse(res);
        return (1LL*sm * res);
    }
};