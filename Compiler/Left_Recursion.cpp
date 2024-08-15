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


// Updated 
vector<int> findLeftRecursionIndexes(string s) {
    vector<int> recursion_indexes;
    if (s[0] == s[3]) {
        recursion_indexes.push_back(3);
    }

    for (int i = 3; i < s.size(); i++) {
        if(i + 1 < s.size() && s[i] == '|' && s[0] == s[i + 1]){
            recursion_indexes.push_back(i + 1);
        }
    }

    return recursion_indexes;
}

vector<string> findAlphas(string s, vector<int> indexes) {
    vector<string> alphas;
    for (int i = 0; i < indexes.size(); i++) {
        int k = indexes[i] + 1;
        string alpha = "";
        
        while (k < s.size() && s[k] != '|') {
            alpha += s[k];
            k ++;
        }

        alphas.push_back(alpha);
    }
    return alphas;
}

vector<string> findBetas(string s, int start) {
    while (s[start] != '|') start++;
    
    vector<string> betas;
    string temp_beta = "";

    while (start < s.size()) {
        if (s[start++] == '|' && temp_beta != "") {
            betas.push_back(temp_beta);
            temp_beta = "";
            continue;
        } 
        temp_beta += s[start];
    }
    betas.push_back(temp_beta);
    return betas;
}

void findAndEliminateLeftRecursion() {
    string s;
    cin >> s;

    vector<int> indexes = findLeftRecursionIndexes(s);

    if (indexes.size() == 0) {
        cout << "No left recursion found.\n";
        return;
    }

    vector<string> alphas = findAlphas(s, indexes);
    vector<string> betas = findBetas(s, indexes[indexes.size() - 1]); 

    cout << "ans: \n";
    cout << s[0] << "->" ;
    
    for (int i = 0; i < betas.size(); i++) {
        cout << betas[i] << s[0] << "'" << (i + 1 < betas.size() ? "|" : "");
    }

    cout << "\n";
    
    cout << s[0] << "'" << "->" ; 
    
    for (auto a : alphas) {
        cout << a << "" << s[0] << "'|";
    }

    cout <<"e";
}

int main() {
    findAndEliminateLeftRecursion();
}
