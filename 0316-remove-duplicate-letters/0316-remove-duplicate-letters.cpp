class Solution {
public:
    string removeDuplicateLetters(string s) {
             int n=s.length();

             unordered_map<char,int>mpp;
             for(auto it:s)mpp[it]++;
             stack<char>st;

             unordered_set<char>seen;

             for(auto it:s){
                     mpp[it]--;

                     if(seen.count(it))continue;

                     while(!st.empty()&&st.top()>it&&mpp[st.top()]>0){
                            seen.erase(st.top());
                             st.pop();
                     }

                     st.push(it);
                     seen.insert(it);
             }


             string ans="";

             while(!st.empty()){
                      ans+=st.top();
                      st.pop();
             }

            reverse(ans.begin(),ans.end());

            return ans;

    }
};