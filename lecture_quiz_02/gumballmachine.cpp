#include "gumballmachine.h"

typedef unsigned int ui;

GumBallMachine::GumBallMachine(void){
    ui i;
    for(i = 0; i < 5; i++){
        quantity[i] = 2;
    }
}

GumBallMachine::GumBallMachine(int n){
    ui i;
    ui remainder = n%5;
    for(i = 0; i < 5; i++){
        quantity[i] = (n - remainder) / 5;
    }
    quantity[0] += remainder;
}

void  GumBallMachine::sellGumBall(int n){
    double amount = 0;
    if(n < 5){
        if(quantity[n] > 0){
            quantity[n]--;
            amount = prices[n];
            cb = CoinBank(cb.sum() + amount);
            printf("%s gum sold! The current amount of money is $%.2f and there are %d gums left\n", colors[n], cb.sum(), quantity[n]);
        } else {
            puts("Sorry, no more %s gums left...\n");
        }
    }
}