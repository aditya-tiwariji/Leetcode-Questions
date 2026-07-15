class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        
              int so=(n*(2*1+(n-1)*2))/2;
              int se=(n*(2*2+(n-1)*2))/2;

              return __gcd(se,so);


    }
};