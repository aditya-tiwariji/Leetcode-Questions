class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
              int mx1=*max_element(nums.begin(),nums.end());
              int cnt=0;
              int max2=0;
              for(int i=0;i<nums.size();i++){
                  if(nums[i]==mx1)cnt++;
                  else{
                      max2=max(max2,nums[i]);
                  }
              }
                 
                //  cout<<mx1<<" "<<max2<<endl;
                //  cout<< (mx1-1)*(max2-1)<<endl;

              if(cnt>=2){
                  return (mx1-1)*(mx1-1);
              }
              else return (mx1-1)*(max2-1);

              
    }
};