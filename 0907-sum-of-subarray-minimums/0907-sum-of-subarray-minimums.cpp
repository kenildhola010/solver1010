class Solution {
public:
    vector<int> f1(vector<int> v){

        int n = v.size();
        vector<int> nse(n,n);
        stack<int> st;

        for(int i=n-1;i>=0; i--){
            while(!st.empty() && v[i] <=  v[st.top()]) st.pop();

            if(!st.empty()) nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> f2(vector<int> v){

        int n = v.size();
        vector<int> psee(n,-1);
        
        stack<int> st;

        for(int i=0;i <n; i++){
            while(!st.empty() && v[i] <  v[st.top()])  st.pop();

            if(!st.empty()) psee[i] = st.top();
            st.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        
        vector<int> nse = f1(arr);
        vector<int> psee = f2(arr);
        long long ans = 0;
        int  md = 1e9 +7;

        for(int i=0; i<arr.size(); i++){

            int left = i  - psee[i];
            int right = nse[i] - i;

            ans = (ans + (1LL * left * right % md) * arr[i]) % md;
        }
        return int(ans);
    }
};