A->ietAB
A->ietMN

int main() {
    string s1, s2, temp = "";
    cin >> s1 >> s2;

    int i = 0;

    for (i = 3; i < min(s1.size() , s2.size()); i++) {
        if (s1[i] == s2[i]) temp += s1[i];
        else break;
    }

    cout << "A->" << temp <<"A'\n";
    cout << "A'->" << s1.substr(i) << "|" << s2.substr(i);
}
