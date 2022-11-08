# Написать объявление класса

### Условие

Вам дано полное определение класса `Rectangle`

```c++
1   class Rectangle {
2   public:
3       Rectangle(int width, int height)
4       {
5         width_ = width;
6         height_ = height;
7       }
8 
9       int GetArea() const {
10        return width_ * height_;
11      }
12  
13      int GetPerimeter() const {
14        return 2 * (width_ + height_);
15      }
16
17      int GetWidth() const { return width_; }
18      int GetHeight() const { return height_; }
19
20  private:
21      int width_, height_;
};
```