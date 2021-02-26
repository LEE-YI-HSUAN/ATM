#ifndef OPER_H
#define OPER_H

#include "pch.h"
#include "account.h"
#include "now_user.h"
#include "setATM.h"
#include "iostream"

using namespace std;
class oper : public account {
public:
	void printBanalance(const now_user user) {
		cout << endl << "Balance Information:" << endl;
		cout << "- Available balance: $" << user.get_availableBalance() << endl;
		cout << "- Total balance:     $" << user.get_totalBalance() << endl;
	}

	void withdrawCash(now_user &user, setATM &ATM) {
		int choice;
		int cash[5] = { 20,40,60,100,200 };
		cout << "Withdrawal options :" << endl;
		cout << "1 - $20" << endl;
		cout << "2 - $40" << endl;
		cout << "3 - $60" << endl;
		cout << "4 - $100" << endl;
		cout << "5 - $200" << endl;
		cout << "6 - Cancel transaction" << endl;
		cout << "Choose a withdrawal option(1 - 6) : ";
		cin >> choice;
		bool run = true;

		while (run == true && choice <= 5 && choice >= 1) {
			for (int i = 0; i < 6; i++) {
				if (i == choice - 1) {
					if (this->get_availableBalance() < cash[i] || ATM.get_ATMmoney() < cash[i]) {
						cout << "Please select a smaller amount ";
						cin >> choice;
						break;
					}
					else {
						cout << endl << "Please take your cash from the cash dispenser." << endl;
						this->set_availableBalance(this->get_availableBalance() - cash[i]);
						user.set_availableBalance(this->get_availableBalance());
						this->set_totalBalance(this->get_totalBalance() - cash[i]);
						user.set_totalBalance(this->get_totalBalance());
						ATM.set_ATMmoney(ATM.get_ATMmoney() - cash[i]);
						run = false;
						break;
					}
				}
			}
		}
	}

	void depositFunds(now_user &user) {
		double cash;
		cout << "Please enter a deposit amount in CENTS(or 0 to cancel) :";
		cin >> cash;
		cash /= 100;

		cout << "Please insert a deposit envelope containing $" << cash << " in the deposit slot." << endl;

		this->set_totalBalance(this->get_totalBalance() + cash);
		user.set_totalBalance(this->get_totalBalance());
	}

	void exit(account(&user)[2], now_user nowUser) {
		cout << "Exiting the system..." << endl << endl << "Thank you!Goodbye!" << endl << endl;

		for (int i = 0; i < 2; i++) {
			if (user[i].getAccount() == nowUser.getAccount()) {
				user[i].set_availableBalance(nowUser.get_availableBalance());
				user[i].set_totalBalance(nowUser.get_totalBalance());
			}
		}
	}

	const oper& operator=(const now_user &user) {
		this->setAccount(user.getAccount());
		this->setPIN(user.getPIN());
		this->set_availableBalance(user.get_availableBalance());
		this->set_totalBalance(user.get_totalBalance());

		return *this;
	}

};
#endif
