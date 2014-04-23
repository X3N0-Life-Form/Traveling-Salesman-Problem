#include "city.h"

City::City(int id, int x, int y) :
    id(id), x_i(x), y_i(y) {

}

City::City(int id, float x, float y) :
    id(id), x_f(x), y_f(y)  {
    
}

const int City::getId() {
    return id;
}


bool operator <(City& left, City& right) {
    return left.getId() < right.getId();
}

bool operator >(City& left, City& right) {
    return left.getId() > right.getId();
}

bool operator ==(City& left, City& right) {
    return left.getId() == right.getId();
}

std::ostream& operator <<(std::ostream& out, City& right) {
    out << "City: id=" << right.getId();
    return out;
}

std::ostream& operator <<(std::ostream& out, City* right) {
    out << "City: id=" << right->getId();
    return out;
}