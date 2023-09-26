#include<iostream>
#include<conio.h>
#include<time.h>
#include<string>
using namespace std;

int list();
int deposit();
void withdraw();
void transferamount();
void checkdetails();
void checkBalance();
int timing();
void end();
int ch,totalamount=10000,depoamo,withamo,transamo;
int acc,amnt;
char a[50];
char b[50];
int main()
{
  system("cls");
 cout<<"\nEnter your name: ";
 gets(a);
 cout<<"\nEnter your account number: ";
 cin>>acc;
 while(1)
 {
   system("cls");
   switch(list())
   {
     case 1:
        deposit();
        cout<<"Your Amount is Deposit and Availbel Balance is : "<<totalamount<<endl;
        cout<<endl;
        timing();
        break;

     case 2:
        withdraw();
        if (withamo<=totalamount)
            cout<<"Your Amount is Withdraw and Availbel Balance is :"<<totalamount<<endl;
            cout<<endl;
            timing();
        break;

     case 3:
        transferamount();
         
        if (transamo<=totalamount);
           cout<<"Your Amount is Transfer and Availbel Balance is :" <<totalamount<<endl;
           cout<<endl;
           timing();
        break;

     case 4:
        checkdetails();
        break;

     case 5:
        checkBalance();
        break;

     case 6:
       system("CLS");
        end();
        getch();
        exit(0);

     default:
        system("CLS");
        cout<<"\n*****Invalid Choice*****";
        cout<<"\nPress any key twice to choose again..";
        getch();
        break;
    } //---------------------------------end of switch
  getch();
 }//-------------------------------------end of while
}

int list()
{
  
  cout<<"\n**********--> WELCOME "<<a<<" <--**********"<<endl;
  cout<<"\n1. Deposit Amount";
  cout<<"\n2. Withdraw Amount";
  cout<<"\n3. Transfer Amount";
  cout<<"\n4. Check details";
  cout<<"\n5. Check Balance";
  cout<<"\n6. Exit"<<endl;
  
  cout<<"\nEnter your choice <e.g- 1 to Deposit Amount>: "<<endl;
  cin>>ch; 
 
  return(ch);
}


int deposit()
{ 
    timing();
    cout<<endl;
    cout<<"\nEnter the amount you want to Deposit: ";
    cin>>depoamo;
    totalamount += depoamo;
}
void withdraw()
{
    timing();
    cout<<endl;
    cout<<"\nEnter the amount you want to Withdraw: ";
    cin>>withamo;
      if (withamo<=totalamount)
        totalamount-=withamo;
      else
        cout<<"\n*****Insufficient Balance*****";
}
void transferamount()
{
    timing();
    cout<<endl;
    cout<<"Enter Transection name: ";
    cin>>b;
    cout<<"Enter Transection account number: ";
    cin>>amnt;
    cout<<"\nEnter the amount you want to Transfer: ";
    cin>>transamo;   
      if (transamo<=totalamount)
        totalamount-=transamo;
      else
        cout<<"\n*****Insufficient Balance*****";
}
void checkdetails()
{
    cout<<"\nYour Banking Name      : "<<a; 
    cout<<"\nTotal Amount           : "<<totalamount; 
    cout<<"\nTotal Deposited Amount : "<<depoamo; 
    cout<<"\nTotal Withdrawn Amount : "<<withamo; 
    cout<<"\nTotal Transfered Amount: "<<transamo; 
}
void checkBalance()
{
    cout<<"\nYour Banking Name      : "<<a; 
    cout<<"\nTotal Amount           : "<<totalamount; 
}
int timing() 
{
  
    int countdown = 10; // 30 seconds timer
    clock_t startTime = clock();

    while (countdown > 0)
    {
        if (_kbhit()) // Check if a key is pressed
        {
            char key = _getch(); // Get the pressed key
            if (key != '\0')    // Ignore special keys
                break;         // Exit the loop if any key is pressed
        }

        clock_t currentTime = clock();
        double elapsedSeconds = double(currentTime - startTime) / CLOCKS_PER_SEC;

        if (elapsedSeconds >= 1.0)
        {
            cout << " \rTime remaining: " << countdown << " second";
            countdown--;
            startTime = currentTime; // Reset the start time
        }
    }

    if (countdown == 0)
    {
        cout << "\rTimeout! Returning to the main menu..." << endl;
        totalamount =10000;
        return main();
    }
}

void end()
{
    cout<<"\n**********************************************\n";
    cout<<endl;
    cout<<"\n* Your Name                : "<<a;
    cout<<"\n* Account Number           : "<<acc;
    cout<<"\n* Total Amount             : "<<totalamount;
    cout<<"\n* Total Deposited Amount   : "<<depoamo;
    cout<<"\n* Total Withdrawn Amount   : "<<withamo;
    cout<<"\n* Transfered Name          : "<<b;
    cout<<"\n* Transfered Account Number: "<<amnt;
    cout<<"\n* Total Transfered Amount  : " <<transamo;
    cout<<endl;
    cout<<"\n   *****Thanks For Using ATM Machine*****";
    cout<<"\n******************Thanks*******************"; 
}