class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        map<char, int> mp;

        for (char ch : s) {
            mp[ch]++;
        }

        string prefix = "";
        string answer = "";

        for (int i = 0; i < s.size(); i++) {
            auto it = mp.upper_bound(target[i]);

            if (it != mp.end()) {
                char chosen = it->first;

                string candidate = prefix;
                candidate += chosen;

                mp[chosen]--;
                if (mp[chosen] == 0) {
                    mp.erase(chosen);
                }

                for (auto &[ch, count] : mp) {
                    candidate += string(count, ch);
                }

                answer = candidate;
                mp[chosen]++;
            }

            if (!mp.count(target[i])) {
                break;
            }

            prefix += target[i];
            mp[target[i]]--;

            if (mp[target[i]] == 0) {
                mp.erase(target[i]);
            }
        }

        return answer;
    }
};