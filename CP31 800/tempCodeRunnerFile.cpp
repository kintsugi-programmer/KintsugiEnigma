#include <bits/stdc++.h>
using namespace std;

int main() {
    int tests;
    cin >> tests;

    while (tests--) {
        int lenarr;
        cin >> lenarr;

        vector<string> arr(lenarr);
        for (int i = 0; i < lenarr; i++) {
            cin >> arr[i];
        }

        int dot = 0;
        int con = 0;
        bool found_three_consecutive = false;

        for (int i = 0; i < lenarr; i++) {
            if (arr[i] == ".") {
                dot++;
                con++;
                if (con == 3) {
                    found_three_consecutive = true;
                    continue;
                }
            } else {
                con = 0;
                continue;
            }
        }

        if (found_three_consecutive) {
            cout << 3 << endl;
        } else {
            cout << dot << endl;
        }
    }

    return 0;
}
