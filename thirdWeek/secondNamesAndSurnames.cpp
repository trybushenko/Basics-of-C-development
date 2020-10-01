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
task:   Дополните класс из предыдущей задачи «Имена и фамилии — 1» методом GetFullNameWithHistory:

        class Person {
            public:
              void ChangeFirstName(int year, const string& first_name) {
                // добавить факт изменения имени на first_name в год year
              }
              void ChangeLastName(int year, const string& last_name) {
                // добавить факт изменения фамилии на last_name в год year
              }
              string GetFullName(int year) {
                // получить имя и фамилию по состоянию на конец года year
              }
              string GetFullNameWithHistory(int year) {
                // получить все имена и фамилии по состоянию на конец года year
              }
            private:
              // приватные поля
        };

        В отличие от метода GetFullName, 
        метод GetFullNameWithHistory должен вернуть не только последние имя и 
        фамилию к концу данного года, но ещё и все предыдущие имена и фамилии в 
        обратном хронологическом порядке. Если текущие факты говорят о том, что человек два раза 
        подряд изменил фамилию или имя на одно и то же, второе изменение при формировании истории нужно игнорировать.

        Для лучшего понимания формата см. примеры.
            Пример 1:
                int main() {
                  Person person;

                  person.ChangeFirstName(1900, "Eugene");
                  person.ChangeLastName(1900, "Sokolov");
                  person.ChangeLastName(1910, "Sokolov");
                  person.ChangeFirstName(1920, "Evgeny");
                  person.ChangeLastName(1930, "Sokolov");
                  cout << person.GetFullNameWithHistory(1940) << endl;

                  return 0;
                }
            Вывод:
                Evgeny (Eugene) Sokolov
            
            Пример 2:
                int main() {
                  Person person;

                  person.ChangeFirstName(1965, "Polina");
                  person.ChangeLastName(1967, "Sergeeva");
                  for (int year : {1900, 1965, 1990}) {
                    cout << person.GetFullNameWithHistory(year) << endl;
                  }

                  person.ChangeFirstName(1970, "Appolinaria");
                  for (int year : {1969, 1970}) {
                    cout << person.GetFullNameWithHistory(year) << endl;
                  }

                  person.ChangeLastName(1968, "Volkova");
                  for (int year : {1969, 1970}) {
                    cout << person.GetFullNameWithHistory(year) << endl;
                  }

                  person.ChangeFirstName(1990, "Polina");
                  person.ChangeLastName(1990, "Volkova-Sergeeva");
                  cout << person.GetFullNameWithHistory(1990) << endl;

                  person.ChangeFirstName(1966, "Pauline");
                  cout << person.GetFullNameWithHistory(1966) << endl;

                  person.ChangeLastName(1960, "Sergeeva");
                  for (int year : {1960, 1967}) {
                    cout << person.GetFullNameWithHistory(year) << endl;
                  }

                  person.ChangeLastName(1961, "Ivanova");
                  cout << person.GetFullNameWithHistory(1967) << endl;

                  return 0;
                }
            Вывод:
                Incognito
                Polina with unknown last name
                Polina Sergeeva
                Polina Sergeeva
                Appolinaria (Polina) Sergeeva
                Polina Volkova (Sergeeva)
                Appolinaria (Polina) Volkova (Sergeeva)
                Polina (Appolinaria, Polina) Volkova-Sergeeva (Volkova, Sergeeva)
                Pauline (Polina) with unknown last name
                Sergeeva with unknown first name
                Pauline (Polina) Sergeeva
                Pauline (Polina) Sergeeva (Ivanova, Sergeeva)

            Пример 3:
                int main() {
                  Person person;

                  person.ChangeFirstName(1965, "Polina");
                  person.ChangeFirstName(1965, "Appolinaria");

                  person.ChangeLastName(1965, "Sergeeva");
                  person.ChangeLastName(1965, "Volkova");
                  person.ChangeLastName(1965, "Volkova-Sergeeva");

                  for (int year : {1964, 1965, 1966}) {
                    cout << person.GetFullNameWithHistory(year) << endl;
                  }

                  return 0;
                }
            Вывод:
                Incognito
                Appolinaria Volkova-Sergeeva
                Appolinaria Volkova-Sergeeva
*/



class Person {
    public:
        void ChangeFirstName(int year, const string& first_name) {
          yearAndFirstName[year] = first_name;
        }
        void ChangeLastName(int year, const string& last_name) {
          yearAndLastName[year] = last_name;
        }
        string GetFullName(int year) {
            string name, surname, result;
            map<int, string> :: iterator nameIterator, surnameIterator;
            nameIterator = yearAndFirstName.lower_bound(year);
            surnameIterator = yearAndLastName.lower_bound(year);
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
        string GetFullNameWithHistory(int year) {
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

        string getAllSurNames(const map<int, string, greater<int>>& firstAndLastNames, const int& year) {
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
  Person person;
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");

  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");

  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");

  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");

  cout << person.GetFullNameWithHistory(1966) << endl;
  person.ChangeLastName(1960, "Sergeeva");

  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");

  cout << person.GetFullNameWithHistory(1967) << endl;
  return 0;
}