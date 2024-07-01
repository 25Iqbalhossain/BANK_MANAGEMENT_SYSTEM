#include<bits/stdc++.h>
using namespace std;

class Bank_account
{
public:
    string account_holder;
    string address;
    int age;
    int account_number;
protected:
    int  account_balance;
private:
    string password;
public:
     Bank_account(string account_holder,string address,int age,string password)
    {
        this->account_number=account_number;
        this->address=address;
        this->age=age;
        this->password=password;
        this->account_number=rand()%1000000000;
        this->account_balance=0;
        cout<<"Your account Number is "<<this->account_number<<endl;
    }
    int show_balance(string password){

    if(this->password==password){
        return  this->account_balance;
    }
    else{
        return -1;
    }
    }

    void add_money(string password,int amount){
    if(this->password==password){
        this->account_balance+=amount;
        cout<<"Add money successful "<<endl;
    }
    else{
        cout<<"Password Didn't match ";
    }
    }

      void deposit_money(string password,int amount){
    if(this->password==password){
        this->account_balance-=amount;
        cout<<"Add money successful "<<endl;
    }
    else{
        cout<<"Password Didn't match ";
    }
    }
    friend class Mycash;
};

class Mycash{
protected:
    int balance;
public:
    Mycash(){
    this->balance=0;
    }
    void add_money_from_bank(Bank_account *myAccount,string password,int amount){

    if(myAccount->password==password){
        this->balance += amount;
        myAccount->account_balance -= amount;
        cout<<"Add money from bank is successful"<<endl;
    }
    else{
        cout<<"Password Didn't Match "<<endl;
    }
    }
  int show_balance(){

  return balance;

  }
};

Bank_account* CreateAccount(){

string account_holder,address,password;
int age;
cout<<"Create Account "<<endl;
cin>>account_holder>>address>>age>>password;
Bank_account *myAccount= new  Bank_account(account_holder,address,age,password);// for dynamic memory ;

return myAccount;
}


void add_money(Bank_account*myAccount){

string password;
int amount;
cout<<"ADD MONEY"<<endl;
cin>>password>>amount;
myAccount->add_money(password,amount);
cout<<"Your bank balance is "<<myAccount->show_balance("abc")<<endl;
}


void deposit_money(Bank_account*myAccount){
string password;
int amount;
cout<<"DEPOSIT MONEY"<<endl;
cin>>password>>amount;
myAccount->deposit_money(password,amount);
cout<<"Your bank balance is "<<myAccount->show_balance("abc")<<endl;
}


void add_money_from_bank(Mycash *mycash ,Bank_account *myAccount){
string password;
int amount;
cout<<"ADD MONEY FROM BANK "<<endl;
cin>>password>>amount;
 mycash->add_money_from_bank(myAccount,password,amount);
 cout<<"Your bank balance is "<<myAccount->show_balance("abc")<<endl;
 cout<<"MyCash Balance is "<<mycash->show_balance()<<endl;

}



int main(){

Bank_account *myAccount=CreateAccount();

deposit_money(myAccount);
Mycash *mycash=new Mycash();

Flag:
    cout<<"Select Option"<<endl;
    cout<<"1.Add Money to Bank"<<endl;
    cout<<"2.Deposit Money from Bank"<<endl;
    cout<<"3.Add money to Mycash from Bank"<<endl;

    int option;
    cin>>option;
     if(option==1){
        add_money(myAccount);
     }
    else if (option ==2){
        deposit_money(myAccount);
    }
    else if (option==3){
       add_money_from_bank(mycash,myAccount);
    }
    else{
        cout<<"Invalid option"<<endl;
    }
    goto Flag;

return 0;
}

