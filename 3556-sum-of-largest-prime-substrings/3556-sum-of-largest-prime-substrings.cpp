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
                 for(ll i=0;i<n;i++)
                 {
                        for(ll j=0;j<=i;j++){
                                  
                                   string sub=s.substr(j,i-j+1);//{start,length}

                                   ll k=0;
                                   ll len=sub.size();
                                   while(k<len&&sub[k]=='0'){
                                          k++;
                                   }

                                   sub=sub.substr(k,len-k);
                                   if(sub.empty())continue;  
                                   ll x=stoll(sub);

                                    if(isprime(x)&&!seen.count(x)){
                                            
                                          pq.push(x);
                                          seen.insert(x);
    
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
    }
};