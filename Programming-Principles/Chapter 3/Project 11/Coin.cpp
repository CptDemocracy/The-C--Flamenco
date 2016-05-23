#include <stdexcept>

#include "Coin.h"

Coin::Coin(int coins) {
    if (coins < 0) {
        throw std::invalid_argument { "The amount of coins cannot be negative." };
    }
    _coins = coins;
}

Coin::~Coin(void) {
}

int Coin::GetCents(void) const {
    return _coins * GetCentsPerCoin();
}

int Coin::GetCoinCount(void) const {
    return _coins;
}