class TimeMap {
    unordered_map<int, unordered_map<string,string>> hmap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hmap[timestamp][key] = value;
    }
    
    string get(string key, int timestamp) {
        while(timestamp>0){
            if(hmap.count(timestamp) && hmap[timestamp].count(key)){
                return hmap[timestamp][key];
            }
            timestamp--;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */