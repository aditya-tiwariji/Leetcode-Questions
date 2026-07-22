class Solution {
public:
vector<string>v;
  
  unordered_map<int,string>mpp;

void fun(int i,string digits,string temp,int n){
      
              if(temp.size()==n){
                  v.push_back(temp);
                  return ;
              }
          

               for(auto c:mpp[digits[i]-'0']){
                      
                      if(temp.size()<n){
                             fun(i+1,digits,temp+c,n);
                      }
               }
          
          
}
    vector<string> letterCombinations(string digits) {
        
             
            
              int k=2;
              for(char ch='a';ch<='z';ch++)
              {
                       string s="";
                       int v=0;
                       if(k!=7&&k!=9)v=1;
                       char c=ch;
                       while(v<=3){
                          s+=c;
                       
                          if(v==3)break;
                           v++;
                          c++;
                       }
                       mpp[k]=s;
                      
                       k++;
                       ch=c;


              }

           
              int n=digits.size();
           

              fun(0,digits,"",n);

           

             

              return v;
    }
};