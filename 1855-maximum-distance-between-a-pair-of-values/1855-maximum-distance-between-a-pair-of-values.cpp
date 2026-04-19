class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
            int n=nums1.size();
            int m=nums2.size();
            vector<int>temp=nums2;
            reverse(temp.begin(),temp.end());

            int maxi=0;
            for(int i=0;i<n;i++)
            {
                auto it=lower_bound(temp.begin(),temp.end(),nums1[i]);
                if(it==temp.end()){
                        if(temp[m-1]==nums1[i]){
                                if(m-1-i>=0){
                                   maxi=max(maxi,m-1-i);
                                }
                        }      
                }
                else{
                    int ind=it-temp.begin();
                    // return ind;

                    int org=m-1-ind;
                 
                    if(i<=org){
                       maxi=max(maxi,org-i);
                    }
                }
            }
            return maxi;
    }
};