#include <stdio.h>
#include <stdbool.h>

bool isOperator(char a) {
    if (a == '+' || a == '-' || a == '*' || a == '%' || a == '=') {
        return true;
    }
    return false;
}

bool isIdentifier(char a) {
    if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z') || (a >= '0' && a <= '9')) {
        return true;
    }
    return false;
}

int main() {
    char s[100];
    fgets(s, sizeof(s), stdin);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            continue;
        }

        if (isIdentifier(s[i])) {
            char temp[100] = "";
            int j = 0;

            while (s[i] != '\0' && s[i] != ' ' && isIdentifier(s[i])) {
                temp[j++] = s[i++];
            }
            printf("%s is identifier\n", temp);
        }

        if (isOperator(s[i])) {
            printf("%c is operator\n", s[i]);
        }
    }

    return 0;
}

/* C++ */

bool isOperator(char a) {
    if (a == '+' || a == '-' || a == '*' || a == '%' || a == '=' )
        return true;
    return false;
}

bool isIdentifier(char a) {
    if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z') || (a >= '0' && a <= '9'))
        return true;
    return false;
}

int main() {
    string s;
    getline(cin, s);

    unordered_set<string> keywords;
    keywords.insert("int");
    keywords.insert("float");
    keywords.insert("double");
    keywords.insert("string");
    keywords.insert("char");

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') continue;

        if (isIdentifier(s[i])) {
            string temp = "";

            while (i < s.size() && s[i] != ' ' && isIdentifier(s[i])) {
                temp += s[i];
                i++;
            }

            if (keywords.find(temp) != keywords.end()) {
                cout << temp << " is keyword\n";
            } else {
                cout << temp << " is identifier\n";
            }
        } 
        if (isOperator(s[i])) {
            cout << s[i] << " is Operator\n";
        }
    }
}
