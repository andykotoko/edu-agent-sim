#include "simulation.h"
#include <iostream>

namespace edu {

Simulation::Simulation() {}

void Simulation::run() {
    std::cout << "===== Edu-Agent-Sim Simulation Start =====\n";

    initTeachers();
    printAll();

    std::cout << "===== Simulation End =====\n";
}

void Simulation::initTeachers() {
    std::cout << "Initializing teachers...\n";

    teachers.clear();

    // 三位老师：简体、繁体、英文
    teachers.emplace_back(Language::SimplifiedChinese, 0, nameGen);
    teachers.emplace_back(Language::TraditionalChinese, 1, nameGen);
    teachers.emplace_back(Language::English, 2, nameGen);

    // 为每个老师创建学生
    for (auto &t : teachers) {
        t.generateStudents(nameGen);
    }
}

void Simulation::printAll() const {
    std::cout << "\n--- Teacher List ---\n";
    for (const auto &t : teachers) {
        t.print();
        std::cout << "\n";
    }
}

} // namespace edu
