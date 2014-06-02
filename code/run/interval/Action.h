/* 
 * File:   Action.h
 * Author: etudiant
 *
 * Created on 2 juin 2014, 09:06
 */

#ifndef ACTION_H
#define	ACTION_H

#include <vector>
#include <ostream>

class Action {
private:
    std::pair<int, int> pair;
    int costDiff;
public:
    Action(std::pair<int, int> pair, int costDiff);
    Action(const Action& orig);
    virtual ~Action();
    // Getters/Setters
    int getCostDiff() const;
    const std::pair<int, int>& getPair() const;
};

std::ostream& operator<<(std::ostream& out, const Action& action);
std::ostream& operator<<(std::ostream& out, const Action* action);

#endif	/* ACTION_H */

