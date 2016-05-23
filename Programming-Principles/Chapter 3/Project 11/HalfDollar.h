#ifndef HALFDOLLAR_H_
#define HALFDOLLAR_H_

#include "Coin.h"

class HalfDollar : public Coin {
    private:
        const int COINS_IN_HALF_DOLLAR { 50 };
    protected:
        int GetCentsPerCoin(void) const override;
    public:
        HalfDollar(int coins) 
            : Coin(coins) 
        {
        }
};

#endif /* HALFDOLLAR_H_ */