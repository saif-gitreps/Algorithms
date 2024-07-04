#include<iostream>
/*
 left recursion.
 if 0 == 2 then left recursion.
 then remove using a formula, find Alpha , then beta
 to find alpha . the value at 2 , then the value after 2 till a bar | symbol is found. e->e+t|t ,
 here +t is alpha, t is beta.
*/
using namespace std;

int leftRecursionIndex(string s) {
    if (s[0] == s[3]) {
        return 3;
    }
    for (int i = 3; i < s.size(); i++) {
        if(i + 1 < s.size() && s[i] == '|' && s[0] == s[i + 1]){
            return i + 1;
        }
    }

    return 0;
}

void isLeftRecursion(bool &run) {
    string s, alpha = "", beta = "";
    cin >> s;

    if (s == "end") {
        run = false;
        return;
    }

    int i = leftRecursionIndex(s);

    if (!i) {
        cout << "No left recursion \n";
        return;
    }

    i++;

    while(s[i] != '|') {
        alpha += s[i];
        i++;
    }

    i++;

    while(i < s.size()) {
        beta += s[i];
        i++;
    }

    cout << "ans: \n";
    cout << s[0] << "->" << beta << s[0] << "'";
    cout << "\n";
    cout << s[0] << "'" << "->" << alpha << "" <<s[0] << "'|e";
    cout << "\n";
}

int main() {

    bool run = true;
    while(run) {
        cout << "Enter grammar: ";
        isLeftRecursion(run);
    }
}