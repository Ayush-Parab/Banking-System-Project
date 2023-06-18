#include<iostream>
#include<cmath>
#include<fstream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

class Account
{
    private:
    string FirstName;
    string LastName;
    int balance;
    int AccountNumber;
    static int counter;

    public:
    Account();
    Account(string FirstName, string LastName, int balance, int AccountNumber);
    void setFirstName(string FirstName);
    void setLastName(string LastName);
    void setBalance(int balance);
    void setAccountNumber(int AccountNumber);
    void deposit(int deposit);
    void withdraw(int withdraw);
    int getBalance();
    void getDetails();
    int getAccountNumber();
    void display();
    friend ofstream & operator <<(ofstream &fout, Account &A);
    friend ifstream & operator >>(ifstream &fin, Account &A);

};
int Account::counter=0;

int main()
{
    vector<Account> v;
    Account A;
    int choice=5;
    string firstname,lastname;
    int balance,deposit,withdraw;
    int acn;
    int accountsmade=0;

    ifstream fin;
    fin.open("TotalAccounts.txt");
    fin>>accountsmade;
    fin.close();
    fin.open("Account.txt");
    while(!fin.eof())
    {
        fin>>A;
        v.push_back(A);

    }
    fin.close();
    v.erase(v.end());

    cout<<"This is my first cpp project!"<<endl;
    cout<<endl;

    while(choice>0 && choice<7)
    {
        cout<<"1.Open account"<<endl;
        cout<<"2.Balance enquiry"<<endl;
        cout<<"3.Deposit"<<endl;
        cout<<"4.Withdraw"<<endl;
        cout<<"5.Close an account"<<endl;
        cout<<"6.Show all accounts"<<endl;
        cout<<"7.Quit"<<endl;
        cout<<endl;

        cout<<"Enter your choice:";

        cin>>choice;

        switch(choice)
        {
            case 1: //Open account
            {
                accountsmade++;
                cout<<"Enter first name:";
                cin>>firstname;
                A.setFirstName(firstname);
                cout<<"Enter last name:";
                cin>>lastname;
                A.setLastName(lastname);
                cout<<"Enter initial balance:";
                cin>>balance;
                A.setAccountNumber(accountsmade);
                A.setBalance(balance);
                A.getDetails();
            
                v.push_back(A);
            
                break;
            }

            case 2: //Balance enquiry
            {
                cout<<"Enter account number:";
                cin>>acn;
                vector<Account>::iterator it;
                for(it=v.begin();it!=v.end();it++)
                {
                    A=*it;
                    if(A.getAccountNumber()==acn)
                    {
                        cout<<"The balance is:"<<A.getBalance()<<endl;
                        cout<<endl;
                    }
                }           
                break;
            }

            case 3: //Deposit
            {
                cout<<"Enter account number:";
                cin>>acn;
                cout<<"Enter the amount you want to deposit:";
                cin>>deposit;
                cout<<endl;
                vector<Account>::iterator it;
            
                for(it=v.begin();it!=v.end();it++)
                {
                    A=*it;
                    if(A.getAccountNumber()==acn)
                    {
                        A.deposit(deposit);
                        v.erase(it);
                        v.insert(it,A);
                    }
                }
            
                break;
            }

            case 4: //Withdraw
            {
                cout<<"Enter account number:";
                cin>>acn;
                cout<<"Enter the amount you want to withdraw:";
                cin>>withdraw;
                cout<<endl;
                vector<Account>::iterator it;
                for(it=v.begin();it!=v.end();it++)
                {
                    A=*it;
                    if(A.getAccountNumber()==acn)
                    {
                        A.withdraw(withdraw);
                        v.erase(it);
                        v.insert(it,A);
                    }
                }           
                break;
                }

            case 5: //Close account
            {
                cout<<"Enter account number:";
                cin>>acn;
                cout<<endl;
                vector<Account>::iterator it;
                for(it=v.begin();it!=v.end();it++)
                {
                    A=*it;
                    if(A.getAccountNumber()==acn)
                    {                   
                        v.erase(it);                    
                    }
                }
                break;
            }

            case 6: //Show all accounts            
            {
                vector<Account>::iterator it;
                for(it=v.begin();it!=v.end();it++)
                {
                     A=*it;
                    if(A.getAccountNumber()==0)
                    {
                        v.erase(it);
                    }
                }
            }
                cout<<endl;
                cout<<"List of bank accounts:"<<endl;
                cout<<endl;
                {vector<Account>::iterator it;
            
                for(it=v.begin();it!=v.end();it++)
                {
                    A=*it;
                    A.display();               
                    cout<<endl;
                }
                break;
                }

            case 7: //quit
            break;

            default:
            cout<<"Invalid option";
            break;
        }

    }
    {
        vector<Account>::iterator it;
        for(it=v.begin();it!=v.end();it++)
            {
                A=*it;
                if(A.getAccountNumber()==0)
                    {
                        v.erase(it);
                    }
            }
    }
    
            ofstream fout;
            fout.open("Account.txt",ios::trunc);
            vector<Account>::iterator it;
            for(it=v.begin();it!=v.end();it++)
            {
                A=*it;
                fout<<A;
            }
            fout.close();

            fout.open("TotalAccounts.txt",ios::trunc);
            fout<<accountsmade;
            fout.close();
   
    return 0;
}

Account::Account()
{
    
    FirstName="null";
    LastName="null";
    balance=0;
    AccountNumber=0;
}

Account::Account(string FirstName, string LastName, int balance, int AccountNumber)
{
    setFirstName(FirstName);
    setLastName(LastName);
    setBalance(balance);
    setAccountNumber(AccountNumber);
}

void Account::setFirstName(string FirstName)
{
    this->FirstName=FirstName;
}

void Account::setLastName(string LastName)
{
    this->LastName=LastName;
}

void Account::setBalance(int balance)
{
    this->balance=balance;
}

void Account::setAccountNumber(int AccountNumber)
{
    this->AccountNumber=AccountNumber;
}

void Account::deposit(int deposit)
{
    balance=balance+deposit;
}

void Account::withdraw(int withdraw)
{
    if(withdraw<=balance)
    {
        balance=balance-withdraw;
    }
}

int Account::getBalance()
{
    return balance;
}

void Account::getDetails()
{
    counter++;
    cout<<endl;
    cout<<"First name:"<<FirstName<<endl;
    cout<<"Last Name:"<<LastName<<endl;
    cout<<"Balance:"<<balance<<endl;
    cout<<"Account number:"<<AccountNumber<<endl;
    cout<<endl;
}

int Account::getAccountNumber()
{
    return AccountNumber;
}

void Account::display()
{
    cout<<"First name:"<<FirstName<<endl;
    cout<<"Last Name:"<<LastName<<endl;
    cout<<"Balance:"<<balance<<endl;
    cout<<"Account number:"<<AccountNumber<<endl;
}

ofstream & operator <<(ofstream &fout, Account &A)
{
    fout<<A.FirstName<<" "<<A.LastName<<" "<<A.balance<<" "<<A.AccountNumber<<endl;
    return fout;
}

ifstream & operator >>(ifstream &fin, Account &A)
{
    fin>>A.FirstName>>A.LastName>>A.balance>>A.AccountNumber;
    return fin;
}


