#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <utility>
#include <map>
#include <set>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task: 	learning file, where I get to know about operator of comparison
*/

struct Date {
	int year, month, day;
};

bool operator<(const Date& lhs, const Date& rhs) {
	// type of next line tuple(const int&, const string&, const int&)
	return tie(lhs.year, lhs.month, lhs.day) < tie(rhs.year, rhs.month, rhs.day);
}

class Cities {
	public:
		tuple<bool, string> FindCountry(const string& city) const {
			if (city_to_country.count(city) == 1) {
				return {true, city_to_country.at(city)};
			} else if (ambigious_city.count(city) == 1){
				return {false, "Ambigious"};
			} else {
				return {false, "Don't exist"};
			}
		}
	private:
		map<string, string> city_to_country;
		set<string> ambigious_city;
};

/*
int main(int argc, const char** argv) {
	cout << (Date{2017, 6, 8} < Date{2017, 1, 26}) << endl;
	//auto t = tie(7, "C++", true); raises an exception  as so as tie is for single using -
	//a tuple of references
	auto t1 = make_tuple(7, "C++", true);
	cout << get<1>(t1) << endl;
	//tuple<int&, string&, bool&> r(7, "C++", true);
	pair<int, string> t2(7, "C++");
	cout << t2.first << " " << t2.second << endl;
	map<int, string> digits{{1, "one"}};
	for (const auto& [key, value] : digits) {
		cout << key << ' ' << value << "\n";
	}


	Cities cities;
	//bool success; alternative variant of realization
	//string message; alternative variant of realization
	//tie(success, message) = cities.FindCountry("Volgograd"); alternative variant of realization
	auto [success, message] = cities.FindCountry("Volgograd");
	cout << success << " - " << message << endl;
	return 0;
}

*/
