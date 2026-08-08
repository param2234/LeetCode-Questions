class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int arr[26] = {0};
        int j = 0;
        int max_freq = 0;
        int ans = 0;

        for(int i = 0;i<s.length();i++){

            arr[s[i] - 'A']++;
            max_freq = max(max_freq , arr[s[i] - 'A']);

            if(i - j + 1 - max_freq > k){
                arr[s[j] - 'A']--;
                j++;
            }

            ans = max(ans , i - j + 1);

        }

        return ans;
    }
};