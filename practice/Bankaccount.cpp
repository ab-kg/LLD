#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Encapsulation

class BankAccount {
private:
    string holdername;
    double amount;
    int transactionCount = 0;
public:
    BankAccount(const string& n , double a) : holdername(n) , amount(a){
        if( amount < 0 ){
            throw invalid_argument("Balance cannot be negative");
        }
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Deposit must be positive");
        }
        this->amount += amount;
        transactionCount++;
    }

    bool transferTo(BankAccount& reciever , double amt ){
        if (amt <= 0 || amt > amount) {
            return false;
        }

        if (this == &reciever) {
            return false;
        }
        if(amt<= amount ){
            amount -= amt ;  
            reciever.deposit(amt) ;
            transactionCount++ ; 
            return true ;
        }
        return false;
    }

    bool withdraw(double am) {
        if (am <= 0 || am > amount) {
            return false;
        }
        amount -= am ;
        transactionCount++ ; 
        return true ;
    }

    double getBalance() const {
        return amount ; 
    }
};


int main(){
    string n = "abhishek";
    BankAccount one = BankAccount(n , 100);

    string n2 = "athul";
    BankAccount two = BankAccount(n2 , 200);

    one.transferTo(two , 50);

    cout << one.getBalance() << endl;
    cout << two.getBalance() << endl; 

}