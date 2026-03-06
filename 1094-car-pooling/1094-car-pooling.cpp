class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
               int n=trips.size();

               vector<int>v(1001,0);

               for(auto it:trips)
               {
                   int  p=it[0];
                   int  from=it[1];
                   int  to=it[2];

                   v[from]+=p; 
                   v[to]-=p;
               }

               if(v[0] > capacity) return false;
               
               for(int i=1;i<v.size();i++)
               {
                       v[i]=v[i-1]+v[i];
                       if(v[i]>capacity)return false;
               }

               return true;
    }
};