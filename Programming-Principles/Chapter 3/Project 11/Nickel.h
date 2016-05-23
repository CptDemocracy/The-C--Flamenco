#ifndef NICKEL_H_
#define NICKEL_H_

#include "Coin.h"

class Nickel : public Coin {
    private:
        const int COINS_IN_NICKEL { 5 };
    protected:
        int GetCentsPerCoin(void) const override;
    public:
        Nickel(int coins) 
            : Coin(coins) 
        {
        }
};

#endif /* NICKEL_H_ */