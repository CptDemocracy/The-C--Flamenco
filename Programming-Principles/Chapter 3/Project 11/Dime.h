#ifndef DIME_H_
#define DIME_H_

#include "Coin.h"

class Dime : public Coin {
    private:
        const int COINS_IN_DIME { 10 };
    protected:
        int GetCentsPerCoin(void) const override;
    public:
        Dime(int coins) 
            : Coin(coins) 
        {
        }
};

#endif /* DIME_H_ */