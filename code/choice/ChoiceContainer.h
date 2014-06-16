/* 
 * File:   ChoiceContainer.h
 * Author: etudiant
 *
 * Created on 16 juin 2014, 09:52
 */

#ifndef CHOICECONTAINER_H
#define	CHOICECONTAINER_H

#include <vector>

#include "../run/interval/Interval.h"

class ChoiceContainer {
private:
    Interval* interval;
    std::vector<std::pair<int, int> > pairs;
    int index;
public:
    // Constructors / Destructor
    ChoiceContainer(Interval* interval);
    ChoiceContainer(const ChoiceContainer& orig);
    /**
     * Note: doesn't delete interval.
     */
    virtual ~ChoiceContainer();
    // Getters / Setters / Adders
    int getIndex();
    void addPair(std::pair<int, int>& pair);
    // Advanced Getters
    std::pair<int, int>& getNextPair();
};

#endif	/* CHOICECONTAINER_H */

