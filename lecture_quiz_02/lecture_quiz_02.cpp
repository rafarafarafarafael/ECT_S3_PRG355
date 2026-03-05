#include <cstdio>
#include "coinbank.h"
#include "gumballmachine.h"


int main(){
    // CoinBank cb1, cb2(8.35);
    // cb2.display();
    GumBallMachine myMachine = GumBallMachine(32);
    myMachine.sellGumBall(0);
    return 0;
}