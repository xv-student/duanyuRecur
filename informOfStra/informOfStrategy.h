//
// Created by 25318 on 2021/3/25.
//

#ifndef DUANYURECUR_INFORMOFSTRATEGY_H
#define DUANYURECUR_INFORMOFSTRATEGY_H


class informOfStrategy {
private:
    double cooperationRate=-1;
    double payoff=0;
public:
    informOfStrategy();

    informOfStrategy(double cooperationRate, double payoff);

    virtual ~informOfStrategy();

    double getCooperationRate() const;

    void setCooperationRate(double cooperationRate);

    double getPayoff() const;

    void setPayoff(double payoff);
};



#endif //DUANYURECUR_INFORMOFSTRATEGY_H
