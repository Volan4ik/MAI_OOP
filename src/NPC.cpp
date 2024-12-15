#include "NPC.h"

NPC::NPC(int id, int x, int y) : id(id), x(x), y(y), alive(true) {}

void NPC::move(int dx, int dy, int maxWidth, int maxHeight) {
    std::lock_guard<std::mutex> lock(npcMutex);
    if (!alive) return;

    x = std::max(0, std::min(maxWidth - 1, x + dx));
    y = std::max(0, std::min(maxHeight - 1, y + dy));
}

bool NPC::isAlive() const {
    std::lock_guard<std::mutex> lock(npcMutex);
    return alive;
}

void NPC::kill() {
    std::lock_guard<std::mutex> lock(npcMutex);
    alive = false;
}

int NPC::rollDice() const {
    std::lock_guard<std::mutex> lock(npcMutex);
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 6);
    return dist(gen);
}

int NPC::getX() const {
    std::lock_guard<std::mutex> lock(npcMutex);
    return x;
}

int NPC::getY() const {
    std::lock_guard<std::mutex> lock(npcMutex);
    return y;
}

int NPC::getID() const {
    return id;
}
