#include <cstdio>

#ifndef _COINBANK
#define _COINBANK
class CoinBank{
	private:
		int coins[5] = {0, 0, 0, 0, 0};
		double values[5] = {0.05, 0.10, 0.25 ,1.00 , 2.00};

	public:
		CoinBank(void);
		CoinBank(float amount);
		double sum(void);
		void display(void);
		void operator++(int);
		void operator--(int);
};

#endif