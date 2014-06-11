/* 
 * File:   city.h
 * Author: etudiant
 *
 * Created on 22 avril 2014, 13:59
 */

#ifndef CITY_H
#define	CITY_H

#include <ostream>

class City {
private:
    int id;
    int x_i;
    int y_i;
    float x_f;
    float y_f;
public:
    // Constructors / Destructor
    City(const City& orig);
    City(int id, int x, int y);
    City(int id, float x, float y);
    // Getters / Setters
    const int getId();
    const int getXI();
    const int getYI();
    const float getXF();
    const float getYF();
};

// Operators
bool operator<(City& left, City& right);
bool operator>(City& left, City& right);
bool operator==(City& left, City& right);
std::ostream& operator<<(std::ostream& out, City& right);
std::ostream& operator<<(std::ostream& out, City* right);

#endif	/* CITY_H */

