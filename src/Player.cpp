#include "Player.h"

Player::Player() {
    hearts       = 3;
    sausageFound = 0;
    boneFound    = 0;
}

void Player::loseHeart()    { hearts--;       }
void Player::gainHeart()    { hearts++;       }
void Player::foundSausage() { sausageFound++; }
void Player::foundBone()    { boneFound++;    }

int  Player::getHearts()       const { return hearts;       }
int  Player::getSausageFound() const { return sausageFound; }
int  Player::getBoneFound()    const { return boneFound;    }
bool Player::isAlive()         const { return hearts > 0;   }
