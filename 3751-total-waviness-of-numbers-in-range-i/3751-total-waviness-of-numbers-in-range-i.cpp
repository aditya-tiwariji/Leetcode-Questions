class Solution {
public:
    int totalWaviness(int num1, int num2) {
           int cnt=0;
            for(int i=num1;i<=num2;i++)
                {
                         string s=to_string(i);
                        int n=s.size();
                    if(n<=2)continue;
                        for(int i=1;i<n-1;i++){
                              int m=s[i]-'0';
                              int r=s[i+1]-'0';
                               int l=s[i-1]-'0';
                            if(m>l&&m>r|| m<l&&m<r)cnt++;
                            
                        }
                }
        return cnt;
    }
};