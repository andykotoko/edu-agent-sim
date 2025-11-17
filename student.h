#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "types.h"

namespace edu {

class Student {
private:
    std::string name;
    Behaviour behaviour;
    Score score;  

public:
    Student(const std::string& n, Behaviour b, Score s);

    const std::string& getName() const;
    Behaviour getBehaviour() const;
    Score getScore() const;
};

} // namespace edu

#endif
