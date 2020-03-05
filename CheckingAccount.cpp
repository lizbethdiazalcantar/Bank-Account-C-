//this is the file that contains the function definitions of the checking account 
//the checking account is derived from the bank account

#include "CheckingAccount.h"
#include "BankAccount.h"
#include<iostream>
using namespace std;


//this function withdraws money after checking if the balance is more than the withdrawal amount

void CheckingAccount::withdraw(double W)
{
	if (Balance < W)				//if balance is less than the amount,
	{

		serviceCharge += 15;		//add $15 to service charges to subtract them from the balance


		//display message to the user that withdrawal will not be made

		cout << "You cannot withdraw more money than the amount in your balance.\n";
		cout << "You have a service charge of $15 taken from your account.\n";


		//if the balance will be negative after subtracting the service charges
		//the user owes this amount to the bank.

		if (Balance - serviceCharge < 0)

			cout << "You now owe $" << serviceCharge - Balance << "to the bank\n";
	}

	else	
									//if there is enough money for withdrawal,
		BankAccount::withdraw(W);	//withdraw normally with base class function


}


//this function deposits money, and if the Balance was negative,
//the negative amount will be taken from the deposit

void CheckingAccount::deposit(double D)
{
	if (Balance < 0)
	{
		cout << "\n$" << -Balance << " will be deducted from your deposit.\n";
		D += Balance;
	}

	BankAccount::deposit(D);
	
}


//this function determines monthly proceedings of the checking account

void CheckingAccount::monthlyProc()
{
	serviceCharge += 5;							//first adds monthly $5 fee

	serviceCharge += (0.10 * withdrawCount);	//then add $0.01 for every withdrawal

	BankAccount::monthlyProc();					//call base class's function to update statistics
}