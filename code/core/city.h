/* 
 * File:   city.h
 * Author: etudiant
 *
 * Created on 22 avril 2014, 13:59
 */

#ifndef CITY_H
#define	CITY_H

class City {
private:
    int id;
    int x_i;
    int y_i;
    float x_f;
    float y_f;
public:
    City(int id, int x, int y);
    City(int id, float x, float y);
};

#endif	/* CITY_H */

