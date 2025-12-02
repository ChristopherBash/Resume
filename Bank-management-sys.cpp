// Bank-management-sys.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>

using namespace std;

//stucture to represnt bank account

struct bankmanagement {

	int accountnub; //Account Number
    char accountT; //Account Type
    string name, address; //Account Name,Address
	float amount; //Account Balance

    // Function declarations for various operations on bank accounts
    bool checkavailabilty(); // Check if the account slot is available
    bool searchaccount(int); // Search for an account by account number
    void newaccount(); // Create a new bank account
    void deposit(); // Deposit money into an account
    void withdraw(); // Withdraw money from an account
    void check_account(); // Display account details
    void modifyaccount(); // Modify account information
    void deleteaccount(); // Delete an account

    // Constructor to initialize account attributes
    bankmanagement()
    {
        
        accountnub = 0;
        name = "";
        address = "";
        accountT = '\0';
        amount = 0.0;
    }

};

//Main function
int main()
{
    bankmanagement b[5];

    int x, an; //variables for user and account number
    bool check; //bool variable to check for account existance


    while (1) {

        system("CLS");
        cout << "========================================" << endl;
        cout << "               Bank Menu                " << endl;
        cout << "     Enter 1 to create new account      " << endl;
        cout << "     ENter 2 to deposit                 " << endl;
        cout << "     Enter 3 to withdraw                " << endl;
        cout << "     Enter 4 to check account           " << endl;                        
        cout << "     Enter 5 to modify                  " << endl;
        cout << "     Enter 6 to delete                  " << endl;
        cout << "     Enter 7 to show all accounts       " << endl;
        cout << "     Enter 8 to exit                    " << endl;

        cout << "     Enter choice number:               " << endl;
        cin >> x;

        switch (x) 
        {

           case 1: // Create a new account
           {

               check = false;
               for (int i = 0; i < 5; i++) 
               {
                   if (b[i].checkavailabilty()) // Check if the account slot is available
                   {
                       check = true;
                       b[i].newaccount(); // Call function to create a new account
                       cout << " working.";
                       break;
                   }
               }

               if (check == false)
                   cout << " Accounts exceeded."; // Notify if maximum accounts limit is reached

               break;
           }

           case 2: // Deposit money into an account
           {
               check = false;
               cout << "Enter account no. :";
               cin >> an;
               for (int i = 0; i < 5; i++)
               {
                   if (b[i].searchaccount(an))
                   {
                       check = true;
                       b[i].deposit();
                       break;
                   }
               }

               if (check == false)
                   cout << "No account found.";
               break;

           }

           case 3: // Withdraw money from an account
           {
               check = false;
               cout << "Enter account no. ";
               cin >> an;
               for (int i = 0; i < 5; i++)
               {
                   if (b[i].searchaccount(an))
                   {
                       check = true;
                       b[i].withdraw();
                   }
               }

               if (check == false)
                   cout << "No account found. ";

               break;

           }

           case 4: // Check account details
           {
               check = false;
               cout << "Enter account no. ";
               cin >> an;
               for (int i = 0; i < 5; i++)
               {
                   if (b[i].searchaccount(an))
                   {
                       check = true;
                       b[i].check_account();
                       break;

                   }
               }

               if (check == false)
                   cout << "No account found";

               break;
           }

           case 5: // Modify account information
           {
               check = false;
               cout << "Enter account no. ";
               cin >> an;
               for (int i = 0; i < 5; i++)
               {
                   if (b[i].searchaccount(an))
                   {
                       check = true;
                       b[i].modifyaccount();
                       break;
                   }
               }

               if (check == false)
                   cout << "No account found. ";

               break;
           }

           case 6: // Delete an account
           {
               check = false;
               cout << " Enter account no. : ";
               cin >> an;
               for (int i = 0; i < 5; i++)
               {
                   if (b[i].searchaccount(an))
                   {
                       check = true;
                       b[i].deleteaccount();
                       break;
                   }

            
               }

               if (check == false)
                   cout << " No account found ."; // Notify if account not found

               break;
           }

           case 7: // Show all accounts
           {
               check = false;
               for (int i = 0; i < 5; i++)
               {
                   if (!b[i].checkavailabilty()) // Check if the account is not empty
                   {

                       check = true;
                       cout << "\nAccount details of " << i + 1 << ":\n ";
                       b[i].check_account(); // Call function to display account details
                       cout << "\n==========================================\n";
                   }
               }

               if (check == false)
                   cout << " No account found ."; // Notify if no accounts are found

               break;
           }

           case 8: // Exit the program
           {
               exit(0); // Terminate the program
           }

        }

        _getch(); //Pause the screen
    }

    return 0;
   
}

// Function to check if the account slot is available
bool bankmanagement::checkavailabilty()
{
    if (accountnub == 0 && name =="" && address =="" && accountT =='\0' && amount == 0.0) {

        return true;
    }
    else {
        return false;
    }
}

// Function to search for an account by account number
bool bankmanagement::searchaccount(int a)
{

    if (accountnub == a)
        return true;
    else
        return false;
}


// Function to create a new account
void bankmanagement::newaccount() {

    cout << "Enter your account no: ";
    cin >> accountnub;

    cout << "Enter your full name: ";
    cin >> name;
 
    cout << "Enter your address: ";
    cin >> address;

    cout << "What type of accout do you want to open saving or checking: ";
    cin >> accountT;

    cout << "Enter how much money you want to deposit: ";
    cin >> amount;

    cout << "Account created successfully! ";
}


// Function to deposit money into an account
void bankmanagement::deposit() {

    float d;
    cout << "\n Enter ammout to deposit: ";
    cin >> d; 
    amount += d;
    cout << "updated..New Ammount = " << amount;
}

// Function to withdraw money from an account
void bankmanagement::withdraw() {

    int wd;
    cout << "\n Enter ammount to withdraw; ";
    cin >> wd;
    if (wd <= amount) {
        amount -= wd;
        cout << "\n Amount is withdrawed.";
    }
    else
    {
        cout << "\n insuffecient funds";
    }

    cout << "\n Remainig ammount: " << amount;
}

// Function to display account details
void bankmanagement::check_account() 
{
    cout << "\n Your name: " << name;
    
    cout << "\n Your address: " << address;

    cout << "\n Account type: " << accountT;

    cout << "\n Ammount: " << amount;

}

// Function to modify account information
void bankmanagement::modifyaccount()
{
    cout << "\n Account No: " << accountnub;

    cout << "\n Modify Account holder name: ";
    cin >> name;

    cout << "\n modify your address: ";
    cin >> address;

    cout << "\n Modify type of account: savings or checking: ";
    cin >> accountT;

    cout << "\n Account is modified.";
}

// Function to delete an account
void bankmanagement::deleteaccount()
{
    accountnub = 0;
    name = "";
    address = "";
    accountT = '\0';
    amount = 0.0;
    cout << "\n sucessfully deleted.";
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

