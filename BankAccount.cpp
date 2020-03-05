//this file contains the member function definitions for the bank account class

#include<iostream>			//required or cout and cin
#include "BankAccount.h"	
using namespace std;


//this function performs a deposit : 

void BankAccount::deposit(double D)		//it takes the amount to be deposited,
{
	while (D < 0)						//validates it,
	{
		cout << "Please enter a valid amount: ";
		cin >> D;
	}

	Balance += D;						//adds it to the balance,
	depositCount++;						//increments the counter of deposit number,
	totalDeposit += D;					//and adds the amount to the total deposit amount 

	//display message
	cout << "Thank you. Your deposit has been made.\n";
}


//this function performs a withdrawal: 

void BankAccount::withdraw(double W)		//it takes the amount to be withdrawn,
{
	while (W < 0)							//validates it,
	{
		cout << "Please enter a valid amount: ";
		cin >> W;
	}
	Balance -= W;							//subtracts it from the balance,
	withdrawCount++;						//increments the counter of withdrawal number
	totalWithdraw += W;						//and adds the amount to the total withdrawals amount

	//display message
	cout << "Thank you. Your withdrawal has been made.\n";
}


//this function calculates the monthly interest from the annual interest rate
//then adds the monthly interest to the balance

void BankAccount::calcInt()
{
	if (Balance > 0)		//add the interest only when the balance is positive
	{
		double monRate = (intRate / 12);
		double monInterest = Balance * monRate;
		Balance += monInterest;
	}
	
}


//this function subtracts the service charges from the balance
// then adds the monthly interest by calling calcInt function

void BankAccount::monthlyProc()
{
	Balance -= serviceCharge;
	calcInt();
	
	//display the service charge before it resets to 0
	cout << "Service Charges: $" << serviceCharge << endl;

	//then, it sets the service charges, number of withdrawals and deposits to 0

	withdrawCount = 0;				
	depositCount = 0;
	serviceCharge = 0;

}

//Mutator functions:

//this function takes a value and sets it to the balance amount
void BankAccount::setBalance(double d)
{
	Balance = d;
}

//this function takes a value and sets it to the annual interest rate
void BankAccount::setintRate(double r)
{
	intRate = r;
}

//this funciton takes a value and sets it to the service charge amount
void BankAccount::setServiceCharge(double s)
{
	serviceCharge = s;
}