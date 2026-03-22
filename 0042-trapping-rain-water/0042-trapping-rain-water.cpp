class Solution {
public:
    int trap(vector<int>& height) {
        
             int n=height.size();

             int i=0;
             int j=n-1;

             int pre_max=0;
             int suff_max=0;

             int cnt=0;
             while(i<j)
             {
                    if(height[i]<=height[j]){
                           if(height[i]>=pre_max)pre_max=height[i];
                           else  cnt+=pre_max-height[i];

                           i++;
                    }
                    else{
                         if(height[j]>=suff_max)suff_max=height[j];
                         else cnt+=suff_max-height[j];
                         j--;
                    }
             }

             return cnt;
    } 
};