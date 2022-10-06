class TimeMap {
    // {key, {{timestamp1, value1}, {timestamp2, value2}, {timestamp3, value3}}}
    unordered_map<string, vector<pair<int, string>>> hmap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hmap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!hmap.count(key)){
            //key not present in the hmap
            return "";
        }
        //using binary search to find out the timestamp just smaller than input timestamp
        int l = 0;
        int r = hmap[key].size()-1;
        
        if(hmap[key][l].first > timestamp){
            // the timestamps inside vector are greatetr than input
            return "";
        }
        if(hmap[key][r].first <= timestamp){
            //last timestamp of vector is smaller than input
            return hmap[key][r].second;
        }
        
        while(l<r-1){
            int mid = (l+r)/2;
            
            if(hmap[key][mid].first < timestamp){
                //goto right half of vector
                l = mid;
            }
            else if(hmap[key][mid].first == timestamp){
                return hmap[key][mid].second;
            }
            else{
                r = mid;
            }
        }
        
        if(hmap[key][r].first <= timestamp){
            return hmap[key][r].second;
        }
        else{
            return hmap[key][l].second;
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */