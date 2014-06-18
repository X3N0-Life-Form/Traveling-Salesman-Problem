/* 
 * File:   Picker.h
 * Author: etudiant
 *
 * Created on 16 juin 2014, 14:29
 */

#ifndef PICKER_H
#define	PICKER_H

#include <vector>

#include "Hookable.h"

class Picker : public Hookable {
public:
    // Constructors / Destructors
    Picker();
    Picker(const Picker& orig);
    virtual ~Picker();
    // Abstract Methods
    virtual std::pair<int, int>& getPair() = 0;
    virtual void prepareContainers(std::vector<std::pair<int, int> >* pairs) = 0;
    virtual bool maybeMoveOn() = 0;
};

#endif	/* PICKER_H */

