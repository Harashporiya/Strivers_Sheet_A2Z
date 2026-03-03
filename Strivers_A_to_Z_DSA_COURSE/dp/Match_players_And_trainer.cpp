#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int p = 0;
        int t = 0;

        while (p < players.size() && t < trainers.size()) {
            if (trainers[t] >= players[p]) {
                p++;
            }
            t++;
        }

        return p;
    }
};


// ================= MAIN FUNCTION =================

int main() {

    Solution obj;

    // Hardcoded test case
    vector<int> players = {4, 7, 9};
    vector<int> trainers = {8, 2, 5, 8};

    cout << "Players: ";
    for (int x : players) cout << x << " ";

    cout << "\nTrainers: ";
    for (int x : trainers) cout << x << " ";

    cout << "\n\nMaximum matches: "
         << obj.matchPlayersAndTrainers(players, trainers) << endl;

    return 0;
}