#ifndef NAME_GENERATOR_H
#define NAME_GENERATOR_H

#include <string>
#include <map>
#include <vector>
#include "types.h"

namespace edu {

class NameGenerator {
public:
    NameGenerator();  

    std::string getTeacherName(Language lang, int index) const;
    std::string getStudentName(Language lang, int index) const;

private:
    std::map<Language, std::vector<std::string>> teacherPools;
    std::map<Language, std::vector<std::string>> studentPools;
};

} // namespace edu

#endif
