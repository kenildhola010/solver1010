class StockSpanner {
public:
stack<pair<int,int>> st;
int id;
    StockSpanner() {
        id = -1;
    
    }
    
    int next(int price) {

        id++;
        
       
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }

        int span;

        if(st.empty()) span = id+1;
        else span = id- st.top().second; 

        st.push({price,id});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */