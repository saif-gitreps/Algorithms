class Bank {

private:
// idk why i am getting heap buffer overflow(my code is trying to access unavailable memories)
public:
vector<long long> balance; 
    Bank(vector<long long>& bal) {
        for(auto x: bal){
            this->balance.push_back(x);
        }
    }
    bool transfer(int account1, int account2, long long money) {
        if(this->balance[account1-1]-money<0){
            return false;
        }
        this->balance[account1-1] -= money;
        this->balance[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        int n = this->balance.size();
        if(account>n || account<=0){
            return false;
        }
        this->balance[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        int n = this->balance.size();
        if(account>n || account<=0){
            return false;
        }
        this->balance[account-1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */


class Bank {

private:
// okay i figured out my mistake, so my mistake was i didnt add some conditions in the
// transfer and depoist methods.
public:
vector<long long> balance; 
    Bank(vector<long long>& bal) {
        this->balance = bal;
    }
    bool transfer(int account1, int account2, long long money) {
        int n = this->balance.size();
        if(account1>n || account1<=0){
            return false;
        }
        if(account2>n || account2<=0){
            return false;
        }
        if(this->balance[account1-1]-money<0){
            return false;
        }
        this->balance[account1-1] -= money;
        this->balance[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        int n = this->balance.size();
        if(account>n || account<=0){
            return false;
        }
        this->balance[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        int n = this->balance.size();
        if(account>n || account<=0){
            return false;
        }
        if(this->balance[account-1]<money){
            return false;
        }
        this->balance[account-1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
