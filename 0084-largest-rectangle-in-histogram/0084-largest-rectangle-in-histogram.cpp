class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
          
            //pse //nse
            int n=heights.size();


            vector<int>pse(n,-1);
            vector<int>nse(n,n);

            stack<int>st;
            for(int i=0;i<n;i++){
                
                  while(!st.empty()&&heights[st.top()]>=heights[i]){
                           st.pop();

                  }

                 if(st.empty())pse[i]=-1;  
                 else pse[i]=st.top();
                 st.push(i);
  
            }

            stack<int>pt;

            for(int i=n-1;i>=0;i--){
                   
                   while(!pt.empty()&&heights[pt.top()]>=heights[i]){
                       pt.pop();
                   }

                   if(pt.empty())nse[i]=n;
                   else nse[i]=pt.top();
                   pt.push(i);
            }

            int ans=0;
            for(int i=0;i<n;i++){
                   int wd=nse[i]-pse[i]-1;
                   ans=max(ans,wd*heights[i]);
            }

            return ans;
    }  
};