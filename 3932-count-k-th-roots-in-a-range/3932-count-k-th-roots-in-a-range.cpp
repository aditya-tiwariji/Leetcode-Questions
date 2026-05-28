class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k==1)return r-l+1;
        int cnt=0;   
          for(int x=0;x<=100000;x++){
               if(pow(x,k)>=l&&pow(x,k)<=r)cnt++;
          }

          return cnt;
    }
};