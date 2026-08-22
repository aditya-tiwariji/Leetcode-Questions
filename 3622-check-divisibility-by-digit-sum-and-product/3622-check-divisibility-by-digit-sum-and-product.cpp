class Solution {
public:
    bool checkDivisibility(int n) {
             
             int v=n;
             string s=to_string(v);
             
             int sum=0;
             int prod=1;
             for(auto it:s){
                sum=sum+(it-'0');
                prod=prod*(it-'0');
             }
             
             return (n%(sum+prod)==0);
    }
};