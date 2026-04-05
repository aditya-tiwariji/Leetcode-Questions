class Solution {
public:
    vector<int> findGoodIntegers(int n) {
           
           unordered_map<long long ,long long >mpp;
           for(int i=1;i<=1000;i++)
           {
                  for(int j=i;j<=1000;j++)
                  {
                            long long x=(long long )i*i*i + (long long )j*j*j;
                            if(x>n)break;
                            mpp[x]++;
                            
                  }
           }
         vector<int>ans;
           for(auto it:mpp)
           {
               if(it.second>=2){
                    ans.push_back(it.first);
               }
           }

            sort(ans.begin(),ans.end());
           return ans;
    }
};