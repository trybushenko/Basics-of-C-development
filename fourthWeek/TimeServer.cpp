#include <iostream>
#include <string>
#include <exception>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   Вам дана функция string AskTimeServer(), про которую известно следующее:
            -в процессе своей работы она обращается по сети к удалённому серверу, запрашивая текущее время;
            -если обращение к серверу прошло успешно, функция возвращает текущее время в виде строки;
            -если в процессе обращения к серверу возникла сетевая проблема, функция выбрасывает исключение system_error;
            -функция может выбрасывать другие исключения, чтобы сообщить о других проблемах.

        Используя функцию AskTimeServer, напишите класс TimeServer, используя интерфейс.

        Метод GetCurrentTime должен вести себя так:
            -он должен вызвать функцию AskTimeServer, записать её результат в поле last_fetched_time и вернуть значение этого поля;

            -если AskTimeServer выбросила исключение system_error, 
             метод GetCurrentTime должен его поймать и вернуть текущее значение поля last_fetched_time. 
             Таким образом мы скрываем от пользователя сетевые проблемы, возвращая значение, 
             которое было получено при последнем успешном обращении к серверу;

            -если AskTimeServer выбросила другое исключение, 
             метод GetCurrentTime должен пробросить его дальше, 
             потому что в рамках класса TimeServer мы не знаем, 
             как обрабатывать проблемы, не связанные со сбоями сети.
*/


class TimeServer {
    public:
        string GetCurrentTime() {
            try {
                last_fetched_time = AskTimeServer();
                return last_fetched_time;
            } catch(system_error& se) {
                return last_fetched_time;   
            }
        }
    private:
        string last_fetched_time = "00:00:00";
};


int main(int argc, const char** argv) {
     TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
    return 0;
}