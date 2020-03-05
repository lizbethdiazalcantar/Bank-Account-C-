//this file contains the function definitions of the savings account 
//savings account is derived from bank account

#include "SavingsAccount.h"
#include "BankAccount.h"
#include<iostream>
using namespace std;


// this function withdraws money from savings account after checking if status is active:

void SavingsAccount::withdraw(double W)
{

	while (W < 0)				//ask again for valid amount if the amount was negative
	{
		cout << "Please enter a valid amount:  ";
		cin >> W;
	}

	if (status)					//if the account was active, withdraw the amount normally
	{
		BankAccount::withdraw(W);

		setStatus();			//update status after the withdrawal

		if (!status)			//if the account turned inactive, warn the user
			cout << "You now have less than $25 in your balance. Your account is now inactive.\n";
	}

	else						//if the account was inactive, withdrawal can't be made
								
		cout << "Sorry, your account is inactive.\n"
			<<"You cannot make withdrawals until you have at least $25 in your balance.\n";
}



//this function deposits money from savings account after checking if the status is active

void SavingsAccount::deposit(double D)
{
	while (D < 0)				//ask again for valid amount if the amount was negative
	{
		cout << "Please enter a valid amount:  ";
		cin >> D;
	}

	//deposit normally if the account is active

	if (status)						
		BankAccount::deposit(D);


	//if the account is inactive but the deposit makes the balance >= 25, add the deposit 

	else if (!status && (Balance + D) >= 25)						
	{

		BankAccount::deposit(D);

		//and update the account status to active

		cout << "Your account will now be activated.\n";			

	}

	else		//otherwise display message that withdrawal can't be made.

		cout << "Sorry, your account is inactive, and the deposit amount is not enough"
		<<" to activate it.\n You currently cannot make deposits.\n";

	setStatus();		//update status as active or inactive
}


//this function determines the service charges amount 

void SavingsAccount:: monthlyProc()
{
	if (withdrawCount > 4)					//if the number of withdrawals is > 4,
		serviceCharge = withdrawCount - 4;  //service charge is $1 per every withdrawal more than 4

	BankAccount::monthlyProc();				//now call base class fucntion for monthly proceedings

	setStatus();							//reset status after subtractions from balance
}
