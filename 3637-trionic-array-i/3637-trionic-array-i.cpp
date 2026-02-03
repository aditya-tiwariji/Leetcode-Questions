class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
          
        for(int p=1;p<n-2;p++)
        {   
           
             for(int q=p+1;q<n-1;q++)
             {      bool f=true;
             
                   for(int i=0;i<p;i++)
                   {
                       if(nums[i]>=nums[i+1])
                       {
                            f=false;
                            break;

                       }
                   }

                if(f){
                   for(int j=p;j<q;j++)
                   {
                         if(nums[j]<=nums[j+1])
                         {
                            f= false;
                            break;
                         }
                   }
                }

                 if(f){
                   for(int i=q;i<n-1;i++)
                   {
                          if(nums[i]>=nums[i+1])
                          {
                            f= false;
                            break;
                          }
                   }
                 }
                        

             if(f)
             {
                  return true;
             }
      

            }
        }

        return false;
    }
};