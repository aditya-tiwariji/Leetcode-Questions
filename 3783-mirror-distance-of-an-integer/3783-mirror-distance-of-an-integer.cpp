class Solution {
public:
    int mirrorDistance(int n) {

             string s=to_string(n);
            reverse(s.begin(),s.end());

             long long x=stoll(s);
              return abs(n-x);
    }
};