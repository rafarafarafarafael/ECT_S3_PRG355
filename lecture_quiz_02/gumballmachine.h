#include "coinbank.h"

#ifndef _GUMBALLMACHINE
#define _GUMBALLMACHINE

class GumBallMachine{
    private:
        int quantity[5] = {0, 0, 0, 0, 0};
        char *colors[5] = {"Red", "Blue", "Green", "Yellow", "Orange"};
        float prices[5] = {0.10, 0.35, 0.5, 0.65, 0.7};
        CoinBank cb = CoinBank(0.0);

    public:
        GumBallMachine(void);
        GumBallMachine(int n);
        void sellGumBall(int n);
};

#endif