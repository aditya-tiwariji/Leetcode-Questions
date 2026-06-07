class Solution {
public:

vector<string>ans;
void fun(string s,int n,int k){

    if(s.size()==n){
           int cost=0;
            for(int i=0;i<n;i++)if(s[i]=='1')cost+=i;
            if(cost<=k){
                   ans.push_back(s);
            }
            return ;
    }

         if(s.back()=='1'){
              fun(s+'0',n,k);
         }
         else{
             fun(s+'0',n,k);
             fun(s+'1',n,k);

         }
}
    vector<string> generateValidStrings(int n, int k) {
        
                    fun("0",n,k);
                    fun("1",n,k);

                    return ans;
    }
};