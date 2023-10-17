#include <ostream>
#include "List.h"


template <typename T>
class ListArray : public List<T> {
private:
    T* arr; // Puntero al inicio del array
    int max; // Tamaño actual del array
    int n;   // Número de elementos en la lista
    static const int MINSIZE = 2; // Tamaño mínimo del array

public:
    // Constructor
    ListArray() {
        max = MINSIZE;
        n = 0;
        arr = new T[max];
    }

    // Destructor
    ~ListArray() {
        delete[] arr;
    }

    // Métodos heredados de la interfaz
   virtual  void insert(int pos, T e) override {
        // Implementación de insert
    if(pos > n || pos < 0){
      throw std::out_of_range("Número fuera de rango del array");
    }
    if(size() == max)
	    resize(size()*2)
    }
   if(pos==0){
	   prepend(e);
      }
      else if(pos == n){
	append(e);
      }
      else{
	      for(int i = n ; i > pos ; i--){
		      arr[i] = arr[i-1];	 		
	      }
	      arr[pos] = e;
	      n++;
      }
 	
  } 
  virtual  void prepend(T e) override{
      if(size() == max)
	     resize(size()*2);
      else{
	      for(int i = n; i > 0; i --){
		      arr[i] = arr[i-1];

	      }
arr[0] = e;
	      n++;
      } 
    }

    virtual void append(T e) override{
      if(size() == max)
             resize(size()*2);

      arr[n] = e;
      n++;
    }

     virtual T remove(int pos) override{
      T aux;
	  if(pos > size()-1 || pos < 0){
	throw std::out_of_range("Número fuera de rango del array");
      }
      else{
	    aux = arr[pos];  
	    
	    for(int i = pos; i < n; i++){
		arr[i] = arr[i+1];
	      }
	   n--;
	return aux;
      }
      
    }
    
  virtual T get(int pos) override{
      if(pos > size()-1 || pos < 0){
	throw std::out_of_range("Número fuera de rango del array");
      }
      else{
	return arr[pos];
      }
    }
  virtual int search(T e) override{
      for(int i = 0; i < n ; i++){
	if ( arr[i] == e)
	  return i;
      }
      return -1;
    }
  virtual bool empty() override{
      if(n == 0){
	return true;
      } else{ return false;}
    }
    
  virtual int size() override{
      return n;
    }

    // Sobrecarga del operador []
    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Index out of range");
        }
        return arr[pos];
    }

    // Sobrecarga global del operador <<
    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
        for (int i = 0; i < list.n; i++) {
            out << list.arr[i] << " ";
        }
        return out;
    }

private:
    // Método privado para redimensionar el array
    void resize(int new_size) {
        T* new_arr = new T[new_size];
        for (int i = 0; i < n; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
    }
};

