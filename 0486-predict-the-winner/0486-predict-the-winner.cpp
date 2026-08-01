class Solution {
public:
    

    bool fun(vector<int>&nums,bool turn,int l ,int r ,int s1,int s2){

                 if(r<l){
                      return s1>=s2;
                 }             


             if(turn){
                  
                   bool first=fun(nums,!turn,l+1,r,s1+nums[l],s2);
                   bool last=fun(nums,!turn,l,r-1,s1+nums[r],s2);

                   return first||last;
                  

             }
             else{
                 
                 
                 bool first=fun(nums,!turn,l+1,r,s1,s2+nums[l]);
                 bool last=fun(nums,!turn ,l,r-1,s1,s2+nums[r]);

                 return first&&last; // for evry move of p2 p1 must win

             }
               
    }

    bool predictTheWinner(vector<int>& nums) {
           int n=nums.size();
            
            
          bool ans=fun(nums,true,0,n-1,0,0);

         return ans;


           
    }
};