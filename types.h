#ifndef TYPES_H
#define TYPES_H

#include <cstdint>
#include <string>

namespace edu { // 避免全局名字冲突

// 基础 ID & 别名
using StudentId  = std::uint32_t;
using TeacherId  = std::uint32_t;
using StepIndex  = std::uint32_t;
using Score      = double;

// 语言类型
enum class Language : std::uint8_t {
    SimplifiedChinese,
    TraditionalChinese,
    English,
    Japanese,
    Korean,
    Spanish,
    French
};

// 学生行为
enum class Behaviour : std::uint8_t {
    Diligent,
    Lazy,
    Disruptive,
    Sleepy,
    Inquisitive
};

// 科目类型
enum class Subject : std::uint8_t {
    Mathematics,
    EnglishSubject, // 避免和 Language::English 冲突
    Science,
    History,
    Art
};

// 课堂事件
enum class EventType : std::uint8_t {
    PopQuiz,
    GroupProject,
    FieldTrip,
    IllnessOutbreak,
    ParentVisit,
    None
};

// 老师等级（A~E）
enum class TeacherLevel : char {
    A = 'A',
    B = 'B',
    C = 'C',
    D = 'D',
    E = 'E'
};

// 一些小的值对象
struct SubjectScore {
    Subject subject;
    Score  value;
};

struct EventImpact {
    EventType type;
    double    scoreDelta;
    int       satisfactionDelta;
    int       performanceDelta;
};

// toString 声明（实现放 .cpp）
std::string toString(Language);
std::string toString(Behaviour);
std::string toString(Subject);
std::string toString(EventType);
std::string toString(TeacherLevel);

} // namespace edu

#endif
