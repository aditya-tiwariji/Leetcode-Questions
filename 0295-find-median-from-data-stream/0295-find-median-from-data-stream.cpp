class MedianFinder {
public:
  priority_queue<int>left;
  priority_queue<int,vector<int>,greater<int>>right;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
      
              left.push(num);

              if(!right.empty()&&right.top()<left.top()){//left<=right
                     int x=left.top();
                     left.pop();

                     right.push(x);
              }

              if(left.size()>right.size()+1){
                       int x=left.top();
                       left.pop();

                       right.push(x);
              }
             else if(right.size()>left.size()){
                  int x=right.top();
                  right.pop();

                  left.push(x);
             }



       


    }
    
    double findMedian() {
       
                 if(left.size()>right.size()){
                       return left.top();
                 }
                 else{
                      return (double)(left.top()+right.top())/2;
                 }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */