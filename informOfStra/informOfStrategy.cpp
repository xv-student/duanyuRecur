//
// Created by 25318 on 2021/3/25.
//

#include "informOfStrategy.h"

informOfStrategy::informOfStrategy() {}

informOfStrategy::informOfStrategy(double cooperationRate, double payoff) : cooperationRate(cooperationRate),
                                                                            payoff(payoff) {}

informOfStrategy::~informOfStrategy() {

}

double informOfStrategy::getCooperationRate() const {
    return cooperationRate;
}

void informOfStrategy::setCooperationRate(double cooperationRate) {
    informOfStrategy::cooperationRate = cooperationRate;
}

double informOfStrategy::getPayoff() const {
    return payoff;
}

void informOfStrategy::setPayoff(double payoff) {
    informOfStrategy::payoff = payoff;
}
