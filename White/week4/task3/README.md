# Обратимая функция с умножением и делением

### Условие
 
Добавьте в класс `Function` из задачи «Обратимая функция» обработку умножения ('*') и деления ('/'). Гарантируется отсутствие элементарных операций умножения и деления на `0`.

### Пример

#### Код

```c++
1   struct Image {
2     double quality;
3     double freshness;
4     double rating;
5   };
6
7   struct Params {
8     double a;
9     double b;
10    double c;
11  };
12
13  Function MakeWeightFunction(const Params& params, const Image& image) {
14    Function function;
15    function.AddPart('*', params.a);
16    function.AddPart('-', image.freshness * params.b);
17    function.AddPart('+', image.rating * params.c);
18    return function;
19  }
20
21  double ComputeImageWeight(const Params& params, const Image& image) {
22    Function function = MakeWeightFunction(params, image);
23    return function.Apply(image.quality);
24  }
25
26  double ComputeQualityByWeight(const Params& params, const Image& image, double weight) {
27    Function function = MakeWeightFunction(params, image);
28    function.Invert();
29    return function.Apply(weight);
30  }
31
32  int main() {
33    Image image = {10, 2, 6};
34    Params params = {4, 2, 6};
35    cout << ComputeImageWeight(params, image) << endl;
36    cout << ComputeQualityByWeight(params, image, 52) << endl;
37    return 0;
38  }
```

#### Вывод

```c++
1   72
2   5
```
