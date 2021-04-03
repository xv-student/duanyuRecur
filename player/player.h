//
// Created by 25318 on 2021/3/25.
//

#ifndef DUANYURECUR_PLAYER_H
#define DUANYURECUR_PLAYER_H


class player {
private:
    int strategy=-1;
    double payoff=0;

    int neighbour_up=-1;
    int neighbour_down=-1;
    int neighbour_right=-1;
    int neighbour_left=-1;

    int neighbour_up_right=-1;
    int neighbour_up_left=-1;
    int neighbour_down_right=-1;
    int neighbour_down_left=-1;
public:
    player();

    player(int strategy, double payoff, int neighbourUp, int neighbourDown, int neighbourRight, int neighbourLeft,
           int neighbourUpRight, int neighbourUpLeft, int neighbourDownRight, int neighbourDownLeft);

    virtual ~player();

    int getStrategy() const;

    void setStrategy(int strategy);

    double getPayoff() const;

    void setPayoff(double payoff);

    int getNeighbourUp() const;

    void setNeighbourUp(int neighbourUp);

    int getNeighbourDown() const;

    void setNeighbourDown(int neighbourDown);

    int getNeighbourRight() const;

    void setNeighbourRight(int neighbourRight);

    int getNeighbourLeft() const;

    void setNeighbourLeft(int neighbourLeft);

    int getNeighbourUpRight() const;

    void setNeighbourUpRight(int neighbourUpRight);

    int getNeighbourUpLeft() const;

    void setNeighbourUpLeft(int neighbourUpLeft);

    int getNeighbourDownRight() const;

    void setNeighbourDownRight(int neighbourDownRight);

    int getNeighbourDownLeft() const;

    void setNeighbourDownLeft(int neighbourDownLeft);

};


#endif //DUANYURECUR_PLAYER_H
