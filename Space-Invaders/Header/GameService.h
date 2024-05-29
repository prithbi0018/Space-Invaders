#pragma once


class GameService {
private:
    void initialize();
    void destroy();

public:
    GameService(); // Constructor
    ~GameService(); // Destructor

    void Ignite();
    void update();
    void render();
    bool isRunning();
};



