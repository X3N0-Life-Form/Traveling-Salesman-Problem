/* 
 * File:   ChoicePicker.h
 * Author: etudiant
 *
 * Created on 16 juin 2014, 09:49
 */

#ifndef CHOICEPICKER_H
#define	CHOICEPICKER_H

#include <vector>

#include "../run/interval/IntervalManager.h"
#include "ChoiceContainer.h"

class ChoicePicker {
private:
    IntervalManager* manager;
    std::vector<ChoiceContainer*> containers;
public:
    // Constructors / Destructor
    ChoicePicker(IntervalManager* manager);
    ChoicePicker(const ChoicePicker& orig);
    /**
     * Note: doesn't delete manager.
     */
    virtual ~ChoicePicker();
    // Getters / Setters
    std::vector<ChoiceContainer*>& getContainers();
    // Advanced Getters
    std::pair<int, int>& getPair();
    // Other Methods
    ChoiceContainer* selectContainer(std::pair<int, int>& pair);
    void prepareContainers(std::vector<std::pair<int, int> >& pairs);
};

#endif	/* CHOICEPICKER_H */

