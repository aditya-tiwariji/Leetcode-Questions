class Solution {
public:
using ll=long long;
    int minSwaps(vector<int>& nums) {
        
               int n=nums.size();
               vector<pair<ll,pair<ll,ll>>>v;

               for(int i=0;i<n;i++)
               {
                    int x=nums[i];

                    long long  sum=0;
                    while(x){
                        long long  rem=x%10;
                         sum+=rem;
                         x=x/10;
                    }
                    nums[i];
                    v.push_back({sum,{nums[i],i}});
               }

            
               sort(v.begin(),v.end());
                int cnt=0;
               for(int i=0;i<n;i++){
                    if(v[i].second.second==i)continue;
                    else{
                          cnt++;
                          swap(v[i],v[v[i].second.second]);
                          i--;
                    }
               }
               return cnt;
    }
};