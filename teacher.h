#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <vector>
#include <random>
#include "types.h"
#include "student.h"
#include "NameGenerator.h"

namespace edu {

class Teacher {
private:
    std::string name;
    Language lang;
    TeacherLevel level;

    std::vector<Student> students;

    std::mt19937 mt;
    std::normal_distribution<double> scoreDist;
    std::uniform_int_distribution<int> behaviourDist;

public:
    Teacher(Language l, int index, const NameGenerator& ng);

    void generateStudents(const NameGenerator& ng);

    const std::string& getName() const;
    Language getLanguage() const;
    TeacherLevel getLevel() const;
    const std::vector<Student>& getStudents() const;

    void print() const;
};

} // namespace edu

#endif

