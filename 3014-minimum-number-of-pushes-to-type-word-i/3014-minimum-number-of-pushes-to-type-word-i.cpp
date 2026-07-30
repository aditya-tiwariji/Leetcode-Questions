class Solution {
public:
    int minimumPushes(string word) {
        
           int n=word.size();

          int x=n/8;
          int rem=n%8;

           int sum=0;
          for(int i=1;i<=x;i++){
             sum+=i*8;
          }

          return sum+(x+1)*rem;




    }
};