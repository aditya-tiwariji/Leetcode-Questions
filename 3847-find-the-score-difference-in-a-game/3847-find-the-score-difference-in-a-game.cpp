class Solution {
public:
    int scoreDifference(vector<int>& nums) {
           
             int a=1;
             int b=0;

            int suma=0;
            int sumb=0;
             for(int i=0;i<nums.size();i++)
             {
                 if(nums[i]%2){
                    a=!a;
                    b=!b;

                 }
                 if(i>0&&(i+1)%6==0){
                         a=!a;
                         b=!b;
                 }

                 if(a){
                      suma+=nums[i];
                 }
                 else{
                      sumb+=nums[i];
                 }

             }
             return suma-sumb;

    }
};