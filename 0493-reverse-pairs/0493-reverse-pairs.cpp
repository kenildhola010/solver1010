class Solution {
public:
int ct = 0;
    void merge(int low, int mid, int high, vector<int>& v){

        vector<int> temp;
        int left = low;
        int right = mid+1;

        while(left <= mid && right <= high){
            if(v[left] <= v[right]){
                temp.push_back(v[left]);
                left++;
            }
            else {
                temp.push_back(v[right]);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(v[left]);
                left++;
        }

        while(right <= high ){
            temp.push_back(v[right]);
                right++;
        }

        for(int i=low; i<=high; i++){
            v[i] = temp[i-low];
        }

    }
    void ctp(int low, int mid, int high, vector<int>& v){
        int right = mid+1;
        for(int i=low;i<=mid; i++){
            while(right <= high && (long long)v[i] > 2LL * v[right]){
                right++;
            }
           ct += right - (mid + 1);
        }
    }
    void mergesort(int low, int high, vector<int>& v){

        if(low >= high ) return;
        int mid = (low + high) / 2;

        mergesort(low,mid, v);
        mergesort(mid+1,high,v);
        ctp(low, mid, high, v);
        merge(low, mid, high, v);
    }
    int reversePairs(vector<int>& v) {
        
        int n = v.size();
        mergesort(0,n-1,v);

        return ct;

    }
};