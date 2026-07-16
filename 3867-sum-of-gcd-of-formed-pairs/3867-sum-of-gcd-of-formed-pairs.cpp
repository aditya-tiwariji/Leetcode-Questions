class Solution {
public:
    long long gcdSum(vector<int>& nums) {
             int n=nums.size();

        vector<int>v(n);

        int mx=0;
           for(int i=0;i<n;i++)
               {
                      mx=max(mx,nums[i]);
                      v[i]=__gcd(nums[i],mx);
                   
               }

        sort(v.begin(),v.end());

        int i=0;
        int j=n-1;

        long long sum=0;
        while(i<j)
            {
                  int g=__gcd(v[i],v[j]);
                   sum+=g;
                i++;
                j--;
            }

        return sum;
        
    }
};