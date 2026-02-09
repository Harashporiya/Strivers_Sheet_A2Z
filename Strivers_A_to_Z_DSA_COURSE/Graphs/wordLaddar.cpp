#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            if(word == endWord){
                return step;
            }

            for(int i = 0; i < word.size(); i++){
                char ch = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, step + 1});
                    }
                }
                word[i] = ch;
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    int result = sol.ladderLength(beginWord, endWord, wordList);
    cout << "Shortest transformation length: " << result << endl;

    return 0;
}
