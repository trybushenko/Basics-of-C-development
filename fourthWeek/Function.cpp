#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   Реализуйте рассказанный на лекции класс Function, 
        позволяющий создавать, вычислять и инвертировать функцию, 
        состоящую из следующих элементарных операций:

            -прибавить вещественное число x;
            -вычесть вещественное число x.

        При этом необходимо объявить константными все методы, которые по сути такими являются.

        Замечание:
        Более детальное описание задачи с подробным разбором 
        реализации вышеуказанного класса приводится в двух предшествующих видеолекциях.

        Пример   
*/
/*
struct Image {
    double quality;
    double freshness;
    double rating;
};

struct Params {
    double a;
    double b;
    double c;
};
*/
class FunctionPart {
    private:
        char operation;
        double value;
    public:
        FunctionPart(char new_operation, double new_value) {
            operation = new_operation;
            value = new_value;
        }
        double Apply(double source_value) const {
            double final_value;
            if (operation == '+') final_value = source_value + value;
            else if (operation == '-') final_value = source_value - value;
            else if (operation == '*') final_value = source_value * value;
            else if (operation == '/') final_value = source_value / value; 
            return final_value;
        }
        void Invert() {
            if (operation == '+') operation = '-';
            else if (operation == '-') operation = '+';
            else if (operation == '*') operation = '/';
            else if (operation == '/') operation = '*';
        }
};

class Function {
    public:
        void AddPart(char operation, double value) {
            parts.push_back({operation, value});
        }
        double Apply(double value) const {
            for (const FunctionPart& part : parts) value = part.Apply(value);
            return value;
        }
        void Invert() {
            for (FunctionPart& part : parts) part.Invert();
            reverse(begin(parts), end(parts));
        }
    private:
        vector<FunctionPart> parts;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
    Function function;
    function.AddPart('-', image.freshness * params.a + params.b);
    function.AddPart('+', image.rating * params.c);
    return function;
}

double ComputeImageWeight(const Params& params,
                          const Image& image) {
    Function function = MakeWeightFunction(params, image);
    return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image, 
                              double weight) {
    Function function = MakeWeightFunction(params, image);
    function.Invert();
    return function.Apply(weight);
}

