#include "student.h"

namespace edu {

Student::Student(const std::string& n, Behaviour b, Score s)
    : name(n), behaviour(b), score(s) {}

const std::string& Student::getName() const {
    return name;
}

Behaviour Student::getBehaviour() const {
    return behaviour;
}

Score Student::getScore() const {
    return score;
}

} // namespace edu
