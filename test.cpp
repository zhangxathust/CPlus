#include <iostream>
#include "mytime0.h"
#include "other.h"
#include "stock.h"

using namespace std;



/**
* @author zx
* 函数入口
*/
int main()
{
	//cout << "Hello world!" << endl;
	//testRef();

	//Stock stock1("zhang", 20, 40.0);
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;

	cout << "planning time = ";
	planning.show();
	cout << endl;

	return 0;
}