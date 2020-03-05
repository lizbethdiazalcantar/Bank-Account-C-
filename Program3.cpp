/******************************************************************
Kawthar Badran and Lizbeth Diaz									  *
Tues. 4/17/2018													  *
Program 3: Bank Accounts										  *
uses savings and checking accounts, both derived from bank account*
and calculates the monthly statistics of each.					  *
*******************************************************************/


#include<iostream>
#include<iomanip>				//for formatting deciaml output
#include"BankAccount.h"			//base, bank account
#include"SavingsAccount.h"		//derived, savings account 
#include"CheckingAccount.h"		//derived, checking account

using namespace std;

void statistics( SavingsAccount* sa );			//to display the statistics of the savings account
void statistics(CheckingAccount* ca);
void displayMenu();							//to display menu

double CHECKINGBALANCE = 0;					//start with $0 in each bank
double SAVINGSBALANCE = 0;

int main()
{
	//initialize doubles to hold the annual interest rates

	double savingintrate = 0.10, checkingintrate = 0.3;


	
	//create a savings account object that starts from a balance of 0

	SavingsAccount savings(	CHECKINGBALANCE, savingintrate);



	//create a checking account object that starts from a balance of 0

	CheckingAccount checking( SAVINGSBALANCE, checkingintrate);



	int choice;				//to hold the user's choice from menu

	do {
		

		displayMenu();		//display menu that asks for choice

		cin >> choice;		//get the choice and validate it


		while (choice < 0 || choice > 6)
		{
			cout << "Please enter a valid choice: ";
			cin >> choice;
		}

		
		switch (choice)
		{

		case 1:		//if the user wants to deposit in savings account, ask for the amount

			double depositamountSA;
			cout << "Please enter the amount you want to deposit in your savings account: ";
			cin >> depositamountSA;

			//use the class's function to deposit this amount

			savings.deposit(depositamountSA);		
			break;


		case 2:			//if the user wants to deposit in a checking account, ask for the amount

			double depositAmountCA;
			cout << "Please enter the amount you want to deposit in your checking account: ";
			cin >> depositAmountCA;

			// use the class's function to deposit this amount

			checking.deposit(depositAmountCA);
			break;


		case 3:			//if the user wants to withdraw from the savinggs acount, ask for the amount

			double withdrawalSA;
			cout << "Please enter the amount you want to withdraw from your savings account: ";
			cin >> withdrawalSA;

			//call the class's function to withdraw

			savings.withdraw(withdrawalSA);
			break;



		case 4:			//if the user wants to withdraw from the checking account, ask for the amount

			double withdrawalCA;
			cout << "Please enter the amount you want to withdraw from your checking account: ";
			cin >> withdrawalCA;

			//then call the base class's function to withdraw the amount

			checking.withdraw(withdrawalCA);

			break;



		case 5:			//if the user wants to see the monthly statistics, call the monthly proceedigs
			
			statistics(&savings);				
			statistics(&checking);
			break;


		case 6:			//if the user wants to exit, we end the program politely :)

			cout << "Thank you! Have a good day.\n";
			
		}

		//pause then clear the screen

		system("pause");
		system("read");
		system("cls");

	} while (choice != 6);		//keep displaying the menu as long as the user doesn't choose to exit


	return 0;

}


//this function displays the statistics of the saving account 

void statistics( SavingsAccount * sa)
{
	cout << endl;

	cout << " Monthly statistics for your savings account:\n";
	cout << "---------------------------------------------\n";
	cout << "Beginning balance $" << fixed << showpoint << setprecision(2) << SAVINGSBALANCE << endl;
	
	//total number of deposits and amount of deposited money:

	cout << "Total number of deposits: " << sa->getNumDeposits() << endl;

	cout << "Total amount that was deposited $" << fixed << showpoint << setprecision(2) 
		<< sa->getTotalDeposit() << endl;

	//total number of withdrawals and amount of withdrawn money

	cout << "Total number of withdrawals: " << sa->getNumWithdrawals() << endl;

	cout << "Total amount that was withdrawn $" << fixed << showpoint << setprecision(2) 
		<< sa->getTotalWithdraw() << endl;

	

	//now call the monthly proceedings function that will update the balance 
	//after adding interest and deducting service charges (also displays srvice charges

	sa->monthlyProc();

	//ending balance:

	cout << "Ending balance $" << fixed << showpoint << setprecision(2)
		<< sa->getBalance() << endl;

	cout << endl;
}


//this function displays the statistics of the checking account

void statistics(CheckingAccount * ca)
{
	cout << endl;
	cout << " Monthly statistics for your checking account:\n";
	cout << "---------------------------------------------\n";
	cout << "Beginning balance $" << fixed << showpoint << setprecision(2) << CHECKINGBALANCE << endl;

	//total number of deposits and amount of deposit money:
	cout << "Total number of deposits: " << ca->getNumDeposits() << endl;

	cout << "Total amount that was deposited $" << fixed << showpoint << setprecision(2)
		<< ca->getTotalDeposit() << endl;

	//total number of withdrawals and amount of withdrawn money:

	cout << "Total number of withdrawals: " << ca->getNumWithdrawals() << endl;

	cout << "Total amount that was withdrawn $" << fixed << showpoint << setprecision(2) 
		<< ca->getTotalWithdraw() << endl;

	
	//call the monthly proceedings to update balance that has interest and deducted service charges
	//and will display service charges

	ca->monthlyProc();

	//ending balance: 

	cout << "Ending balance $" << fixed << showpoint << setprecision(2) 
		<<ca->getBalance() << endl;

	cout << endl;
}


//this function displays the menu for the user to choose what to do
//it asks the user for his\her choice

void displayMenu()
{
	cout << "******************** BANK ACCOUNT MENU ********************\n\n";
	cout << "1. Savings Account Deposit\n";
	cout << "2. Checking Account Deposit\n";
	cout << "3. Savings Account Withdrawal\n";
	cout << "4. Checking Account Withdrawal\n";
	cout << "5. Update and Display Account Statistics\n";
	cout << "6.Exit\n";
	cout << "***********************************************************\n\n";
	cout<<"Please enter your choice: <1-6> ";
}