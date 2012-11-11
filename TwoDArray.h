#ifndef __TWO_D_ARRAY__
#define __TWO_D_ARRAY__

#include <vector>
using namespace std;

template <typename T>
class TwoDArray {
private:
	vector<vector<T> > theArray;
	int numRows;
	int numColumns;
	T deffy;
	
public:
	TwoDArray<T>(int r, int c, T def);
	~TwoDArray<T>();
	void insert(int r, int c, T value);
	T access(int r, int c);
	void remove(int r, int c);
	void print();
	int getNumRows();
	int getNumCols();
};

#endif
