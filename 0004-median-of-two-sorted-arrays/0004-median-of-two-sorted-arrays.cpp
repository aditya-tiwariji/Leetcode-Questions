class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
          
               int n=nums1.size();
               int m=nums2.size();

              vector<int>temp;

              int i=0;
              int j=0;

              while(i<n&&j<m)
              {
                      if(nums1[i]<=nums2[j]){
                           temp.push_back(nums1[i]);
                           i++;
                      }
                      else{
                         temp.push_back(nums2[j]);
                         j++;
                      }
              }

              while(i<n){
                  temp.push_back(nums1[i]);
                  i++;
              }
              while(j<m){
                  temp.push_back(nums2[j]);
                  j++;
              }

              int  len=n+m;

              int mid=len/2-1;
              double med;
              if(len%2==0){
                 med=(temp[mid]+temp[mid+1])/2.0;
              }
              else med=temp[mid+1];
           
               return med;


              
               
    }
};