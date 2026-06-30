
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/?envType=daily-question&envId=2026-06-30

class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0;
        int n=s.length();
        int res=0;
        unordered_map<char,int> mp;
        for(int j=0;j<s.length();j++){
            mp[s[j]]++;
            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1){
                res+=n-j;
                mp[s[i]]--;
                i++;
            }
        }  
        return res;
        }
    };
