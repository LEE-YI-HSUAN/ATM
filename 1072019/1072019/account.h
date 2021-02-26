//#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "pch.h"

class account{
public:
	account() {
		userAccount = 0;
		userPIN = 0;
		availableBalance = 0;
		totalBalance = 0;
	}

	account(int useraccount, int userpin, double availablebalance, double totalbalance) {
		userAccount = useraccount;
		userPIN = userpin;
		availableBalance = availablebalance;
		totalBalance = totalbalance;
	}

	void setAccount(int useraccount) {
		userAccount = useraccount;
	}

	int getAccount() const {
		return userAccount;
	}

	void setPIN(int userpin) {
		userPIN = userpin;
	}

	int getPIN() const {
		return userPIN;
	}

	void set_availableBalance(double availablebalance) {
		availableBalance = availablebalance;
	}

	double get_availableBalance() const {
		return availableBalance;
	}

	void set_totalBalance(double totalbalance) {
		totalBalance = totalbalance;
	}

	double get_totalBalance() const {
		return totalBalance;
	}

private:
	int userAccount;
	int userPIN;
	double availableBalance;
	double totalBalance;

};


#endif  //!ACCOUNT.H