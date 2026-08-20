class Solution {
public:
using ll =long long;
ll cnt=0;

vector<int> merge(int low,int mid,int high,vector<int>&nums){
       
          int i=low;
          int j=mid+1;
        
          vector<int>temp;
          while(i<=mid&&j<=high){
               if(nums[i]<=nums[j]){
                    temp.push_back(nums[i]);
                    i++;
                  
               }
               else{
                  temp.push_back(nums[j]);
                  j++;
                 
               }
          }

          while(i<=mid){
                temp.push_back(nums[i]);
                i++;
          }

          while(j<=high){
                temp.push_back(nums[j]);
                j++;
          }
             
          for (int k = low; k <= high; k++) {
            nums[k] = temp[k - low];
           }
          return temp;
}
void mergesort(int l,int h,vector<int>&nums){
         if(l >= h) return;

            int mid=(l+h)/2;

            mergesort(l,mid,nums);
            mergesort(mid+1,h,nums);

              int i=l;
              int j=mid+1;
        
              while(i<=mid&&j<=h){
                    if((long long)2*nums[j]<nums[i]){
                          j++;

                    }
                    else{
                          cnt+=j-(mid+1);
                          i++;
                    }
              }
              while(i<=mid){
                    cnt+=j-(mid+1);
                    i++;
              }

            merge(l,mid,h,nums);


              
}
    int reversePairs(vector<int>& nums) {
        
              int n=nums.size();

              int low=0;
              int high=n-1;


              mergesort(low,high,nums);

              return cnt;

            
    }
};