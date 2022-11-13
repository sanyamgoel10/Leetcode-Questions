class Solution {
public:
    string reverseWords(string s) {
        
        //  STACK APPROACH
//         int y=0;
//         while(y<s.size() && s[y]==' '){
//             y++;
//         }
//         s=s.substr(y,s.size()-y);
//         int y1 = s.size()-1;
//         while(y1>=0 && s[y1]==' '){
//             y1++;
//         }
//         s=s.substr(0,y1+1);
        
//         // cout<<s<<"WEDF";
//         s+=" ";
//         stack<string> st;
//         vector<int> a;
//         int l=0;
//         int r=0;
        
//         while(l<=r && r<s.size()){
//             if(s[r]!=' '){
//                 r++;
//             }
//             else if(s[r]==' '){
//                 string temp = s.substr(l,r-l);
//                 int x=0;
//                 while(x<temp.size() && temp[x]==' '){
//                     x++;
//                 }
//                 temp=temp.substr(x,temp.size()-x);
//                 st.push(temp);
//                 l=r+1;
//                 while(s[r]==' '){
//                     r++;
//                 }
//             }
//         }
        
//         string res="";
        
//         while(!st.empty()){
//             // cout<<st.top()<<endl;
//             res+=st.top() + " ";
//             st.pop();
//         }
        
//         res=res.substr(0,res.size()-1);
//         return res;
        
        //TWO POINTER APPROACH
        string ans="";
        string temp="";
        
        int l=0;
        int r=s.size()-1;
        
        while(l<=r){
            char a = s[l];
            
            if(a!=' '){
                temp+=a;
                if(l==r){
                    if(ans==""){
                        ans=temp;
                    }
                    else{
                        ans = temp+" "+ans;
                    }
                }
            }
            else if(a==' ' && temp!=""){
                if(ans==""){
                    ans=temp;
                }
                else{
                    ans = temp + ' ' + ans;
                }
                temp="";
            }
            l++;
        }
        return ans;        
    }
};