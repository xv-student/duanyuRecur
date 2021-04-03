//
// Created by 25318 on 2021/3/25.
//

#include "player.h"

player::player() {}

player::player(int strategy, double payoff, int neighbourUp, int neighbourDown, int neighbourRight, int neighbourLeft,
               int neighbourUpRight, int neighbourUpLeft, int neighbourDownRight, int neighbourDownLeft) : strategy(
        strategy), payoff(payoff), neighbour_up(neighbourUp), neighbour_down(neighbourDown), neighbour_right(
        neighbourRight), neighbour_left(neighbourLeft), neighbour_up_right(neighbourUpRight), neighbour_up_left(
        neighbourUpLeft), neighbour_down_right(neighbourDownRight), neighbour_down_left(neighbourDownLeft) {}

player::~player() {

}

int player::getStrategy() const {
    return strategy;
}

void player::setStrategy(int strategy) {
    player::strategy = strategy;
}

double player::getPayoff() const {
    return payoff;
}

void player::setPayoff(double payoff) {
    player::payoff = payoff;
}

int player::getNeighbourUp() const {
    return neighbour_up;
}

void player::setNeighbourUp(int neighbourUp) {
    neighbour_up = neighbourUp;
}

int player::getNeighbourDown() const {
    return neighbour_down;
}

void player::setNeighbourDown(int neighbourDown) {
    neighbour_down = neighbourDown;
}

int player::getNeighbourRight() const {
    return neighbour_right;
}

void player::setNeighbourRight(int neighbourRight) {
    neighbour_right = neighbourRight;
}

int player::getNeighbourLeft() const {
    return neighbour_left;
}

void player::setNeighbourLeft(int neighbourLeft) {
    neighbour_left = neighbourLeft;
}

int player::getNeighbourUpRight() const {
    return neighbour_up_right;
}

void player::setNeighbourUpRight(int neighbourUpRight) {
    neighbour_up_right = neighbourUpRight;
}

int player::getNeighbourUpLeft() const {
    return neighbour_up_left;
}

void player::setNeighbourUpLeft(int neighbourUpLeft) {
    neighbour_up_left = neighbourUpLeft;
}

int player::getNeighbourDownRight() const {
    return neighbour_down_right;
}

void player::setNeighbourDownRight(int neighbourDownRight) {
    neighbour_down_right = neighbourDownRight;
}

int player::getNeighbourDownLeft() const {
    return neighbour_down_left;
}

void player::setNeighbourDownLeft(int neighbourDownLeft) {
    neighbour_down_left = neighbourDownLeft;
}
