#include <iostream>
#include <cstdlib>

// Class MyVector
template <class T>
class Myvector {
 public:
  // Allocate i elements, initialised as 0, 1, ..., 1-1, n
  explicit Myvector<T>(int i) : size{i} {
    elems = new T[i]();
    for (int j = 0; j < i; ++j) {
      elems[j] = j;
    }
  }
  // Destructor
  ~Myvector<T>() { delete[] elems; }

  // Copy constructor
  Myvector<T>(const Myvector<T>& newvector) : size{newvector.size} {
    elems = new T[newvector.size];
    for (int i = 0; i < newvector.get_size(); ++i)
      elems[i] = newvector.elems[i];
  }

  // Assignment operator
  Myvector<T>& operator=(const Myvector<T>& newvector) {
    size = newvector.size;
    elems = new T[newvector.size];
    for (int i = 0; i < newvector.get_size(); ++i)
      elems[i] = newvector.elems[i];
    return *this;
  }

  T& operator[](int index) const { return elems[index]; }
  int get_size() const { return size; }
  T* begin() { return elems; }       // begin iterator
  T* end() { return elems + size; }  // end iterator

 private:
  T* elems;
  int size;
};

int main() {
  Myvector<double> v{10};
  std::cout << "Elements in v" << std::endl;
  for (const auto& x : v) std::cout << x << std::endl;
  Myvector<double> v2{v};
  std::cout << "Elements in v2" << std::endl;
  for (const auto& x : v2) std::cout << x << std::endl;
  std::cout << "How about the size of v now:" << v.get_size() << std::endl;
}
