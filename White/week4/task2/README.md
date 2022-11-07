# Обратимая функция

### Условие
 
Реализуйте рассказанный на лекции класс `Function`, позволяющий создавать, вычислять и инвертировать функцию, состоящую из следующих элементарных операций:

* прибавить вещественное число x;
* вычесть вещественное число x.

При этом необходимо объявить константными все методы, которые по сути такими являются.

### Замечание

* Более детальное описание задачи с подробным разбором реализации вышеуказанного класса приводится в двух предшествующих видеолекциях.
* На проверку пришлите файл, содержащий реализацию вышеуказанного класса `Function`.

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
15    function.AddPart('-', image.freshness * params.a + params.b);
16    function.AddPart('+', image.rating * params.c);
17    return function;
18  }
19
20  double ComputeImageWeight(const Params& params, const Image& image) {
21    Function function = MakeWeightFunction(params, image);
22    return function.Apply(image.quality);
23  }
24
25  double ComputeQualityByWeight(const Params& params, const Image& image, double weight) {
26    Function function = MakeWeightFunction(params, image);
27    function.Invert();
28    return function.Apply(weight);
29  }
30
31  int main() {
32    Image image = {10, 2, 6};
33    Params params = {4, 2, 6};
34    cout << ComputeImageWeight(params, image) << endl;
35    cout << ComputeQualityByWeight(params, image, 46) << endl;
36    return 0;
37  }
```

#### Код

```c++
1   36
2   20
```
