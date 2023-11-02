//
// Created by David on 01/11/2023.
//

#ifndef INC_2015_PARTY_H
#define INC_2015_PARTY_H

#include "Person.h"

#include <string>
#include <vector>
#include <map>
#include <ostream>

struct Permutation {
    std::vector<Person> people;

    Permutation() = default;
    Permutation(const Permutation& p) = default;
    Permutation(std::vector<Person> p) : people(p) {};

    Permutation& operator= (const Permutation& p);

    friend std::ostream &operator<<(std::ostream &os, const Permutation &permutation);

    int happiness() const;

private:
    mutable int _happiness = 0;
    mutable int _cached = false;
};

class Party {
public:
    void addAttendee(const std::string &attendee);
    void parseAttendee(const std::string &attendee);

    const std::map<std::string, Person> &getAttendees() const;

private:
    std::map<std::string, Person> attendees;

};


#endif //INC_2015_PARTY_H
