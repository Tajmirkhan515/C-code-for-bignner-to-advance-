
// overloaded ‘+’ operator concatenates strings
#include <iostream>
using namespace std;
#include <string.h> //for strcpy(), strcat()


class String //user-defined string type
{
private:
	
	char str[30]; //holds a string
public:
	String() //constructor, no args
	{
		strcpy_s(str, " ");
	}
	String(const char *s) //constructor, one arg
	{
		strcpy_s(str, s);
	}
	void show() 
	{
		cout << str<<endl;
	}
	String operator + (String ss)  //add Strings
	{

		String temp; //make a temporary String
		if (strlen(str) + strlen(ss.str) < 30)
		{
			strcpy_s(temp.str, str); //left side of the operator copy this string to temp
			strcat_s(temp.str, ss.str); //right side of the operator add the argument string
		}
		else
		{
			cout << "overflow" << endl;
		}
		return temp; //return temp String
	}
};

int main()
{
	String s1 = "hel"; 
	String s2 = "lo"; 
	String s3; //uses constructor 1

	s3 = s1 + s2; //concatenate s2 to s1,
	
	s3.show(); //display s3
	cout << endl;
	return 0;
}