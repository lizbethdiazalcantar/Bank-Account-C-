//this is the header file for the base class: bank account
//it has the member and member function declarations


#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount
{
protected:
	double Balance;						// to hold the balance amount			
	double intRate;						// to hold annual interest rate
	double serviceCharge;				// to hold amount of service charges
	int depositCount, withdrawCount;	// to hold a counter for the number of withdrawals and deposits

	double totalDeposit, totalWithdraw;	  // to hold counter for amount of deposits and withdrawals

public:

	//default constructor: initializes all values to 0

	BankAccount()
	{
		Balance = 0;
		depositCount = 0;
		withdrawCount = 0;
		intRate = 0;
		serviceCharge = 0;
		totalDeposit = 0;
		totalWithdraw = 0;
	}


	//second constructor: takes and sets balance amount and annual interest rate
	//and initializes:  deposit and withdraw counters to 0
	//and initializes: total deposit and withdraw amount to 0
	BankAccount(double B, double R)
	{
		Balance = B;
		intRate = R;
		serviceCharge = 0;
		depositCount = 0;
		withdrawCount = 0;
		totalDeposit = 0;
		totalWithdraw = 0;
	}

	//prototypes for functions

	virtual void deposit(double D);		//to deposit
	virtual void withdraw(double w);	//to withdraw
	virtual void calcInt();				//to calculate monthly interest
	virtual void monthlyProc();			//to subtract service charges from balance


	//prototypes for mutators:

	void setBalance(double);
	void setintRate(double);
	void setServiceCharge(double);
	

	//Accessors:

	double getBalance() const		//to get balance amount
	{
		return Balance;
	}

	int getNumDeposits() const		//to get number of deposits
	{
		return depositCount;
	}

	int getNumWithdrawals() const	// to get number of withdrawls
	{
		return withdrawCount;
	}

	double getIntRate() const		//to get annual interest rate
	{
		return intRate;
	}

	double getServiceCharge() const		// to get amount of service charges
	{
		return serviceCharge;
	}

	
	double getTotalDeposit() const		//to get total amount of deposits
	{
		return totalDeposit;
	}

	double getTotalWithdraw() const		//to get total amount of withdrawals
	{
		return totalWithdraw;
	}


	

	~BankAccount()		
	{
		//Destructor (does nothing)
	}

};
#endif