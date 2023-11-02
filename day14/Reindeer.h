//
// Created by David on 02/11/2023.
//

#ifndef INC_2015_REINDEER_H
#define INC_2015_REINDEER_H

#include <string>

class Reindeer {
public:
    std::string name;
    int speed;
    int flyTime;
    int restTime;
    int points{0};

    Reindeer(const std::string& s);

    void Tick();

    int getDistance() const;

private:
    int distance{0};
    int t{0};  // current position in fly/rest cycle
};


#endif //INC_2015_REINDEER_H
