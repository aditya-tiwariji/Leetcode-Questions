class Solution {
public:
    bool validDigit(int n, int x) {
            string s=to_string(n);
            if(s[0]==x+'0')return false;
            int cnt=count(s.begin(),s.end(),x+'0');
            if(cnt)return true;
            return false;
    }
};