#include "teacher.h"
#include <iostream>
#include <cmath>
#include <algorithm>

namespace edu {

Teacher::Teacher(Language l, int index, const NameGenerator& ng)
    : lang(l),
      name(ng.getTeacherName(l, index)),
      mt(std::random_device{}()),
      scoreDist(75.0, 12.0),
      behaviourDist(0, static_cast<int>(Behaviour::Inquisitive))
{
    // 随机等级
    int lvl = std::uniform_int_distribution<int>(0,4)(mt);
    level = static_cast<TeacherLevel>('A' + lvl);
}

void Teacher::generateStudents(const NameGenerator& ng) {
    students.clear();

    int count;
    switch(level) {
        case TeacherLevel::A: count = 10; break;
        case TeacherLevel::B: count = 8; break;
        case TeacherLevel::C: count = 6; break;
        case TeacherLevel::D: count = 3; break;
        default:              count = 1; break;
    }

    for (int i = 0; i < count; ++i) {
        double raw = scoreDist(mt);
        raw = std::clamp(raw, 1.0, 100.0);

        Behaviour b = static_cast<Behaviour>(behaviourDist(mt));
        std::string stuName = ng.getStudentName(lang, i);

        students.emplace_back(stuName, b, std::round(raw));
    }
}

const std::string& Teacher::getName() const { return name; }
Language Teacher::getLanguage() const { return lang; }
TeacherLevel Teacher::getLevel() const { return level; }
const std::vector<Student>& Teacher::getStudents() const { return students; }

void Teacher::print() const {
    std::cout << "Teacher: " << name
              << " [" << toString(lang) << "]"
              << " Level: " << static_cast<char>(level)
              << "\n";

    for (const auto& s : students) {
        std::cout << "  - " << s.getName()
                  << " (" << toString(s.getBehaviour()) << ")"
                  << ": " << s.getScore() << "\n";
    }
}

} // namespace edu
