class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> mp;
        int ans =0;

        for(char c : text){
            mp[c]++;

            if( mp['b'] >= 1 && mp['a'] >= 1 && mp['l'] >= 2 && mp['o'] >= 2 && mp['n']  >= 1 ){
                
                mp['b']--;
                 mp['a']--; 
                  mp['l']--;  
                  mp['l']--;  
                  mp['o']--;
                   mp['o']--;
                  mp['n']--;
                  ans++;
            }
        }

        return ans;

        

       
    }
};