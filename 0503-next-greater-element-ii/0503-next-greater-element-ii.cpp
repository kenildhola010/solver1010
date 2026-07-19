class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        
        int n = v.size();
        for(int i=0;i<n; i++){
            v.push_back(v[i]);
        }

        stack<int> st;
        vector<int> temp(n,-1);

        for(int i=v.size()-1; i>=0; i--){
            if(i > n -1 ){
                while(!st.empty() && v[i] >= v[st.top()]){
                    st.pop();
                }
                st.push(i % n);
            }
            else{
                while(!st.empty() && v[i] >= v[st.top()]) st.pop();

                if(st.empty()){
                    temp[i] = -1;
                }
                else{
                    temp[i] = st.top();
                }
                st.push(i % n);
            }
        }
        vector<int> ans;
        for(int  i=0; i<n; i++){
            if(temp[i] == -1) ans.push_back(-1);
            else ans.push_back(v[temp[i]]);
        }
        return ans;
    }
};