#include <BrokenLine.h>
#include "D:\Coding\ASD\Templates-Lab1-var5-task-3\src\BrokenLine.cc"
#include <iostream> 
using namespace Line;
using namespace std;

int main()
{
	BrokenLine<float> floatBrokenLine = BrokenLine(3.5f, 5.1f);
	BrokenLine<float> floatBrokenLine2 = BrokenLine(10.f, 20.f);

	BrokenLine<float> floatBrokenLine3 = BrokenLine(15.5f, 6.1f);
	BrokenLine<float> floatBrokenLine4 = BrokenLine(11.f, 120.f);


	BrokenLine<float> floatBrokenLine5 = floatBrokenLine + floatBrokenLine2;
	BrokenLine<float> floatBrokenLine6 = floatBrokenLine3 + floatBrokenLine4;
	BrokenLine<float> floatBrokenLine7 = floatBrokenLine5 + floatBrokenLine6;
	cout << floatBrokenLine7;
	return 0;
}
