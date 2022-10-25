class DetectSquares {
    map<vector<int>, int> hmap;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        hmap[point]++;
    }
    
    int count(vector<int> point) {
        int ans = 0;
        int x = point[0];
        int y = point[1];
        for(auto pts : hmap){
            int currX = pts.first[0];
            int currY = pts.first[1];
            if(currX!=x && currY!=y && abs(x-currX)==abs(y-currY)){
                int countOfSameX = hmap[{currX,y}];
                int countOfSameY = hmap[{x,currY}];
                int countOfDiagonal = hmap[{currX,currY}];
                ans += countOfSameX*countOfSameY*countOfDiagonal;
            }
        }
        
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */