/* 
 * File:   ChoiceStatic.h
 * Author: etudiant
 *
 * Created on 18 juin 2014, 09:04
 */

#ifndef CHOICESTATIC_H
#define	CHOICESTATIC_H

#include <utility>

class ChoiceStatic {
public:
    static std::pair<int, int> NEUTRAL_PAIR;
private:
public:
    ChoiceStatic();
    ChoiceStatic(const ChoiceStatic& orig);
    virtual ~ChoiceStatic();
};

#endif	/* CHOICESTATIC_H */

