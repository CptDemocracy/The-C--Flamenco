#ifndef QUARTER_H_
#define QUARTER_H_

#include "Coin.h"

class Quarter : public Coin {
    private:
        const int COINS_IN_QUARTER { 25 };
    protected:
        int GetCentsPerCoin(void) const override;
    public:
        Quarter(int coins) 
            : Coin(coins) 
        {
        }
};

#endif /* QUARTER_H_ */