class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        
        int n = changed.size();
        
        if(n%2 != 0){
            //because input array does not have even number of elements
            return {};
        }
        
        vector<int> ans;
        
        unordered_map<int,int> hmap;
        for(int i=0;i<n;i++){
            hmap[changed[i]]++;
        }
        
        for(int i=0;i<n;i++){
            if(hmap[changed[i]]==0)
                continue;
            if(hmap[2*changed[i]]==0)
                return {};
            
            ans.push_back(changed[i]);
            hmap[changed[i]]--;
            hmap[2*changed[i]]--;
        }
        
        return ans;
    }
};