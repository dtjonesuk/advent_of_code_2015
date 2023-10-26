//
// Created by David on 26/10/2023.
//

#ifndef INC_2015_PASSWORD_H
#define INC_2015_PASSWORD_H

#include <iostream>
#include <string>
#include <set>

/** Password
 *
 * Unfortunately for Santa, a new Security-Elf recently started, and he has imposed some additional password requirements:
 * - Passwords must include one increasing straight of at least three letters, like abc, bcd, cde, and so on, up to xyz. They cannot skip letters; abd doesn't count.
 * - Passwords may not contain the letters i, o, or l, as these letters can be mistaken for other characters and are therefore confusing.
 * - Passwords must contain at least two different, non-overlapping pairs of letters, like aa, bb, or zz.
 */

class Password {

protected:
    std::string password;
    std::set<char> forbiddenCharacters = {'i', 'o', 'l'};

    void incrementOnce() {
        // start at the end of the string
        // if z:
        //      set to a
        //      move back one character
        //      repeat
        // else:
        //      increment character, skipping forbidden

        auto it = password.rbegin();
        while (it != password.rend()) {
            if (*it == 'z') {
                // wrap around
                *it = 'a';
                it++;
            } else {
                *it = incrementChar(*it);
                break;  // end loop
            }
        }

    }

    char incrementChar(char c) const {
        do {
            c = c == 'z' ? 'a' : c + 1;
        } while (forbiddenCharacters.contains(c));
        return c;
    }

public:
    void increment() {
        do {
            incrementOnce();
        } while (!isValid());
    }

    /// checkStraight
    ///
    /// \return  true if the password contains an increasing straight of 3 or more letters
    ///             must skip forbidden characters when assessing straight
    bool checkStraight() const {
        int straight = 0;
        char next = 0;

        for (char c: password) {
            if (c == next)
                ++straight;
            else
                straight = 0;
            next = c + 1;
            //next = incrementChar(next);

            // bug out early if straight found
            if (straight >= 2)
                return true;
        }
        return false;
    }

    /// checkBadLetters
    ///
    /// \return true if password contains any of i, o or l
    bool checkBadLetters() const {
        for (char c: password) {
            if (forbiddenCharacters.contains(c))
                return false;
        }
        return true;
    }

    /// checkPairs
    ///
    /// \return true if password contains at least two non-overlapping pairs of letters
    bool checkPairs() const {
        std::set<char> pairs;
        char last = 0;
        for (auto it = password.begin() + 1; it != password.end(); ++it) {
            if (*it == *(it - 1)) {
                pairs.insert(*it);
                while (it != password.end() && (*it == *it - 1))
                    ++it;
            }
        }
        return (pairs.size() >= 2);
    }

    Password(const std::string &pwd) : password(pwd) {}

    bool isValid() const {
        return (checkStraight() &&
                checkBadLetters() &&
                checkPairs());
    }

    const std::string &getPassword() const {
        return password;
    }
};


#endif //INC_2015_PASSWORD_H
