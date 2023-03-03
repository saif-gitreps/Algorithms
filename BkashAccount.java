public class BkashAccount{
    int balance;
    String name;
    public BkashAccount(String name,int balance){
        this.balance = balance;
        this.name = name;
    }
    void moneyTransfer(BkashAccount recipent,int amount){
        if(balance>amount){
            this.balance -= amount;
            recipent.balance += amount;
            System.out.println("Transfer successful");
        }
        else{
            System.out.println("Not sufficient funs");
        }
    }
    public static void main(String args[]){
        BkashAccount sender = new BkashAccount("SAIF",20000);
        BkashAccount receiver = new BkashAccount("JALAL",444);
        sender.moneyTransfer(receiver,300);
    }
}

