//Designing the ATM facilities
#include<iostream>
using namespace std;
//Creating the Class Bank
class Cbank
{
protected:
        string name,account_type;
    	double balance,transfer,withdraw,account_no,deposit,interest;
public:
        double withdraw_amount(double);
        double balance_amount( double);
        void setValues();
        void getName();
        void getBalance();
        void calculate_interest();
        void getAccount_Type();
        void transfer_Amount(Cbank customer[],int,int);
        bool check_account(int,int,Cbank customer[],int &cnt);
        Cbank()
        {
            balance=transfer=withdraw=deposit=interest=0;
        }
};
//Setting the Customer Details
void Cbank::setValues()
{
    cout<<"\nEnter the Customer Name:";
    cin>>name;
    cout<<"\nEnter the Amount to be Deposited:";
    cin>>deposit;
    balance_amount(deposit);
    cout<<"\nEnter the Account no:";
    cin>>account_no;
    //cout<<"\nEnter the Account Type:";
    //cin>>account_type;
}
//Getting the Customer Name
void Cbank::getName()
{
    cout<<"\nName:";
    cout<<name;
}
//Getting the Balance
void Cbank::getBalance()
{
    cout<<"\nThe Balance is\t";
    cout<<balance;
}
//Getting the Account Type
void Cbank::getAccount_Type()
{
    cout<<"\nThe Account Type:";
    cout<<account_type;
}
//Setting the Balance
double Cbank::balance_amount(double amount)
{
    balance=balance+amount;
}
//Withdrawing the Balance
double Cbank::withdraw_amount(double amount)
{
    if(amount>balance)
    {
        throw" Amount greater than the Balance";
    }
    else
    {
                balance=balance-amount;
    }
}
//Transfer Amount
void Cbank::transfer_Amount(Cbank customer[],int n,int temp)
{
    int acc,i,cnt,money;
    cout<<"\nEnter the Account Number to which money has to be transfered";
    cin>>acc;
        for(i=0;i<n;i++)
        {
            if(customer[i].account_no==acc)
            {
                cnt=1;
                break;
            }

        }
        if(cnt==1)
          {
              cout<<"\nEnter the amount to be transferred";
              cin>>money;
              cout<<"\nThe New Balance:";
              customer[temp].withdraw_amount(money);
              customer[i].balance_amount(money);
              customer[i].getBalance();
          }

}
//Checking the Account No
bool Cbank::check_account(int acc_no,int n,Cbank customer[],int &cnt)
{
    int i;
    bool flag;
    for(i=0;i<n;i++)
    {
        ++cnt;
        if(customer[i].account_no==acc_no)
        {
            flag=1;
            break;
        }
        else
        {
            flag=0;
        }
    }
    return flag;
}
//Calculating the interest
void Cbank::calculate_interest()
{
    balance=balance+(interest*balance);
}
//Creating the Cheque Account class
class ChequeAccount:public Cbank
{
protected:
    double limit;
public:
            ChequeAccount()
            {
                limit=0;
            }

};
int main()
{
    int i=0,n,acc_no,choice;
    static int count=-1;
    double amount;
    bool check;
    //Creating Array of Objects for the Class Bank
    Cbank customer[5],m;
    cout<<"\n\t\t\t\tWelcome to World Bank";
    cout<<"\nEnter the No of Customers";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter the Customer Details \n";
        customer[i].setValues();
    }
    do
    {
        cout<<"\nEnter the Account No to login:";
        cin>>acc_no;
        check=m.check_account(acc_no,n,customer,count);
        if(check==1)
        {
            cout<<"\nWelcome";
            customer[count].getName();
            //customer[count].getAccount_Type();
            do
            {
            cout<<"\n1.Check Balance";
            cout<<"\n2.Deposit Amount";
            cout<<"\n3.Withdraw Amount";
            cout<<"\n4.Transfer Amount";
            try
            {
                    cin>>choice;
                if(choice>4)
                {
                    throw "Invalid Choice";
                }
            }
            catch(const char* msg)
            {
              cerr<<msg;
            }
            switch(choice)
            {
                case 1: cout<<count;
                        customer[count].getBalance();
                        break;
                case 2: cout<<"\nEnter the Amount to be deposited:";
                        cin>>amount;
                        customer[count].balance_amount(amount);
                        customer[count].getBalance();
                        break;
                case 3: cout<<"\nEnter the Amount to be withdrawn:";
                        cin>>amount;
                       try
                       {
                        customer[count].withdraw_amount(amount);
                        customer[count].getBalance();
                       }
                        catch(const char* msg)
                        {
                          cerr<<msg;
                        }
                        break;
                case 4:customer[count].transfer_Amount(customer,n,count);
                        break;
            }
                cout<<"\nPress 1 to continue or any number to exit";
                cin>>choice;
            }while(choice==1);
        }
        else
        {
            cout<<"\nInvalid Account No";
        }
        cout<<"\nPress 1 to login as other user or any number to exit";
        cin>>choice;
        count=-1;
    }while(choice==1);
return 0;
}
