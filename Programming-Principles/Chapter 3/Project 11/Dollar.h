#ifndef DOLLAR_H_
#define DOLLAR_H_

#include "Coin.h"

class Dollar : public Coin {
    private:
        const int COINS_IN_DOLLAR { 100 };
    protected:
        int GetCentsPerCoin(void) const override;
    public:
        Dollar(int coins) 
            : Coin(coins) 
        {
        }
};

#endif /* DOLLAR_H_ */