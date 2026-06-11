class Solution {
public:
    void sortColors(vector<int>& v) {
        int l = 0;
        int mid = 0;
        int h = v.size()-1;

        while(mid<=h){
            if(v[mid] == 0){
                swap(v[l],v[mid]);
                l++;
                mid++;
            }
            else if(v[mid] == 1){
                mid++;
            }
            else{
                swap(v[h],v[mid]);
                h--;
            }

        }
    }
};