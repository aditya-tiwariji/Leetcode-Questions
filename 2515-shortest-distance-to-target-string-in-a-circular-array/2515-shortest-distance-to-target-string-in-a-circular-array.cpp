class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
           int n=words.size();
           int m=target.size();

           if(words[startIndex]==target)return 0;

           int i=(startIndex+1)%n;
           int cnt1=1;
           while(words[i]!=target&&i!=startIndex){
                 cnt1++;
                 i=(i+1)%n;
                if(startIndex==i)return -1;
           }

           i=(startIndex-1+n)%n;
           int cnt2=1;
           while(words[i]!=target&&i!=startIndex){
               cnt2++;
               i=(i-1+n)%n;
               if(startIndex==i)return -1;
           }

           return min(cnt1,cnt2);
    }
};