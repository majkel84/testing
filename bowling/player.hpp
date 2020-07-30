#pragma once

class Player {
public:
    int getScore() const;
    void setScore(int score);

    int countScore();
private:
    int score_;
};
