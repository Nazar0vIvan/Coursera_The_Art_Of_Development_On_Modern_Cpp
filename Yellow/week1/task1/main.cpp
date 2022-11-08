#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

class Matrix
{
public:
  Matrix(int num_rows = 0, int num_cols = 0){
    Reset(num_rows, num_cols);
  };

  int At(int row, int col) const{
    return m_data.at(row).at(col);
  }

  int& At(int row, int col){
    return m_data.at(row).at(col);
  }

  int GetNumRows() const{ return m_num_rows; }

  int GetNumColumns() const{ return m_num_cols; }

  void Reset(int num_rows, int num_cols){
    if (num_rows < 0){
      throw out_of_range("num_rows must be >= 0");
    }
    if (num_cols < 0){
      throw out_of_range("num_cols must be >= 0");
    }
    if (num_rows == 0 || num_cols == 0){
      num_rows = num_cols = 0;
    }

    m_num_rows = num_rows;
    m_num_cols = num_cols;
    m_data.assign(num_rows, vector<int>(num_cols));
  }

private:
  int m_num_rows;
  int m_num_cols;
  vector<vector<int>> m_data;
};

bool operator==(const Matrix& m1, const Matrix& m2){
  if (m1.GetNumRows() != m2.GetNumRows()){
    return false;
  }

  if (m1.GetNumColumns() != m2.GetNumColumns()){
    return false;
  }

  for (int row = 0; row < m1.GetNumRows(); ++row){
    for (int column = 0; column < m1.GetNumColumns(); ++column){
      if (m1.At(row, column) != m2.At(row, column)){
        return false;
      }
    }
  }

  return true;
}

Matrix operator+(const Matrix& m1, const Matrix& m2){
  if (m1.GetNumRows() != m2.GetNumRows()){
    throw invalid_argument("Mismatched number of rows");
  }

  if (m1.GetNumColumns() != m2.GetNumColumns()){
    throw invalid_argument("Mismatched number of columns");
  }

  Matrix result(m1.GetNumRows(), m1.GetNumColumns());
  for (int row = 0; row < result.GetNumRows(); ++row){
    for (int column = 0; column < result.GetNumColumns(); ++column){
      result.At(row, column) = m1.At(row, column) + m2.At(row, column);
    }
  }

  return result;
}



istream& operator>>(istream& in, Matrix& matrix){
  int num_rows, num_columns;
  in >> num_rows >> num_columns;

  matrix.Reset(num_rows, num_columns);
  for (int row = 0; row < num_rows; ++row){
    for (int column = 0; column < num_columns; ++column){
      in >> matrix.At(row, column);
    }
  }

  return in;
}

ostream& operator<<(ostream& out, const Matrix& matrix){
  out << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
  for (int row = 0; row < matrix.GetNumRows(); ++row){
    for (int column = 0; column < matrix.GetNumColumns(); ++column){
      if (column > 0){
        out << " ";
      }
      out << matrix.At(row, column);
    }
    out << endl;
  }

  return out;
}



int main(){

  Matrix m1;
  Matrix m2;
  try{
      Matrix m1 = { 0, 6 };
      Matrix m2 = { 7, 0 };
      cout << (m1 == m2 ? "yes" : "no") << endl;
      cout << m1 + m2 << endl;
  }
  catch(exception& ex){
      cout << ex.what() << endl;
  }

  return 0;
}
