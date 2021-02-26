#ifndef NOW_USER_H
#define NOW_USER_H

#include "account.h"

class now_user : public account {
public:
	
	bool checkAccount(int useraccount, account user[]) {
		for (int i = 0; i < 2; i++)
			if (useraccount == user[i].getAccount())
				return true;

		return false;
	}

	bool checkPIN(int useraccount, int PIN, account user[]) {
		for (int i = 0; i < 2; i++) {
			if (useraccount == user[i].getAccount()) {
				if (PIN == user[i].getPIN())
					return true;
				else return false;
			}
		}
	}

	void setValue(int useraccount, int PIN, account user[]) {
		setAccount(useraccount);
		setPIN(PIN);

		int i = 0;
		for (; i < 2; i++)
			if (user[i].getAccount() == useraccount)
				break;

		set_availableBalance(user[i].get_availableBalance());
		set_totalBalance(user[i].get_totalBalance());
	}
};
#endif