class Solution {
public:
    void solve(string &s, int used[]){
        memset(used, 0, sizeof(used) * 26);  // 注意这里要乘以 26！
        int i = 0;
        while(i < s.size()){
            used[s[i++] - 'a']++;
        }
    }

    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        int used1[26], used2[26];
        solve(s, used1);
        solve(t, used2);
        for(int i = 0; i < 26; i++){
            if(used1[i] != used2[i]) return false;
        }
        return true;
    }
};
