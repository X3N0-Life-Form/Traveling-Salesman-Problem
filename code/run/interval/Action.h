/* 
 * File:   Action.h
 * Author: etudiant
 *
 * Created on 2 juin 2014, 09:06
 */

#ifndef ACTION_H
#define	ACTION_H

#include <vector>

class Action {
private:
    std::pair<int, int> pair;
    int costDiff;
public:
    Action(std::pair<int, int> pair, int costDiff);
    Action(const Action& orig);
    virtual ~Action();

};

#endif	/* ACTION_H */

