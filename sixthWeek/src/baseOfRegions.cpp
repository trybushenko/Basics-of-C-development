#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <chrono>


/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task: 	Имеется база регионов, представленная вектором структур Region
		Здесь Lang — идентификатор языка.
		Напишите функцию FindMaxRepetitionCount,
		принимающую базу регионов и определяющую,
		какое максимальное количество повторов (число вхождений одного и того же элемента) она содержит.
		Две записи (объекты типа Region) считаются различными, если они отличаются хотя бы одним полем.

			Вывод к командам из точки входа программы:
				3
				1
*/


enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};


auto giveTupleRegion(const Region& region) {
	return tie(region.std_name, region.parent_std_name, region.names, region.population);
}

bool operator==(const Region& lhs, const Region& rhs) {
	return giveTupleRegion(lhs) == giveTupleRegion(rhs);
}

bool operator<(const Region& lhs, const Region& rhs) {
	return giveTupleRegion(lhs) < giveTupleRegion(rhs);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
	vector<int> numbers;
	int maximum = 0;
	map<Region, int> elemAndOccurence;
	for (size_t i = 0; i < regions.size(); i++) {
		if (elemAndOccurence.count(regions[i]) == 1) {
			++elemAndOccurence[regions[i]];
		}
		else {
			elemAndOccurence[regions[i]] = 1;
		}
		if (elemAndOccurence[regions[i]] > maximum) maximum = elemAndOccurence[regions[i]];
	}

	return maximum;
}

int main() {
  cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      },
  }) << endl;

  cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Toulouse",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          31
      },
  }) << endl;

  return 0;
}
