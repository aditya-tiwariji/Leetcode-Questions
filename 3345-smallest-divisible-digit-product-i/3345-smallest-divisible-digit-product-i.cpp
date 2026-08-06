class Solution {
public:
    int smallestNumber(int n, int t) {
          
              
              int x=n;

                 while(true){
                       
                        int p=1;
                        string s=to_string(x);
                        for(auto it:s)p=p*(it-'0');
                        if(p%t==0)return x;
                        x++;

                 }

                 return 0;
    }
};