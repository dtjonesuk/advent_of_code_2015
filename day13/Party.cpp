//
// Created by David on 01/11/2023.
//

#include "Party.h"
#include <regex>
#include <algorithm>

void Party::addAttendee(const std::string& attendee) {
    std::map<std::string, int> sentiments;
    for (auto& [name, person] : attendees) {
        sentiments[name] = 0;
        person.sentiments[attendee] = 0;
    }
    Person &self = attendees[attendee];
    self.name = attendee;
    self.sentiments = sentiments;

    attendees[attendee] = self;
}

const static std::string sentimentExpression = "([A-Z]\\w+) would (gain|lose) (\\d+) happiness units by sitting next to ([A-Z]\\w+)";

void Party::parseAttendee(const std::string &attendee) {
    std::regex re(sentimentExpression);
    std::smatch match;
    if (std::regex_search(attendee, match, re)) {
        auto name = match.str(1);
        bool gain = match.str(2) == "gain";
        int amount = stoi(match.str(3));
        auto seated = match.str(4);

        Person &person = attendees[name];
        person.name = name;

        person.sentiments[seated] = gain ? amount : -amount;
    }
}

const std::map<std::string, Person>& Party::getAttendees() const {
    return attendees;
}

int Permutation::happiness() const {
    if (_cached)
        return _happiness;

    int total = 0;
    for (auto it = people.begin(); it != people.end(); ++it) {
        auto& current = *it;
        auto& next = (it+1) == people.end() ? people.front() : *(it+1);

        // current persons cw sentiment
        total += current.sentiments.at(next.name);

        // next persons ccw sentiment
        total += next.sentiments.at(current.name);
    }

    _happiness = total;
    _cached = true;

    return total;
}

Permutation &Permutation::operator=(const Permutation &p) {
    people.clear();
    std::copy(p.people.cbegin(), p.people.cend(), std::back_inserter(people));
    _happiness = happiness();
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Permutation &permutation) {
    for (auto& p : permutation.people) {
        os << p.name << ", ";
    }
    return os;
}
