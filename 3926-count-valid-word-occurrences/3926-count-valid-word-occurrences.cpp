class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
            string s="";
            
            for(auto it:chunks)s+=it;
            int n=s.length();
            int i=0;
            while(i<n&&s[i]==' ')i++; 
            
            string sub="";
            map<string,int>mpp;
            while(i<n){
                   if(s[i]==' '){
                       if(!sub.empty()){
                         mpp[sub]++;
                          sub="";
                       }

                   }
                   if(i+1<n&&s[i]=='-'&&s[i+1]=='-'){
                    if(!sub.empty()){
                       mpp[sub]++;
                    }
                      while(s[i]=='-')i++;

                      sub="";
                   }

                   if(s[i]>='a'&&s[i]<='z')sub+=s[i];
                   else if(i+1<n&&i-1>=0&&s[i]=='-'&&isalpha(s[i-1])&&isalpha(s[i+1]))sub+=s[i];

                   i++;
            }

            if(!sub.empty())mpp[sub]++;

            vector<int>ans;
            for(auto it:queries){
                   if(mpp.count(it))ans.push_back(mpp[it]);
                   else ans.push_back(0);
            }

            return ans;


    }
};