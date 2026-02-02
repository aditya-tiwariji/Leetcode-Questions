class Solution {
public:
    string removeKdigits(string nums,int k) {
           int n=nums.size();

           if(k==n)return "0";
           stack<char>st;
            
            for(int i=0;i<n;i++)
            {
                  while(!st.empty()&&k>0&&st.top()-'0'>nums[i]-'0'){
                      st.pop();
                      k--;
                  }

                  st.push(nums[i]);
            }
           
            if(k>0){
                while(!st.empty()&&k>0){
                      st.pop();
                      k--;
                }
            }

            string ans="";
            while(!st.empty()){
                  ans.push_back(st.top());
                  st.pop();
            }

            while(ans.size()!=0&&ans.back()=='0')
            {
                  ans.pop_back();
            }
            
            if(ans.empty())return "0";
            reverse(ans.begin(),ans.end());

            return ans;

    }
};