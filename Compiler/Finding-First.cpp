#include <bits/stdc++.h>
using namespace std;

string find_terminal(string s, unordered_map<string, string> &mp) {
    if (mp.find(s) != mp.end()) {
        return find_terminal(mp[s], mp);
    }

    return s;
}


int main() {
    cout << "Enter the number of production: \n";
    int n; 
    cin >> n;
    unordered_map<string, string> start_first_map; 

    // for prime use backticks, E` 
    cout << "Enter the production(s): \n";
    while (n--) {
        string temp, start = "", first = "";
        cin >> temp;

        int i = 0;
        while (i < temp.size() && temp[i] != '-') {
            start += temp[i]; 
            i++;
        }
        i += 2; // for example, E->Fi, currrent index is at '-', need to move outta dat.

        if (islower(temp[i])) {
            // case where first is 'id'.
            while (islower(temp[i])) {
                first += temp[i];
                i++;
            }
        } else if (i + 1 < temp.size() && isupper(temp[i]) && temp[i+1] == '`'){
            // case where first is '+' or '(' or 'a'
            first += temp[i];
            first += temp[i+1];
        } else {
            first = temp[i];
        }

        start_first_map[start] = first;
        // prod_array.push_back()
    }

    cout << "\n";

    for (auto &it : start_first_map) {
        // checking if it is terminal. 
        if (start_first_map.find(it.second) != start_first_map.end()) {
            string terminal = find_terminal(it.second, start_first_map);

            cout << "first(" << it.first << ")=" << terminal;
        } else {
            cout << "first(" << it.first << ")=" << it.second;
        }
        cout << "\n";
    }
}
