class Robot {
public:
    
    char cur='E';
    map<char,char>AC;
    int x=0;
    int y=0;
    int mx=0;
    int my=0;

    Robot(int width, int height) {
           mx=width;
           my=height;

        
               AC['E']='N';
               AC['W']='S';
               AC['N']='W';
               AC['S']='E';
    }
    
    void step(int num) {
           
                int p=2*(mx+my-2);
    
                int k=num%p;
                if (k==0)k=p;

             while(k>0){
                
                  if(cur=='E'){
                      if(x+1==mx){
                           cur=AC[cur];
                           continue;
                      }
                       x++; 
                  }
                  else if(cur=='W'){
                      if(x-1<0){
                           cur=AC[cur];
                           continue;
                      }
                      x--;
                  }
                  else if(cur=='N'){
                      if(y+1==my){
                           cur=AC[cur];
                           continue;
                      }
                       y++;
                  }
                 else  if(cur=='S'){
                      if(y-1<0){
                           cur=AC[cur];
                           continue;
                      }
                      y--;
                  }
                  k--;
             }
    }
    
    vector<int> getPos() {
             return {x,y};
    }
    
    string getDir() {
          
           if(cur=='E')return "East";
           else if(cur=='W')return "West";
           else if(cur=='N')return "North";
           else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */