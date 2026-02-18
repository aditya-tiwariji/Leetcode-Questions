class Solution {
public:
    bool hasAlternatingBits(int n) {
            string s=bitset<32>(n).to_string();
            int ind=s.find('1');

            if(ind==n)return false;

            for(int i=ind;i<s.size()-1;i++)
            {
                  if(s[i]==s[i+1])return false;
            }
            return true;
    }
};