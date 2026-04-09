class NumArray {
public:
     vector<int>block;
     int b;
     vector<int>nums;
    NumArray(vector<int>& nums) {
             int n=nums.size();
             this->nums=nums;
             b=ceil(sqrt(n));
            
              vector<int>v(b);
              block=v;

          for(int i=0;i<n;i++)
          {
              int idx=i/b;
              block[idx]+=nums[i];
          }    

    }  
    
    void update(int index, int val) {
             int blockIdx=index/b;
             block[blockIdx]-=nums[index];
          
              nums[index]=val;
              block[blockIdx]+=val;

    }
    
    int sumRange(int left, int right) {
           
             int start=left/b;
             int end=right/b;
             int sum=0;
             if(start==end){
                  for(int i=left;i<=right;i++)
                  {
                        sum+=nums[i];
                  }
             }
             else{
                  int endOfLeft=(start+1)*b-1;
                  // left
                  for(int i=left;i<=endOfLeft;i++)sum+=nums[i];
                  
                  // middle
                  for(int i=start+1;i<=end-1;i++){
                       sum+=block[i];
                  }

                  int startOfright=end*b;
                  // right

                  for(int i=startOfright;i<=right;i++)sum+=nums[i];
             }

             return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */