class Solution {
public:
    string addBinary(string a, string b) {
                 int n=a.size();
                 int m=b.size();

                 int i=n-1;
                 int j=m-1;

                 string sum="";  
                  int carry=0;
                 while(i>=0||j>=0||carry==1){
                         
                           int add=carry;
                           if(i>=0){
                               add+=a[i]-'0';

                           } 
                           if(j>=0){
                              add+=b[j]-'0';
                           }

                           

                           sum=char((add%2)+'0')+sum;
                           carry=add/2;

                           i--;
                           j--;
                 }

                 return sum;
    }
};