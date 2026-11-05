#ifndef DYV_H
#define DYV_H

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
int busquedaBinaria(const T& X, const std::vector<T>& V, int ini, int fin){
	if (ini > fin){
		std::cout << "No se encuentra en el array" << std::endl;
		return -1;
	}

	int medio = (ini + fin)/2;
	
	if(V[medio] == X){
		return medio;
	
	}else if (V[medio] > X){
		return busquedaBinaria(X, V, ini, medio - 1);
	
	}else{
		return busquedaBinaria(X, V, medio + 1, fin);
	
	}
}

template <typename T> 
int partition(std::vector<T>& V, int ini, int fin){
    T pivote = V[fin];
    int i = ini - 1;
    for (int j=ini; j<fin; j++){
		if(V[j] <= pivote){
         
			std::swap (V[i], V[j]);
         
			i++;

         }
     }

     std::swap(V[i + 1], V[fin]);

    return i + 1;
}


template <typename T>
void quicksort(std::vector<T>& V, int ini, int fin){
	if(ini < fin){
		int pivot = partition(V, ini, fin);
		quicksort(V, ini, pivot - 1);
		quicksort(V, pivot + 1, fin);
	}
}

#endif
