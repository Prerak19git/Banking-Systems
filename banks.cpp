/******************************************************************************

      BANKING SYSTEM !!
      
*******************************************************************************/
#include <bits/stdc++.h>
#include<ctime>
using namespace std;

unordered_set<long long>allids;


// int get_age ( string dateandtime)
// {
    
// }

class Customer
{
  public:
  string name,email; 
  long long customer_id, contact_number;
  vector<string>addr;
  vector<int>DOB;
  
  public:
  Customer();
 
  
  
};

vector<Customer>listofcustomers;

Customer::Customer()
 {   cout<<"Enter your name ";
      getline(cin.ignore(),name);
      cout<<"Contact details - ";
      cin>> contact_number;
      cout<<"\n";
      cout<<"Enter your address : \n";
      cout<<"STATE ? ";
      string x;
      getline(cin.ignore(),x);
      addr.push_back(x);
      cout<<"CITY ? ";
      getline(cin.ignore(),x);
      addr.push_back(x);
      
      cout<<endl;
      cout<<"Locality ? "<<endl;
      getline(cin.ignore(),x);
      addr.push_back(x);
      
      cout<<"HOUSE ? "<<endl;
      getline(cin.ignore(),x);
      addr.push_back(x);
      reverse(addr.begin(), addr.end());
      cout<<endl;
      long long r;
      cout<<"ENTER YOUR DATE OF BIRTH\n";
      cout<<"DAY? ";
      cin>>r;
      DOB.push_back(r);
      
      cout<<endl;
      cout<<"MONTH ? "<<endl;
      cin>>r;
      DOB.push_back(r);
      cout<<" YEAR ? "<<endl;
      cin>>r;
      DOB.push_back(r);
      cout<<endl;
  
      
      cout<<"Enter your email address "<<endl;
      cin>>email;
      
      customer_id = rand();
      while(allids.find(customer_id) != allids.end())
      {
          customer_id =  rand();
      }
      
    
      
      allids.insert(customer_id);
      listofcustomers.push_back(*this);
      cout<<"Your Customer Id is "<<customer_id<<endl;
      
  }

class Account
{
    public:
        long long account_number,customer_id ,balance;
        string name;
        vector<int>start_date;
        
    public:
      void add_account()
      {
         cout<<" Please enter your customer_id : ";
         cin>>customer_id;
         
         account_number = customer_id + 3*rand();
         
         cout<<"how much money you want to deposit to start with ? ";
         cin>>balance;
         
         cout<<"What is the date today? DD MM YYYY/n";
         for( int i =0; i <3; i++)
         {
             int y;
             cin>>y;
             start_date.push_back(y);
         }
         
         for( auto customer : listofcustomers)
         {
            
             if( customer.customer_id == customer_id)
             {

                 name = customer.name;
             }
         }
         
      }
      
      void deleteaccount(long long number)
      {
          
      }
      
      void update_account( long long number)
      {
          
      }
    
};


class Savings_Account : public Account
{ 
    
    private:
    int cardpin;
    
    public:
    long long NRV,penalty_nrv;
    long double Interest_Rate;
    long long Card_number;
    
    public:
    int get_cardpin()
    {
        return cardpin;
    }
    
    
    Savings_Account();

    
};

vector<Savings_Account>savingaccounts;

Savings_Account::Savings_Account()
    {
        add_account();
        
        if( balance <10000)
        {
            cout<<" Your acount cannot be created as your deposit is less then 10000";
            cout<<savingaccounts.size();
            return;
        }
        NRV = 100000;
        penalty_nrv = 1000;
        Interest_Rate = 6;
        
        Card_number = customer_id + 2*rand();
        
        cout<<" your ATM card number is "<<Card_number;
        cout<<endl<<"please set up yout ATM pin, enter 4 digits only : ";
        cin>>cardpin;
        
       
        // cout<<"the interest_rate of this is "<<(*this).Interest_Rate<<endl;
        savingaccounts.push_back(*this);
         cout<<"Your Savings Account has been setup\n";
        // cout<<((savingaccounts[0])).Interest_Rate<<endl;
        
    }




class Current_Account : public Account
{
    public :
    long long NRV=500000;
    long long penalty_nrv = 5000;
    long long age_limit = 18;
    
    public:
    Current_Account();
  
    
};

vector<Current_Account>currentaccounts;

Current_Account::Current_Account()
{
    add_account();
    int age_of_cust  = 0;
    // for( auto cust : listofcustomers )
    // {
    //     if( cust.customer_id == customer_id)
    //     {
    //       age_diff = get_age(dateandtime,cust.DOB);        
    //     }
    // }
    // if(age_of_cust < 18)
    // {
    //  cout<<"Your account cannot be setup as your age is less than 18 ";
    //     return;   
    // }
    
    
    if( balance < 100000)
    {
        cout<<"Your account cannot be setup as your deposit is less than 100000";
        return;
    }
    
    currentaccounts.push_back(*this);
     cout<<"Your Current Account has been setup\n";
    
    return;
    
}


// class Loan_Account : public Account
// {
//     public :
//     long long NRV=500000;
//     long long penalty_nrv = 5000;
//     long long age_limit = 18;
    
//     public:
//     Loan_Account();
  
    
// };

// vector<Loan_Account>loanaccounts;

// Loan_Account::Loan_Account()
// {
//     add_account();
//     int age_of_cust  = 0;
//     // for( auto cust : listofcustomers )
//     // {
//     //     if( cust.customer_id == customer_id)
//     //     {
//     //       age_diff = get_age(dateandtime,cust.DOB);        
//     //     }
//     // }
//     // if(age_of_cust < 18)
//     // {
//     //  cout<<"Your account cannot be setup as your age is less than 18 ";
//     //     return;   
//     // }
    
    
//     if( balance < 100000)
//     {
//         cout<<"Your account cannot be setup as your deposit is less than 100000";
//         return;
//     }
    
//     currentaccounts.push_back(*this);
//      cout<<"Your Current Account has been setup\n";
    
//     return;
    
// }

class Transaction
{
  public :
  int king;
  vector<int>date, description;
  long long amount;
  
  public:
  Transaction();
  
};

vector<Transaction>transactions;

int atm_check( long long acc_num, vector<int>curr_date, long long transaction_amt)
{
    for( auto trs : transactions)
    {
        long long ct_month=0,in_day=0;
        
        if(trs.date[2]!= curr_date[2] or trs.date[1]!= curr_date[1]){continue;}
        
        if(trs.decription[0] == "ATM" and trs.desription[1] ==to_string(acc_num))
        {
          ct_month ++;
         
        }
        
        if(trs.date[0] == curr_date[0] and trs.kind == 0)
        {
            in_day += trs.amount;
        }

    
    }
    
    if( tr.amount >= 50000){ return -1;}
    else return ct_month;
}

Transaction::Transaction()
{
  cout<<"enter your Account Number\n";
  
  long long n;
  cin>>n;
  
  cout<<"What is today's date ? DD MM YYYY\n";
  for( int i=0; i <3; i++)
  {
      int x;
      cin>>x;
      date.push_back(x);
  }
  
  string tp = "S";
  
  for( auto it : currentaccounts)
  {
      if( it.account_number == n)
      {
          tp = "C";
      }
  }
  
//   for( auto it : loanaccounts)
//   {
//       if( it.account_number == n)
//       {
//           tp = "L";
//       }
//   }

 if( tp == 'S')
 {
     cout<<"Do you want to make an atm transaction or direct transaction ? A / D\n";
     char x;
     cin>>x;
     
     if( x == 'A')
     {
          long long amount;
             cout<<"Enter amount to be withdrawn : ";
             cin>>amount;
             int checker = atm_check(n, date, amount);
         if( checker != -1)
         {
             cout<<"Enter your 4 digit atm pin:\n";
             int pin;
             cin>>pin;
             
             int correct_pin ;
             for( auto acct : savingaccounts )
             {
                 if(acct.account_number == n)
                 {
                     correct_pin = acct.get_cardpin();
                 }
             }
             
             if(pin != correct_pin)
             {
                 cout<<"Wrong Pin Entered. No transaction allowed!\n";
                 return;
             }
             
             int curr_bal=0;
             description = {"ATM",to_string(n)};
             for( auto &it : savingaccounts)
             {
                 if(it.account_number == n)
                 {
                     it.balance -= amount;
                     curr_bal = it.balance;
                     
                     if(checker >=5 )
                     {
                         it.balance -= 500;
                     }
                 }
                
             }
             
            
             
             kind = 0;
             
             transactions.push_back(*this);
             cout<<"Transaction was successfull !\n";
             cout<<"Your current balance is "<<curr_bal<<endl;
         }
         else{cout<<"You cannot transact! Sorry."; return;}
         
     }
     
 }
  
    
};


void get_details( long long cust_id)
{
    // for( auto &cust : listofaccounts)
    // {
    //     if( cust.customer_id == cust_id)
    //     {
    //         for( auto it : cust)
    //         {
    //             cout<<it<<endl;
    //         }
    //     }
    // }
    return;
}

int main()
{
  int t;
  cout<<"customers_in_queue : ";
  cin>>t;
  
  while( t--)
  {
      cout<<"Are you an existing customer ? Y / N "<<endl;
      char x;
      cin>>x;
     
      if( x == 'N')
      {
         Customer curr;  
        //  cout<<"Your customer id is "<< curr.customer_id<<endl<<endl;
      }
     
      cout<<" What service would you like to use ?\n"<<endl;
      cout<<" 1. Open a new account\n";
      cout<<" 2. Details of an existing account\n";
      cout<<" 3. Details of an existing user \n";
      cout<<" 4. Making a transaction\n";
      cout<<" 5. Exit"<<endl<<endl;
      int option;
      
      cin>> option;
      
      switch(option)
      {
          case 1 :
          { 
              cout<<"Which type of account you want to open ?\n";
              cout<<" Savings / Current / Loan"<<endl;
              string acc_type;
              cin>>acc_type;
              
              if( acc_type == "Savings")
              {
                  Savings_Account curr_customer;
              }
              
              else if (acc_type == "Current")
              {
                  Current_Account curr_customer;
                  
              }
              
              else
              {
                //   Loan_Account curr_customer;
              }
              
              
              break;
          }
          
          case 2:
          {
              cout<<"Please enter your customer-id"<<endl;
              long long id;
              cin>>id;
              vector<pair<long long, string>>customers_accounts;
              
              for( auto acct : savingaccounts )
              {
                  if(acct.customer_id == id)
                  {
                      customers_accounts.push_back({acct.account_number,"SAVINGS"});
                  }
              }
              
              for( auto acct : currentaccounts )
              {
                  if(acct.customer_id == id)
                  {
                      customers_accounts.push_back({acct.account_number,"CURRENT"});
                  }
              }
            //   for( auto acct : loanaccounts )
            //   {
            //       if(acct.customer_id == id)
            //       {
            //           customers_accounts.push_back({acct.account_number,"LOAN"});
            //       }
            //   }
              if( customers_accounts.size() == 0)
              {
                  cout<<"You dont have any accounts under this customer_id !";
                  break;
              }
              cout<<"You have the following accounts : "<<endl<<endl;
              for( int i = 0; i <customers_accounts.size(); i++)
              {
                  cout<< i+1 <<". "<<customers_accounts[i].first<<" "<<customers_accounts[i].second<<endl;
              }
             cout<<"Which accounts details would you like to see ? "<<endl;
             int index;
             cin>>index;
             
             while( index > customers_accounts.size())
             {
                 cout<<"please enter a valid index of account ! "<<endl;
                 cin>>index;
             }
             
              if( customers_accounts[index-1].second == "SAVINGS")
              {
                  for( auto account : savingaccounts)
                  {
                      if(account.account_number == customers_accounts[index-1].first)
                      {
                          cout<<"here are your account details"<<endl;
                          
                          cout<<" Account holder's name :  " <<account.name<<endl;
                          cout<<" Account number :  " <<account.account_number<<endl;
                          cout<<" Account Customer ID :  " <<account.customer_id<<endl;
                          cout<<" Account Balance :  " <<account.balance<<endl;
                          cout<<" Account Start Date :  ";
                          cout<<account.start_date[0]<<"/"<<account.start_date[1]<<"/"<<account.start_date[2]<<endl;
                          
                          cout<<" Card Number :  " <<account.Card_number<<endl;
                          
                      }
                  }
              }
              else  if( customers_accounts[index-1].second == "CURRENT")
              {
                  for( auto account : savingaccounts)
                  {
                      if(account.account_number == customers_accounts[index-1].first)
                      {
                          cout<<"here are your account details"<<endl;
                          
                          cout<<" Account holder's name :  " <<account.name<<endl;
                          cout<<" Account number :  " <<account.account_number<<endl;
                          cout<<" Account Customer ID :  " <<account.customer_id<<endl;
                          cout<<" Account Balance :  " <<account.balance<<endl;
                       cout<<" Account Start Date :  ";
                          cout<<account.start_date[0]<<"/"<<account.start_date[1]<<"/"<<account.start_date[2]<<endl;
                          

                          
                      }
                  }
              }
              else
              {
                  continue;
              }
              
              
              
              break;
          }
          
          case 3:
          {
            cout<<"Enter your customer id "<<endl;
            long long id;
            cin>>id;
            
            for( auto cust : listofcustomers)
            {
                if( cust.customer_id == id)
                {
                    cout<<" Customer's name is :"<< cust.name<<endl;
                    cout<<"Customer's email is :"<<cust.email<<endl;
                    cout<<"Customer's DOB is : ";
                    cout<<cust.DOB[0]<<"/"<<cust.DOB[1]<<"/"<<cust.DOB[2]<<endl;
                    
                    cout<<"Customer's adress is : ";
                    cout<<cust.addr[0]<<","<<cust.addr[1]<<","<<cust.addr[2]<< ","<<cust.addr[3]<<endl;
                    
                    cout<<"Customer's contact : "<<cust.contact_number<<endl;
                    
                }
            }
            
          }
      }
      
      
  }
  
  
}
