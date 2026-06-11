class Solution {
public:
using ll =long long ;
bool isprime(ll n){
          
          if(n==2)return true;
          if(n<=1)return false;

          for(ll i=2;i*i<=n;i++){
               if(n%i==0)return false;
          }

          return true;
}
    long long sumOfLargestPrimes(string s) {
            
                 ll n=s.size();
                 set<int>seen;
                priority_queue<ll>pq; 
                 for(ll i=0;i<n;i++)//O(n)
                 {
                       ll num=0;
                        for(ll j=i;j<n;j++){//O(n)
                                
                                num=num*10+s[j]-'0';

                                if(isprime(num)&&!seen.count(num)){
                                       pq.push(num);
                                       seen.insert(num);
                                }

                        }
                 }

                 int k=min(3,(int)pq.size()); 
                 ll sum=0;
                 while(k--){
                       sum+=pq.top();
                       pq.pop();
                 }

                 return sum;
                 // tc
    }
};