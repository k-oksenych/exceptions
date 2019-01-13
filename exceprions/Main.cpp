#include <iostream>

#include "Array.h"

using namespace std;

int main()
{
	Array<int> ar1;

	try
	{
		ar1.Add(1);
		ar1.Add(2);
		ar1.Add(3);
		ar1.Add(4);
		ar1.Add(5);
		ar1.Add(6);
		ar1.Add(7);
		ar1.Add(8);
		ar1.Add(9);
		ar1.Add(10);
		//ar1.Add(10);

		//cout << ar1[10] << endl;

		//cout << ar1.IndexOf(25, 10) << endl;

		//cout << ar1.BinarySearch(10, 5, 10) << endl;
	}
	catch (ElementExistsException e)
	{
		cout << "This element exists in array" << endl;
	}
	catch (ArgumentOutOfRangeException e)
	{
		cout << "Argument out of range" << endl;
	}
	catch (ArgumentException e)
	{
		cout << "Incorrect arguments" << endl;
	}
}