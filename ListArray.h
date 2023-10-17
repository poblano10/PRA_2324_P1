#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
    T* arr;     	// Puntero al inicio del array
    int max;            // Tamaño actual del array
    int n;              // Número de elementos en la lista
    static const int MINSIZE = 2; // Tamaño mínimo del array

    void resize(int new_size);
        // miembros privados

    public:
     ListArray();  // Constructor
    ~ListArray(); // Destructor
    T operator[](int pos);
   friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list);
};
