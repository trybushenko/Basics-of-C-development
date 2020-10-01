#include <iostream>
#include <string>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   Дана структура LectureTitle:

        Допишите конструктор и структуры Specialization, Course, Week так, 
        чтобы объект LectureTitle можно было создать с помощью кода.
        LectureTitle title(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
        );

        но нельзя было с помощью следующих фрагментов кода:
        LectureTitle title("C++", "White belt", "4th");

        LectureTitle title(string("C++"), string("White belt"), string("4th"));

        LectureTitle title = {"C++", "White belt", "4th"};

        LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};

        LectureTitle title(
            Course("White belt"),
            Specialization("C++"),
            Week("4th")
        );

        LectureTitle title(
            Specialization("C++"),
            Week("4th"),
            Course("White belt")
        );
*/
struct Specialization {
    string specialization;
    explicit Specialization(string _specialization) {
        specialization = _specialization;
    }
};

struct Course {
    string course;
    explicit Course (string _course) {
        course = _course;
    }
};

struct Week {
    string week;
    explicit Week(string _week) {
        week = _week;
    }
};

struct LectureTitle {
  string specialization;
  string course;
  string week;

  LectureTitle(Specialization _specialization, Course _course, Week _week) {
      specialization = _specialization.specialization;
      course = _course.course;
      week = _week.week;
  }
};

int main() {
    LectureTitle title(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
        );
    //cout << title.specialization << " - specialization" << "\n" << title.course << " - course" << "\n" << title.week << " - week";   
    return 0;
}