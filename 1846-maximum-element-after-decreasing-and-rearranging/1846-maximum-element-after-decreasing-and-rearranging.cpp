class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
              sort(arr.begin(),arr.end());

              vector<long long>v;
              v.push_back(1);  
              for(int i=1;i<arr.size();i++){
                    if(arr[i]-v.back()>1){
                              v.push_back(v.back()+1);
                    }
                    else{
                         v.push_back(arr[i]);
                    }
                    
              }

                sort(v.rbegin(),v.rend());

                return v[0];
    }
};