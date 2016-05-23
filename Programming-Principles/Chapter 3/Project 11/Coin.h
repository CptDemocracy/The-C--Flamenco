#ifndef COIN_H_
#define COIN_H_

/* Abstract class. */
class Coin {
    private:
        int _coins;
    protected:
        Coin(void) = delete;
        Coin(int coins);
        virtual int GetCentsPerCoin(void) const = 0;
    public:
        int GetCoinCount(void) const;
        int GetCents(void) const;
        virtual ~Coin(void);
};

#endif /* COIN_H_ */