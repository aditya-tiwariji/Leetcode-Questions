class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLend, int secondLen) {
            int n=nums.size();
           vector<int>pre(n,0);

              pre[0]=nums[0];

              for(int i=1;i<n;i++)
              {
                  pre[i]=pre[i-1]+nums[i];
              }
              
              
                  
              int i=0;
              int j=0; 
              int maxi=0;
      
              while(j<n)
              {
                     if(j-i+1==secondLen){
                            int cur_sum=pre[j]-(i-1<0?0:pre[i-1]);
                            int l1=0;
                            int l2=0;
                            int mx1=0;
                           
                                  
                                 
                                   while(l2<i){
                                        if(l2-l1+1==firstLend){
                                                if(l1-1>=0){
                                                   mx1=max(mx1,pre[l2]-pre[l1-1]);
                                                }
                                                else{
                                                     mx1=max(mx1,pre[l2]);
                                                }
                                                l1++;
                                        }
                                        l2++;
                                        
                                   }
                            

                               l1=j+1;
                               l2=j+1;
                           
                           
                                  
                                 
                                   while(l2<n){
                                        if(l2-l1+1==firstLend){
                                                if(l1-1>=0){
                                                   mx1=max(mx1,pre[l2]-pre[l1-1]);
                                                }
                                                else{
                                                     mx1=max(mx1,pre[l2]);
                                                }
                                                l1++;
                                        }
                                        l2++;
                                        
                                   }
                                i++;
                            maxi=max(maxi,cur_sum+mx1);
                     }
                     
                     j++;
                      
              }

              return maxi;

              

              

                
               
    }
};