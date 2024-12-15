#ifndef NPC_H
#define NPC_H

#include <random>
#include <mutex>

class NPC {
public:
    NPC(int id, int x, int y);

    void move(int dx, int dy, int maxWidth, int maxHeight);
    bool isAlive() const;
    void kill();
    int rollDice() const;
    int getX() const;
    int getY() const;
    int getID() const;

private:
    int id;
    int x, y;
    bool alive;
    mutable std::mutex npcMutex;
};

#endif // NPC_H
