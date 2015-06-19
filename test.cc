#include <iostream>

using namespace std;

bool _arr[8][8];
size_t _d = 8;
void print() {
	for(int i = 7;i > -1;--i) { 
		for(int j = 0;j < 8;++j)
			cout << _arr[j][i] << ' ';
		cout << endl;
	}
	cout << endl << endl;
}

/*
 ___
   |
*/
void d1(int frame) {
	int x = frame;
	int y = 0;
	while(x > -1) {
		if((y < _d) && (x < _d))
			_arr[x][y] = 1;
		x -= 1;
		y += 1;
	} 
}
/*
  ____	
 |
 |

*/
void d2(int frame) {
	int x = _d - 1;
	int y = frame;
	while(y > -1) {
		if((y < _d) && (x < _d))
			_arr[x][y] = 1;
		x -= 1;
		y -= 1;
	}
}


int main() {
	for(int i = 0;i < 8;++i) for(int j = 0;j < 8;++j)
		_arr[i][j] = 0;
	/*for(int i = 15; i > -1;--i) {
		d2up(i);
		print();
	}*/
	/*for(int i = 0; i < 15;++i) {
		d1up(i);
		print();
	}*/
	for(int i = 14, j = 0;i > -1, j < 15;--i, ++j) {
		d1(i);
		d2(i);
		d1(j);
		d2(j);
		print();
	}
	return 0;
}

