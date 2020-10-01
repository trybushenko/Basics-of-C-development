#include <iostream>
#include <string>
#include <map>
#include <vector>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   Дополните класс Person из задачи «Имена и фамилии — 2» конструктором, 
        позволяющим задать имя и фамилию человека при рождении, а также сам год рождения. 
        Класс не должен иметь конструктора по умолчанию.

        При получении на вход года, который меньше года рождения:

        методы GetFullName и GetFullNameWithHistory должны отдавать "No person";
        методы ChangeFirstName и ChangeLastName должны игнорировать запрос.
        Кроме того, необходимо объявить константными все методы, которые по сути ими являются.

        Пример:
            Код: 
                int main() {
                  Person person("Polina", "Sergeeva", 1960);
                  for (int year : {1959, 1960}) {
                    cout << person.GetFullNameWithHistory(year) << endl;
                  }
                
                  person.ChangeFirstName(1965, "Appolinaria");
                  person.ChangeLastName(1967, "Ivanova");
                  for (int year : {1965, 1967}) {
                    cout << person.GetFullNameWithHistory(year) << endl;
                  }
                
                  return 0;
                }

            Вывод:
                No person
                Polina Sergeeva
                Appolinaria (Polina) Sergeeva
                Appolinaria (Polina) Ivanova (Sergeeva)
*/

class Person {
    public:
        Person(const string& name, const string& surname, const int& year) {
            yearAndFirstName[year] = name;
            yearAndLastName[year] = surname;
            birthday = year;
        }

        void ChangeFirstName(int year, const string& first_name) {
            if (birthday > year) return;
            yearAndFirstName[year] = first_name;
        }
        void ChangeLastName(int year, const string& last_name) {
            if (birthday > year) return;
            yearAndLastName[year] = last_name;
        }
        string GetFullName(int year) const {
            if (birthday > year) return "No person";
            string name, surname, result;
            auto nameIterator = yearAndFirstName.lower_bound(year);
            auto surnameIterator = yearAndLastName.lower_bound(year);
            if (nameIterator == yearAndFirstName.end() && surnameIterator == yearAndLastName.end()) result = "Incognito";
            else if (nameIterator != yearAndFirstName.end() && surnameIterator == yearAndLastName.end()) {
                name = nameIterator -> second;
                result = name + " with unknown last name";
            } else if (nameIterator == yearAndFirstName.end() && surnameIterator != yearAndLastName.end()) {
                surname = surnameIterator -> second;
                result = surname + " with unknown first name";
            } else {
                surname = surnameIterator -> second;
                name = nameIterator -> second;
                result = name + ' ' + surname;
            }
            return result;
        }
        string GetFullNameWithHistory(int year) const{
          if (birthday > year) return "No person";
          string result, name, surname;
          bool flagToCheckIfSurname = false;
          bool flagName = false, flagSurname = false, flagNo = false;
          if (!yearAndFirstName.size() && !yearAndLastName.size()) result = "Incognito";
          else {  
            for (const auto& kv : yearAndFirstName) if (kv.first <= year) flagName = true;
            for (const auto& kv : yearAndLastName) if (kv.first <= year) flagSurname = true;
            if (flagName && flagSurname) {
              name = getAllSurNames(yearAndFirstName, year);
              surname = getAllSurNames(yearAndLastName, year);
            } else if (flagName && !flagSurname) {
              name = getAllSurNames(yearAndFirstName, year);
              surname = "with unknown last name";
            } else if (flagSurname && !flagName) {
              surname = getAllSurNames(yearAndLastName, year);
              name = "with unknown first name";
              flagToCheckIfSurname = true;
            } else if (!flagName && !flagSurname) {
              flagNo = true;
            }
            if (flagNo) result = "Incognito";
            else {
                if (flagToCheckIfSurname) result = surname + ' ' + name;
                else result = name + ' ' + surname;
            }
          }
          return result; 
        }
    private:
        map<int, string, greater<int>> yearAndFirstName;
        map<int, string, greater<int>> yearAndLastName;
        int birthday;

        string getAllSurNames(const map<int, string, greater<int>>& firstAndLastNames, const int& year) const{
          string name;
          string prevName;
          string curName;
          vector<string> names;
          for (const auto& kv : firstAndLastNames) {
            if (kv.first <= year && (names.empty() || names.back() != kv.second)) {
              names.push_back(kv.second);
              }
            }
          //creating a vector of duplicates in the vector called @names@ with type of vector<string>
          if (names.size() == 0) name = " with unknown ";
          else if (names.size() == 1) name = names[0];
          else if (names.size() > 1) {
            name = names[0];
            name += " (";
            for (int i = 1; i < names.size(); i++) {
              name += names[i];
              if (i == names.size() - 1) name += ")";
              else name += ", ";
            }
          }
          return name; 
        }
  };

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}