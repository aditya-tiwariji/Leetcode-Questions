class Solution {
public:
    bool rotateString(string s, string p) {
        int n1=s.length(),n2=p.length();
        int j=0;
        for(int i=0;i<n1;i++){
            string t=s.substr(i)+s.substr(0,i);
            if(t==p)return true;
        }
        return false;

       


        
    }
};