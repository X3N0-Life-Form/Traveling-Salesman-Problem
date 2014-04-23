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

const float City::getXF() {
    return x_f;
}

const float City::getYF() {
    return y_f;
}

const int City::getXI() {
    return x_i;
}

const int City::getYI() {
    return y_i;
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