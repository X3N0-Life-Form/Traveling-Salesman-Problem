/* 
 * File:   Hookable.h
 * Author: etudiant
 *
 * Created on 10 juin 2014, 13:03
 */

#ifndef HOOKABLE_H
#define	HOOKABLE_H

#include <utility>

class Hookable {
public:
    Hookable();
    Hookable(const Hookable& orig);
    virtual ~Hookable();
    
    virtual void setHook(Hookable* hook) = 0;
    virtual bool processPair(std::pair<int, int>& pair) = 0;
    virtual void updateHook(bool accepted) = 0;
};

#endif	/* HOOKABLE_H */

