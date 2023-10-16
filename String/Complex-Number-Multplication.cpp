class Solution {
// YaY it worked, i mean it took me an hour to solve but hey it worked at least.
public:
    string complexNumberMultiply(string num1, string num2) {
        string dig1 = "";string im1 = "";
        string dig2 = "";string im2 = "";
        int i =0; 
        while(num1[i] != '+'){
            dig1 += num1[i++];
        }
        i++;
        while(i < num1.size() - 1){
            im1 += num1[i++];
        }
        i = 0; 
        while(num2[i] != '+'){
            dig2 += num2[i++];
        }
        i++;
        while(i < num2.size() - 1){
            im2 += num2[i++];
        }
        string exp;
        vector<string> a;
        exp = to_string((stoi(dig1) * stoi(dig2)));
        a.push_back(exp);
        exp = to_string(stoi(dig1) * stoi(im2));
        a.push_back(exp);
        exp = to_string(stoi(dig2) * stoi(im1));
        a.push_back(exp);
        exp = to_string((stoi(im2) * stoi(im1)) * -1);
        a.push_back(exp);
        string ans = "";
        ans += (to_string(stoi(a[0]) + stoi(a[3])));
        ans += "+";
        ans += (to_string(stoi(a[1]) + stoi(a[2])));
        ans += "i";
        return ans;
    }
};
