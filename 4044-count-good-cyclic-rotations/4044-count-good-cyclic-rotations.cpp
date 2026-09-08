class Solution {
public:
using ll=long long;
    int countGoodRotations(vector<int>& nums) {
           int n=nums.size();

            queue<int>q1,q2;
            ll sum1=0,sum2=0;
           for(int i=0;i<n;i++){
                 if(i<n/2){
                      q1.push(nums[i]);
                      sum1+=nums[i];
                 }
                 else{
                      q2.push(nums[i]);
                      sum2+=nums[i];
                 }
           }

           int k=0;
           int cnt=0;
           while(k<n){
                 cout<<sum1<<" "<<sum2<<endl;
                 if(sum1>sum2)cnt++;
                 int x=q1.front();
                 int y=q2.front();
                 q1.pop();
                 q2.pop();

                 sum1-=x;
                 sum1+=y;
                 sum2-=y;
                 sum2+=x;

                 q1.push(y);
                 q2.push(x);
                 k++;
                 
           }

           return cnt;
    }
};