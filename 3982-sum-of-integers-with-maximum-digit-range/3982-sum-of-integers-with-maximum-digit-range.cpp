class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        
               unordered_map<int,int>mpp;
               int final_maxi=INT_MIN;
             for(auto it:nums){
                   
                      int x=it;
                      int mini=INT_MAX;
                      int maxi=INT_MIN;
                      while(x>0){
                           int rem=x%10;
                           maxi=max(maxi,rem);
                           mini=min(mini,rem);
                           x=x/10;
                      }

                      mpp[maxi-mini]+=it;
                      final_maxi=max(final_maxi,maxi-mini);
             }

             return mpp[final_maxi];

             
    }
};