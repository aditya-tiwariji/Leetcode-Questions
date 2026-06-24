class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
                int n=position.size();

                int low=1;
                int high=*max_element(position.begin(),position.end());

                sort(position.begin(),position.end());
                
                int ans=0;
                while(low<=high){
                      
                         int mid=low+(high-low)/2;// mid dist b/w every ball

                         int k=1;

                         int prev=position[0];   
                         for(int i=1;i<n;i++){
                              if(position[i]-prev>=mid){
                                       k++;
                                       prev=position[i];
                              }
                              
                         }

                         if(k>=m){
                             ans=mid; 
                             low=mid+1;
                              
                         }
                         else{
                              high=mid-1;
                         }


                }

                return ans;
    }
};