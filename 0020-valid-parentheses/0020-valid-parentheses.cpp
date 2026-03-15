class Solution {
public:
    bool isValid(string s) {
            
             stack<char>st;

             for(auto it:s)
             {
                 if(it=='('||it=='['||it=='{')st.push(it);
                 else{
                      
                      if(!st.empty()){
                      char ch=st.top();
                      if(ch=='['&&it==']'){
                           st.pop();
                      }
                      else if(ch=='('&&it==')'){
                          st.pop();
                      }
                      else if(ch=='{'&&it=='}'){
                          st.pop();
                      }
                      else{
                          return false;
                      }
                      }
                      else return false;
                 }
             }

             return (st.empty()?true:false);
    }
};