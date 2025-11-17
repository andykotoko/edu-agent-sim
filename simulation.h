#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include "teacher.h"
#include "NameGenerator.h"
#include "types.h"

namespace edu {

class Simulation {
public:
    Simulation();
    void run();

private:
    NameGenerator nameGen;
    std::vector<Teacher> teachers;

    void initTeachers();
    void printAll() const;
};

} // namespace edu

#endif
