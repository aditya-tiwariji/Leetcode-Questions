class Solution {
public:
    int maxArea(vector<int>& height) {
            int n=height.size();

            int i=0;
            int j=n-1;
            int maxi=0;
            int cnt=0;
            while(i<=j)
            {
                  if(height[i]<=height[j]){
                        cnt=height[i]*(j-i);
                        i++;
                  }
                  else{
                     cnt=height[j]*(j-i);
                     j--;
                  }

                  maxi=max(maxi,cnt);
            }

            return maxi;
    }
};