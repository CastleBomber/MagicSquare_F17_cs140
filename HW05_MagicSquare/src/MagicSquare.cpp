//============================================================================
// Name        : Vectors:	MagicSquare.cpp
// Author      : [CastleBombs]
// Date        : (THURS, 5 OCT 17)
// Class       : cs 140, C++ Object Oriented Programming
// Instructor  : Professor Jackie Kuehn
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * square class
*/
class square {
private:
	int nValue;

public:
	square(int value);	//"other" constructor
	void display();
};

/**
 * main() driver to test square class
 */
int main() {
	int value;
	cout << "Magic Square Value: " ;
	cin >> value;

	square magic(value);
	magic.display();
	//square magics(15);
	//magics.display();
	return 0;
}

/**
 * display magic square
 */
 void square::display()
 {
	//using matrix
	vector<vector<int> > matrix(nValue,vector<int>(nValue));
	vector<vector<int> >::iterator row;// *-_
	vector<int>::iterator col;// |||

	//store values into matrix
	int irow = 0;
	int icol = nValue/2;
	int j = 1;

	while(j <= nValue*nValue ){
		//Handles rndm exception cases
		if(irow < 0 && icol==nValue){
			icol = nValue-1;
			irow = 1;
		}
		if(irow < 0){
			irow = nValue-1;
		}
		if(icol == nValue){
			icol = 0;
		}

		if(matrix[irow][icol]){ // if spot taken
			irow++;//*
			irow++;//*
			icol--;//*
			continue;
		}else{
			matrix[irow][icol] = j; //open spot
			j++;
		}

		//Most important steps!
		irow--;
		icol++;
	}//w



	//  [row*-_][col|||]
	//display matrix's contents
	for(row = matrix.begin(); row != matrix.end(); row++){
		for(col = row->begin(); col != row->end(); col++){
			cout << *col << " ";
		}
		cout << endl;
}}//f

 /**
  * square constructor
  * @param value
  * 	magic number used to build square
 */
 square::square(int value)
 {
	 nValue = value;
 }
