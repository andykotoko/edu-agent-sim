#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Student {
    string name;   // Student name (kept in original language)
    int score;     // Random score between 1–100
};

struct Teacher {
    string name;           // Teacher name (three languages)
    string language;       // Label describing the name language
    char level;            // Teaching level A–E
    int studentCount;      // Number of assigned students
    Student stu[10];       // Up to 10 students
};

// Generate a random teaching level from A to E
char randomLevel() {
    int r = rand() % 5; 
    return 'A' + r;       // A B C D E
}

// Map rating level to number of students
int levelToStudentCount(char level) {
    switch (level) {
        case 'A': return 10;
        case 'B': return 8;
        case 'C': return 6;
        case 'D': return 3;
        case 'E': return 1;
        default:  return 1;
    }
}

// Assign teacher data + student generation
void assign(Teacher *tarr, int tlen) {

    // Teacher names (3 languages)
    string teacherNames[3] = { "张老师", "張老師", "Mr. Smith" };
    string teacherLangs[3] = { "Simplified Chinese", "Traditional Chinese", "English" };

    // Student name pools
    string stuNames_Simplified[10] = {
        "张三","李四","王五","赵六","孙七",
        "周八","吴九","郑十","钱一","孙二"
    };

    string stuNames_Traditional[10] = {
        "張三","李四","王五","趙六","孫七",
        "周八","吳九","鄭十","錢一","孫二"
    };

    string stuNames_English[10] = {
        "Alice","Bob","Charlie","David","Emma",
        "Frank","Grace","Helen","Jack","Lucy"
    };

    for (int i = 0; i < tlen; ++i) {

        // Assign teacher identity
        tarr[i].name = teacherNames[i];
        tarr[i].language = teacherLangs[i];

        // Randomly assign a level A–E
        tarr[i].level = randomLevel();

        // Determine number of students
        tarr[i].studentCount = levelToStudentCount(tarr[i].level);

        // Pick the correct student name list
        string *namesArray = nullptr;
        if (i == 0) namesArray = stuNames_Simplified;
        else if (i == 1) namesArray = stuNames_Traditional;
        else namesArray = stuNames_English;

        // Generate students
        for (int j = 0; j < tarr[i].studentCount; ++j) {
            tarr[i].stu[j].name = namesArray[j];
            tarr[i].stu[j].score = rand() % 100 + 1;
        }
    }
}

// Friendly output for teachers + students
void print(Teacher *tarr, int tlen) {

    for (int i = 0; i < tlen; ++i) {
        cout << "----------------------------------------" << endl;
        cout << "Teacher: " << tarr[i].name 
             << " (" << tarr[i].language << ") 🎓" << endl;

        cout << "Rating: " << tarr[i].level 
             << " ⭐  |  Students assigned: " 
             << tarr[i].studentCount << endl;

        cout << "Class List:" << endl;

        for (int j = 0; j < tarr[i].studentCount; ++j) {
            cout << "  • " << tarr[i].stu[j].name 
                 << " — Score: " << tarr[i].stu[j].score << endl;
        }

        cout << endl;
    }

    cout << "Teaching simulation complete! 🚀" << endl;
}

// Entry point of the simulation
int main() {

    srand((unsigned)time(NULL));

    cout << "Welcome to the classroom simulation system! 🎓" << endl;
    cout << "Please enter the base levels (1–10) for the three teachers, separated by spaces:" << endl;

    int levels[3];
    for (int i = 0; i < 3; ++i) {
        cin >> levels[i];
        if (levels[i] < 1) levels[i] = 1;
        if (levels[i] > 10) levels[i] = 10;
    }

    Teacher teachers[3];
    assign(teachers, 3);
    print(teachers, 3);

    return 0;
}
