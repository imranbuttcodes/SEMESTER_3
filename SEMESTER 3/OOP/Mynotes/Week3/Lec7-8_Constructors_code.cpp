/*			=== Recap ====
		Class, Object, Pillars, Access specifiers
		dot operator, setter getters

			===== Week 3 Lecture 7-8 ====
			====== TODAY's AGENDA =======
			1. Constructors (default, para, delegating)
			2. Constructors Overloading
			3. Member/constructor Initializer List
			4. Arrow Operator
			5. this pointer		(Fraction * this = &CallingObject)

Constructor: A sepcialized member fuinction who initializes/construct
the object.
			1. Its Name
			2. Return type
			3. Its Calling	(implicit, call once)

		// types:
		1. Default c-tor
		2. Parameterizede c-tor
		3. Copy c-tor
		4. Delegating c-tor
			
*/

#include <iostream>
#include <string>
using namespace std;


// Types: 1. Default Constructor
//	  2. Parameterized Constructor
//	  3. Copy Constructor
//	  4. Delegating Constructors
//	  5. Move Constructor	(C++11) {Pre-req: Move semantics)


class Fraction
{
private:
	int num;		// numerator
	int deno;		// denominator
public:
	Fraction() : num(0), deno(1)	// Member/constructor Initializer List
	{
		num = 0 ;
		 deno = 1 ;
		cout << "Default\n";
	}

	Fraction(int p) : Fraction(p)	// delegating c-tor
	{
		//this->num = p;		// equal to num = p ;
		//this->deno = 1;
		cout << "Delegating\n";
	}
	Fraction(int num, int deno) //: num(num) , deno(deno)        //  Parameterized c-tor
	{
		this->num = num;
		deno == 0 ? this->deno = 1 : this->deno = deno;       // ternary operator    
		// if (q==0){deno=1;}else{deno=q;}			  // input validation
		cout << "Parameterized\n";
	}

	

};
int main() {
	Fraction f_obj1;			// Default c-tor
	Fraction f_obj2(5,3);		// Para c-tor
	Fraction f_obj3(6);



	return 0;
}