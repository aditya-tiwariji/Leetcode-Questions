class Solution {
public:
const int mod=1e9+7;
using ll=long long;

long long power(long long x, long long y, long long mod) {
    
    long long ans = 1;
    
    while (y > 0) {
        
        if (y % 2 == 1) {
            ans = (ans * x) % mod;
        }
        
        x = (x * x) % mod;
        y = y / 2;
    }
    
    return ans;
}
    int sumDecoded(vector<long long>& nums) {
              
              ll n=nums.size();
              ll sum=0;

              for(auto it:nums){
                    
                    ll w=it%10;
                    ll d=it/10;

                   string s=to_string(d);
                   ll k=0;
                   ll x=0;
                   for(ll i=0;i<s.size()&&k<w;i++){
                         x=x*10+s[i]-'0';
                         k++;    
                   }
                   ll y=0;
                   for(ll i=k;i<s.size();i++){
                         y=y*10+s[i]-'0';
                   }

                   sum=(sum+power(x,y,mod))%mod;

              }
              return sum;
    }
};