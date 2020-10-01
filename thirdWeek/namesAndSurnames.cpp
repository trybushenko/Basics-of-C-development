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
task:   Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.
        Считайте, что в каждый год может произойти не более одного изменения фамилии 
        и не более одного изменения имени. При этом с течением времени могут открываться всё новые факты из прошлого человека, 
        поэтому года́ в последовательных вызовах методов ChangeLastName и ChangeFirstName не обязаны возрастать.

        Гарантируется, что все имена и фамилии непусты.

        Строка, возвращаемая методом GetFullName, должна содержать разделённые одним пробелом имя и фамилию человека по состоянию на конец данного года.
            -Если к данному году не случилось ни одного изменения фамилии и имени, верните строку "Incognito".
            -Если к данному году случилось изменение фамилии, но не было ни одного изменения имени, верните "last_name with unknown first name".
            -Если к данному году случилось изменение имени, но не было ни одного изменения фамилии, верните "first_name with unknown last name".

        Пример:
            int main() {
                Person person;
                //Incognito
                person.ChangeFirstName(1965, "Polina");
                //Polina
                person.ChangeLastName(1967, "Sergeeva");
                //Polina Sergeeva
                for (int year : {1900, 1965, 1990}) {
                    cout << person.GetFullName(year) << endl;
                }
                //  Output:
                        Incognito
                        Polina with unknown last name
                        Polina Sergeeva

                person.ChangeFirstName(1970, "Appolinaria");
                //Polina Appolinaria
                for (int year : {1969, 1970}) {
                    cout << person.GetFullName(year) << endl;
                }
                //  Output:
                        Polina Sergeeva
                        Appolinaria Sergeeva    
                person.ChangeLastName(1968, "Volkova");
                Polina Volkova
                for (int year : {1969, 1970}) {
                    cout << person.GetFullName(year) << endl;
                }
                //  Output:
                        Polina Volkova
                        Appolinaria Volkova
                return 0;
            }

        Вывод:
            Incognito
            Polina with unknown last name
            Polina Sergeeva
            Polina Sergeeva
            Appolinaria Sergeeva
            Polina Volkova
            Appolinaria Volkova
        
        My output:
            Incognito
            Polina 
            Incognito
            Incognito
            Appolinaria with unknown last name
            Incognito
            Appolinaria with unknown last name

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
    private:
        map<int, string, greater<int>> yearAndFirstName;
        map<int, string, greater<int>> yearAndLastName;
};

int main() {
                Person person;
                //Incognito
                person.ChangeFirstName(1965, "Polina");
                //Polina
                person.ChangeLastName(1967, "Sergeeva");
                //Polina Sergeeva
                for (int year : {1900, 1965, 1990}) {
                    cout << person.GetFullName(year) << endl;
                }
                /*  Output:
                        Incognito
                        Polina with unknown last name
                        Polina Sergeeva
                */
                person.ChangeFirstName(1970, "Appolinaria");
                //Polina Appolinaria
                for (int year : {1969, 1970}) {
                    cout << person.GetFullName(year) << endl;
                }
                /*  Output:
                        Polina Sergeeva
                        Appolinaria Sergeeva
                */    
                person.ChangeLastName(1968, "Volkova");
                //Polina Volkova
                for (int year : {1969, 1970}) {
                    cout << person.GetFullName(year) << endl;
                }
                /*  Output:
                        Polina Volkova
                        Appolinaria Volkova
                */
                return 0;
            }