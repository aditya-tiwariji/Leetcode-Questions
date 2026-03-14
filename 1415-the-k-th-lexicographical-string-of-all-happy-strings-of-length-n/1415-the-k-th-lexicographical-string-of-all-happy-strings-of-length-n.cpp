class Solution {
public:

void fun(int n,string &s,vector<string>&ans){
             
             if(s.size()==n){
                   ans.push_back(s);
                   return ;
             }

             for(char ch='a';ch<='c';ch++)
             {
                   if(s.size()==0||s.back()!=ch){
                         s.push_back(ch);
                         fun(n,s,ans);
                         s.pop_back();
                   }
             }
}
    string getHappyString(int n, int k) {
        

            string s="";
            vector<string>ans;

            fun(n,s,ans);

            sort(ans.begin(),ans.end());

            return (ans.size()>=k)?ans[k-1]:"";
    }
};