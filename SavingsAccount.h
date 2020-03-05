//this header file contains the class declaration of the savings account
//the savings account is derived from the bank account

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "BankAccount.h"

class SavingsAccount: public BankAccount
{
protected:

	bool status;		//to represent status of account: active or inactive

public:

	//constructor that calls base class's second constructor:
	//keeps status active

	SavingsAccount(double b, double r) :BankAccount(b, r)
	{
		status = true;			//initialize flag as true
	}


	//this function sets status of account by itself depending on the Balance amount: 

	void setStatus()
	{
		if (Balance < 25)		//if there are less thn $25 in account, status turn inactive
			status = false;		//otherwise it remains active

		else if (Balance >= 25)
			status = true;		
		 
	}


	//Accessor: 

	bool getStatus() const		//to get status
	{
		return status;
	}


	//function prototypes:

	virtual void withdraw(double W);		//to withdraw money
	virtual void deposit(double D);			//to deposit money
	virtual void monthlyProc();				//for monthly proceedings

};
#endif