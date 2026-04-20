class Solution {
public:
    int maxDistance(vector<int>& colors) {
           int n=colors.size();
           int i=0;
           int j=n-1;

           int maxi=0;    
           while(i<=j){
                if(colors[i]!=colors[j]){
                       maxi=max(maxi,j-i);
                       break;
                }
                else{
                     j--;
                }
               
           }

           i=0;
           j=n-1;
            while(i<=j){
                if(colors[i]!=colors[j]){
                       maxi=max(maxi,j-i);
                       break;
                }
                else{
                     i++;
                }
               
           }

           return maxi;
    }
};