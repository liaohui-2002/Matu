//
// Created by liaohui on 2021/11/21.
//

#include "Location.h"

Location &Location::operator+(Location &offset) {
    Location *l;
    l->x = this->x+offset.getX();
    l->y = this->y+offset.getY();
    return *l;
}

Location &Location::operator-(Location &offset) {
    Location *l;
    l->x = this->x-offset.getX();
    l->y = this->y-offset.getY();
    return *l;
}
