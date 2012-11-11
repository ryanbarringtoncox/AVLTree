#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
using std::cout;
using std::endl;

#include "TwoDArray.h"

template <typename T>
TwoDArray<T>::TwoDArray(int r, int c, T def) {
	assert(r > 0 && c > 0);	
	numRows = r;
	numColumns = c;
	deffy = def;
	theArray.resize(r);	
	for(int i = 0; i < r; ++i) {
		theArray[i].resize(c);
	}
	
	for(int i = 0; i < numRows; ++i) {
		for (int j = 0; j < numColumns; ++j) {
			theArray[i][j]=def;
		}
	}	
}

template <typename T>
TwoDArray<T>::~TwoDArray() {
}

template <typename T>
void TwoDArray<T>::insert(int r, int c, T def) {
	assert(r >= 0 && c >= 0 && r < numRows && c < numColumns);	
	theArray[r][c] = def;
}

template <typename T>
T TwoDArray<T>::access(int r, int c) {
	assert(r >= 0 && c >= 0 && r < numRows && c < numColumns);	
	return theArray[r][c];
}

template <typename T>
void TwoDArray<T>::remove(int r, int c) {	
	assert(r >= 0 && c >= 0 && r < numRows && c < numColumns);	
	theArray[r][c] = deffy;
}

template <typename T>
void TwoDArray<T>::print() {	
	for(int i = 0; i < numRows; ++i) {
		for (int j = 0; j < numColumns; ++j) {
			cout << theArray[i][j]	<< " ";
		}
		cout << endl;
	}	
}

template <typename T>
int TwoDArray<T>::getNumRows() {
	int n = numRows;
	return n;
}

template <typename T>
int TwoDArray<T>::getNumCols() {
	int n = numColumns;
	return n;
}

template class TwoDArray<int>;
template class TwoDArray<double>;
template class TwoDArray<std::string>;
