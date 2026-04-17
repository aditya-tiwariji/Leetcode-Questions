class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
            int n=nums.size();

            map<string ,vector<int>>mpp;
            map<int,int>vis;

            for(int i=0;i<n;i++)
            {
                  string s=to_string(nums[i]);
                  mpp[s].push_back(i);

            }

            int mini=INT_MAX;
            bool f=false;
            for(int i=0;i<n;i++)
            {
                  string s=to_string(nums[i]);
                   int j=s.size()-1;
                  while(j>=0&&s[j]=='0')j--;
                  s=s.substr(0,j+1);
                  string temp=s;
                  reverse(s.begin(),s.end());
                  string rev=s;
                 
                 
                  if(mpp[rev].size()>=1){
                      
                         
                        
                         vector<int>&v=mpp[rev];
                         if(v.size()==1&&v[0]==i)continue;

                         auto it=upper_bound(v.begin(),v.end(),i);
               
                            if(it!=v.end()){     
                               int pos=it-v.begin();
                               mini=min(mini,abs(i-v[pos]));
                               f=true;
                            }
                         }


                       
                  }
            

            if(!f)return -1;
            return mini;
    }
};