#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int hearts;
    int sausageFound;
    int boneFound;

public:
    Player();

    // Actions
    void loseHeart();
    void gainHeart();
    void foundSausage();
    void foundBone();

    // Getters
    int getHearts() const;
    int getSausageFound() const;
    int getBoneFound() const;
    bool isAlive() const;
};

#endif
