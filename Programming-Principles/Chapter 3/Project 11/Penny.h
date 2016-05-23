#ifndef PENNY_H_
#define PENNY_H_

#include "Coin.h"

class Penny : public Coin {
    private:
        const int COINS_IN_PENNY { 1 };
    protected:
        int GetCentsPerCoin(void) const override;
    public:
        Penny(int coins) 
            : Coin(coins) 
        { 
        }
};

#endif /* PENNY_H_ */