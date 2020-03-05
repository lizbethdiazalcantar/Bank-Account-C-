//this header file contains the class declaration of the checking account
//the checking account is derived from the bank account

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "BankAccount.h"

class CheckingAccount : public BankAccount
{
public:

	//constructor that calls second constructor of base class: 

	CheckingAccount(double b, double r) :BankAccount(b, r)
	{}


	//function prototypes:

	virtual void deposit(double);			//to deposit
	virtual void withdraw(double);			//to withdraw
	virtual void monthlyProc();				//for monthly proceedings


};

#endif