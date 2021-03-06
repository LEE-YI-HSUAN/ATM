#include "pch.h"
#include "account.h"
#include "now_user.h"
#include "oper.h"
#include "setATM.h"
#include <iostream>
using namespace std;

void creatAccount(account user[]);
void menu(now_user nowUser, setATM &ATM,account (&user) [2]);
int main();
now_user setNowUser(account user[]);

void creatAccount(account user []) {

	int account[2] = { 12345,98765 };
	int PIN[2] = { 54321,56789 };
	double availableBalance[2] = { 1000.0,200.0 };
	double totalBalance[2] = { 1200.0,200.0 };
	
	for (int i = 0; i < 2; i++) {
		user[i].setAccount(account[i]);
		user[i].setPIN(PIN[i]);
		user[i].set_availableBalance(availableBalance[i]);
		user[i].set_totalBalance(totalBalance[i]);
	}
}

now_user setNowUser(account user[]) {
	cout << "Welcome!" << endl << endl;;
	cout << "Please enter your account number:";

	int userAccount;
	int userPIN;

	now_user nowUser;
	cin >> userAccount;
	while (!nowUser.checkAccount(userAccount, user)) {
		cout << "No such account, please re-enter. ";
		cin >> userAccount;
		//cout << endl;
	}
	cout << endl;

	cout << "Enter your PIN:";
	cin >> userPIN;
	while (!nowUser.checkPIN(userAccount, userPIN, user)) {
		cout << "Wrong password, please re-enter. ";
		cin >> userPIN;
		//cout << endl;
	}
	//cout << endl;
	nowUser.setValue(userAccount, userPIN ,user);

	return nowUser;
}

void menu(now_user nowUser,setATM &ATM,account (&user) [2]) {
	int choice;
	
	cout << endl << "Main menu" << endl;
	cout << "1 - View my balance" << endl;
	cout << "2 - Withdraw cash" << endl;
	cout << "3 - Deposit funds" << endl;
	cout << "4 - Exit" << endl;
	cout << "Enter a choice(1 - 4) : ";
	cin >> choice;
	cout << endl;
	
	oper op;
	op = nowUser;
	if (choice == 1) {
		op.printBanalance(nowUser);
		menu(nowUser, ATM, user);
	}
	else if (choice == 2) {
		op.withdrawCash(nowUser, ATM);
		menu(nowUser, ATM, user);
	}
	else if (choice == 3) {
		op.depositFunds(nowUser);
		menu(nowUser, ATM, user);
	}
	else if (choice == 4)
		op.exit(user,nowUser);
	else {
		cout << "Input errors, please re - enter " << endl;
		menu(nowUser, ATM, user);
	}	
}

int main()
{
	setATM ATM;
	ATM.set_ATMmoney(500.0 * 20);

	account user[2];
	creatAccount(user);

	/*cout << "user1" << endl;
	cout << user[0].getAccount() << endl;
	cout << user[0].getPIN() << endl;
	cout << user[0].get_availableBalance() << endl;
	cout << user[0].get_totalBalance() << endl;
	cout << endl;

	cout << "user2" << endl;
	cout << user[1].getAccount() << endl;
	cout << user[1].getPIN() << endl;
	cout << user[1].get_availableBalance() << endl;
	cout << user[1].get_totalBalance() << endl;
	cout << endl;*/

	bool run = true;
	now_user nowUser;
	//int choice;

	while (run == true) {
		nowUser = setNowUser(user);
		/*cout << "nowUser" << endl;
		cout << nowUser.getAccount() << endl;
		cout << nowUser.getPIN() << endl;
		cout << nowUser.get_availableBalance() << endl;
		cout << nowUser.get_totalBalance() << endl;
		cout << endl;*/
		menu(nowUser, ATM, user);
		
	}

	return 0;
}

