class Solution {
public:
    int minimumCost(vector<int>& cost) {
               int n=cost.size();
            sort(cost.rbegin(),cost.rend());
            if(n==1)return cost[0];
            if(n==2)return cost[0]+cost[1];
         
            int cnt=0;
            for(int i=0;i<n;){
                  cnt+=cost[i];
                  if(i+1<n)cnt+=cost[i+1];
                  
                  i+=3;
            }

            return cnt;


              
    }
};