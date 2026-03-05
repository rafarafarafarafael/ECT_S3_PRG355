#include "coinbank.h"

typedef unsigned int ui;

CoinBank::CoinBank(void) {
	ui i;
	for (i = 0; i < 5; i++) {
		coins[i] = 1;
	}
}

CoinBank::CoinBank(float amount) {
	ui i = 4;
	while (amount >= values[0]) {
		if (amount >= values[i]) {
			amount -= values[i];
			coins[i]++;
		}
		else {
			if (i > 0) i--;
		}
	}
	puts("created specific CoinBank...");
}

double CoinBank::sum(void) {
	double sum = 0;
	ui i;
	for (i = 0; i < 5; i++) {
		sum += coins[i] * values[i];
	}
	return sum;
}

void CoinBank::display(void){
	ui i;
	float amount = 0;
	printf("coins: {");
	for(i = 0; i <5 ; i++){
		printf("%d x %.2f, ", coins[i], values[i]);
	}
	printf("}\n");
	amount = sum();
	printf("total amount in this coin bank: %.2f\n", amount);
}

void CoinBank::operator++(int) {
	ui i;
	for (i = 0; i < 5; i++) {
		coins[i]++;
	}
}

void CoinBank::operator--(int) {
	ui i;
	for (i = 0; i < 5; i++) {
		if (coins[i] > 0) coins[i]--;
	}
}