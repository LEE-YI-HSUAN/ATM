#ifndef SETATM_H
#define SETATM_H


class setATM {
public:
	void set_ATMmoney(double money) {
		ATMmonet = money;
	}

	double get_ATMmoney() const {
		return ATMmonet;
	}

private:
	double ATMmonet;
};

#endif