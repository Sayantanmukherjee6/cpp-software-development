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

  void swap(Myvector<T>& newvector) {
    std::swap(elems, newvector.elems);
    std::swap(size, newvector.size);
    // Inefficient way of doing this would be
    // Myvector<T> temp{newvector}; // unnecessary temp
    // newvector = *this;
    //*this = temp;
  }

  // Move construct
  Myvector<T>(Myvector<T>&& newvector)
      : size{newvector.size}, elems{newvector.elems} {
    newvector.size = 0;
    newvector.elems = nullptr;  // no elements
  }

  // Alternative move construct
  // Myvector<T>(Myvector<T>&& newvector) : size{0}, elems{nullptr} {
  //   swap(newvector);
  // }

  T& operator[](int index) const { return elems[index]; }
  int get_size() const { return size; }
  T* begin() { return elems; }       // begin iterator
  T* end() { return elems + size; }  // end iterator

 private:
  T* elems;
  int size;
};

template <class T>
Myvector<T> operator*(const Myvector<T>& a, const Myvector<T>& b) {
  if (a.get_size() != b.get_size()) std::exit(EXIT_FAILURE);
  Myvector<T> res(a.get_size());
  for (int i = 0; i != a.get_size(); ++i) res[i] = a[i] * b[i];
  return res;
}

int main() {
  Myvector<double> v{100000};
  Myvector<double> v2{v};
  Myvector<double> v3{v};
  v3 = v * v2;
  for (const auto& x : v3) std::cout << x << std::endl;
}
