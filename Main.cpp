
#include <iostream>
#include <windows.h>
//#include <boost>


using namespace std;

	HWND consoleWindow = GetConsoleWindow();

	
	
#define WX 190
#define WY 190
#define MAX 201


bool trouble = false;

typedef class A2PS 
{
	public : int D[MAX] = {0};
	public: int size = 0;
public:	bool sign = 0;



};



void helloworld()
{
	
	while(1)
	{
		int i=0;
		while(i<200)
		{
			i++;
				 system("color b0");
		}
		
		int j=0;
    	while(j<200)
		{
			j++;
				 system("color a3");
		}
	
	}
   
}


A2PS input();

bool checks(string);  //Proccecing DATA

A2PS StringToA2PS(string);   // Convert String To A2PS Type

void SBUCalOUT(A2PS);

A2PS AnayzeData(A2PS);

A2PS Sum(A2PS , A2PS);	     /// Sum a + (-b)  is Sub a, b

void shaking();

int maxsize(A2PS , A2PS);  

bool MaxData(A2PS , A2PS);

A2PS Sub(A2PS , A2PS);

A2PS Mul(A2PS , A2PS);

A2PS ShiftRight(A2PS , int);   /// Shift Right
/*
eg:
		ShiftRight(13 , 2) => 0013


*/

A2PS Divi(A2PS , A2PS);

A2PS Sqr(A2PS);

bool IsSame(A2PS , A2PS);  // Chacking 2 input if same returm 1

void Location(int , int);    /// Handel Location

void ArashASCIGART();  //Handel Graphic



// Main Program

int main()
 {

 //boost::thread thrd(&helloworld);
   //  thrd.join();	
	SetWindowPos(consoleWindow, 0, WX, WY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);  ///Graphical
	
STR:
	  trouble=0;
	ArashASCIGART();  //Graphic
	
	A2PS a , b;
	
	Location(2,2); //Graphic
	cout<<"First Num:";
	Location(2,4); //Graphic
	cout<<char(175)<<"  ";
			
			// cahr 175 is  //Graphic
			
	a = input();
	
	if(trouble)

		goto ProblemF;
	
	
	//////////////////////////////
int op;
	
	Location(37,6);
	cout<<"So what Can I do for you ? ";
	Location(37,7);
	cout<<"\t1. "<<char(175)<<"   +";
	Location(37,8);
	cout<<"\t2. "<<char(175)<<"   -";
	Location(37,9);
	cout<<"\t3. "<<char(175)<<"   *";
	Location(37,10);
	cout<<"\t4. "<<char(175)<<"   /";
	Location(37,11);
	cout<<"\t5. "<<char(175)<<"   "<<char(251);
	Location(37,13);
	cout<<char(175)<<"  ";
	
	// Char 175 is Graphical Char
	
	cin>>op;
	
	/////////////////////////////
	
	getchar();
	
	Location(2,15);
	


  if (!(op/10))
   {
	
	
	
	if(op == 5) {
		cout<<char(175)<<"  "<<char(251);
		SBUCalOUT(a);
		cout<<" = ";
		SBUCalOUT(Sqr(a));
		goto Final;
	}


	cout<<"Second Num:";
	Location(2,17);
	cout<<char(175)<<"  ";
	
	b = input();
	
	if(trouble)
		goto ProblemF;
		
	Location(2,19);
	cout<<char(175)<<"  ";
		
	if (op == 1) {
		
		cout<<" = ";
		
		if(!a.sign) {
			
			if(!b.sign) {
				
				SBUCalOUT(Sum(a , b));
				goto Final;
				
			}
			
			else {
				
				SBUCalOUT(Sub(a , b));
				goto Final;
				
			}

		}
		
		else {
			
			if(!b.sign) {
				
				SBUCalOUT(Sub(b , a));
				goto Final;
				
			}
			
			else {
				
				A2PS c;
				c = Sum(a , b);
				c.sign = true;
				SBUCalOUT(c);
				goto Final;
				
			}
						
		}
		
	}

	if (op == 2)    // sub
	{
		
		cout<<" = ";
		
		/* eg
		
		a=23  a.sign = 0
		a=23 a.sign=1
		a=-23 a.sign=1
		
		*/
		
		
		
		if(a.sign==0)    // eg : a=23
		
		 {	
			
			if(b.sign==0) {
				// eg 23,14
				SBUCalOUT(Sub(a , b));
				goto Final;
				
			}
			
			else {
				// 23 , -13
				SBUCalOUT(Sum(a , b));
				goto Final;
				
			}
			
		}
		
		else   // a = -23
		
		 {
			
			if(b.sign==0)  // a:-23  b:
			{
				
				A2PS c;
				c = Sum(a , b);
				c.sign = true;
				SBUCalOUT(c);
				goto Final;
				
			}
			
			else {
				
				SBUCalOUT(Sub(b , a));
				goto Final;
				
			}
						
		}
	}
	
	if (op == 3) {
		
		cout<<" = ";
		SBUCalOUT(Mul(a , b));
		goto Final;
	}
	
	if (op == 4) {
		A2PS c;
		c = Divi(a , b);
		if(trouble)
			goto ProblemF;
		cout<<" = ";
		SBUCalOUT(c);
		goto Final;
	}
	
	
}

else
{
	
		//	op=0;
		MessageBox(NULL, TEXT( "Sorry My Ability is LIMITED " ), TEXT( "Error" ), MB_OK |  MB_ICONASTERISK );
		////  //Graphical MessageBox
		goto ProblemF;

}

Final:
	
	{
		system("color f9");
		  Location(40,15);
		
system("pause");
	
	goto STR;
	}

	
ProblemF:
	
	{		
			trouble = false;
			Location(0,23);
	
//
//

	
shaking();


 //Graphic
  //Shaking... :)
 
 //Graphic
//// Shaking Finish


cout<<endl;
  
  
  Location(40,18);
system("pause");


	goto STR;
	}

	
}

// Function defenitions

A2PS input() 
{
	
	char s[MAX];
	A2PS out;
	int a[MAX];
	CONSOLE_SCREEN_BUFFER_INFO csbi;
 	GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ),&csbi);
 	cout<<"0";
 	Location(csbi.dwCursorPosition.X , csbi.dwCursorPosition.Y);
	
	do {
		
		cin.getline (s , MAX);
		
		if ( checks(s) )
			out = StringToA2PS(s);
		
		else {
			
			MessageBox(NULL, TEXT( "Wrong Input!" ), TEXT( "Error" ), MB_OK );
			
			trouble = true;
			return out;
			
		}
		
	} while ( !checks(s) );
	
	return AnayzeData(out);
}


A2PS StringToA2PS(string s) {
	
	A2PS out;
	
	bool sign = 0;
	int i = 0;
	
	
	for ( ; i < s.size() && ( s[i] == '-' || s[i] == '+' ) ; i++ )
		if(s[i] == '-')
			sign = !sign;
	
	int j = 0;
	
	for ( ; i < s.size() ; i++ )
		out.D[j++] = int(s[i] - '0');
	
	out.size = j;
	out.sign = sign;
	
	return out;///
}


bool checks(string s)
 {
	
	bool sign = true;
	
	for(int i = 0 ; i < s.size() ; i++ ) 
	{
	
		if( !(s[i] == '-' || s[i] == '+') && sign)
		 {
			
			if(s[i] >= '0' && s[i]<='9')
				sign = false;
		
			else
				return false;
		
		}
		
		if( !sign && !(s[i]>='0' && s[i]<='9') )
			return false;

	}
	
	return true;
}


void SBUCalOUT(A2PS in) {
	
	if(in.sign)
		cout<<"-";
	
	for(int i = 0 ; i < in.size ; i++ )
		cout<<in.D[i];

}


A2PS AnayzeData(A2PS a) {
	
	int i ;
	
	for ( i = 0 ; i < a.size - 1 && a.D[i] == 0 ; i++ );
	

	for (int j = i ; j < a.size ; j++ )
		a.D[j-i]=a.D[j];
		
	a.size = a.size - i;
	
	return a;
	
}


A2PS Sum(A2PS a , A2PS b) {
	
	A2PS out;
	out.sign = false;

	out.size = maxsize(a,b)+1;
	
	int Dcarry = 0;
	int temp;
	
	for ( int i = 0 ; i <= out.size ; i++ ) {
		
		temp =  (a.D[a.size - i] * ((a.size - i) >= 0) ) + ( b.D[b.size - i] * ((b.size - i) >= 0) ) + Dcarry;
		
		out.D[out.size - i] = temp % 10;
		
		Dcarry = temp / 10;
	}
	

	
	return AnayzeData(out);
}


int maxsize(A2PS a, A2PS b) {
	
	return (a.size > b.size) ? a.size : b.size;
	
}


bool MaxData(A2PS a , A2PS b) {
	
	if (a.size > b.size)
		return true;

	if (b.size > a.size)
		return false;
	
	for ( int i = 0 ; i < a.size ; i++ ) {
		
		if(a.D[i] > b.D[i])
			return true;
		if(b.D[i] > a.D[i])
			return false;
			
	}
	
	return true;
}


A2PS Sub(A2PS a , A2PS b) {
	
	A2PS temp;
	int borrow = 0;
	int subtemp;
	A2PS out;
	
	if ( !MaxData(a,b) )
	 {
		swap(a,b);
		out.sign = true;
		
	}
	
	out.size = maxsize(a,b)+1;

	
	for ( int i = 0 ; i < out.size ; i++ ) {
		
		subtemp = a.D[a.size - i] * ( (a.size - i) >= 0 ) - b.D[b.size - i] * ( (b.size - i) >= 0 )- borrow;
		
		if (subtemp < 0) {
			subtemp +=10;
			borrow = 1;
		}
		else
			borrow=0;
			
		out.D[out.size - i] = subtemp;
	}
	
	return AnayzeData(out);
}


A2PS Mul(A2PS a, A2PS b) {
	
	A2PS out;
	

	out.sign = (a.sign xor b.sign);
	out.size = a.size + b.size;
	
	int m = 0;
	
	for ( int i = 0 ; i <= out.size ; i++ ) {
		
		for ( int j = 0 ; j < i ; j++ )
			m += a.D[a.size - j - 1] * (j < a.size) * b.D[b.size - i + j] * (b.size - i + j >= 0);
		
		out.D[out.size - i] = m%10;
		m = m/10; 
	}
	
	while ( m > 0 )
	
  {
		out = ShiftRight(out , 1);
		out.D[0] = m%10;
		m/=10;
	}
	
	return AnayzeData(out);	
}


A2PS ShiftRight(A2PS in , int L) {
	
	A2PS out = in;
	
	for ( int i = out.size + L - 1 ; i >= L ; i-- )
		out.D[i] = out.D[i-L];
	
	for ( int i = L - 1 ; i >= 0 ; i--)
		out.D[i] = 0;
	
	out.size = out.size + L;
	
	return out;
			
}


A2PS Divi(A2PS a ,A2PS b) {
	
	A2PS out;
	
	if(b.D[0] == 0) {
		trouble = true;
		cout<<"\a\a";
		MessageBox(NULL, TEXT( "It doesn't have Meaning..." ), TEXT( "WHAAAATT !!!!!  :(   )" ), MB_OK | MB_ICONEXCLAMATION);
		return out;
	}
	
	A2PS o;
	o.size = 1;
	o.D[0] = 1;
	
	A2PS ten;
	ten.size = 2;
	ten.D[0] = 1;
	
	while ( MaxData ( a , Mul (b , o) ) ) {
		o = Mul(o,ten);
	}
	
	o.size--;
	out.size = 1;
	while(o.size && !IsSame(a , Mul(b , out))) {
		out = Sum(out , o);
		if (!MaxData (a , Mul(b , out)) && !IsSame(a , Mul(b , out) ) ){
			out = Sub(out , o);
			o.size--;
		}
	}
	
	return AnayzeData(out);
}


A2PS Sqr(A2PS in) {
	
	A2PS out;
	
	A2PS ten;
	ten.size = 2;
	ten.D[0] = 1;
	
	A2PS o;
	o.size = 1;
	o.D[0] = 1;
	
	while ( MaxData ( in , Mul (o , o) ) ) {
		o = Mul(o,ten);
	}
	
	o.size--;
	out.size = 1;
	while(o.size && !IsSame(in , Mul(out , out)) ) {
		out = Sum(out , o);
		if ( !MaxData (in , Mul(out , out)) && !IsSame(in , Mul(out , out)) ){
			out = Sub(out , o);
			o.size--;
		}
	}
	
	return AnayzeData(out);
}
/// 1111111111

bool IsSame(A2PS in1 , A2PS in2) {
	
	if(in1.size != in2.size)
		return 0;
	if(in1.sign != in2.sign)
		return 0;
	for ( int i = 0 ; i < in1.size ; i++ )
		if( in1.D[i] != in2.D[i] )
			return 0;
	return 1;
	
}

void shaking()
{
			SetWindowPos(consoleWindow, 0, WX, WY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);  //Graphic

int timem=0;

			while (timem <= 4)
			{


  trouble=0;
for (size_t i = WX; i < WX+10; i++)
			{
				SetWindowPos(consoleWindow, 0, i, i, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

				Sleep(8);
			
				 	system("color fa");
				
			}

			for (size_t i = WX+10; i >WX; i--)
			{
				SetWindowPos(consoleWindow, 0, i, i, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	system("color f1");
				Sleep(8);
			}
			
			
			timem++;
			}
			
}
void Location(int x, int y)  {
	
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPosition;
 
	CursorPosition.X = x; // Locates column
	CursorPosition.Y = y; // Locates Row
	SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}


void ArashASCIGART() {
	
	system("cls");
  	system("color f5");
  	system("MODE CON COLS=113 LINES=23");
  	
	int X = 25;
	
	cout<<char(201);
	

		cout<<char(205);
			cout<<char(205);
				cout<<char(205);
					cout<<char(205);
						cout<<char(205);
							cout<<"Pardis Sodeifi";
							
			for ( int i = 0 ; i < 5 + X; i++ )
		cout<<char(205);
		
		
	cout<<"Arashsoft EAI";
	for ( int i = 0 ; i < X; i++ )
		cout<<char(205);
	
	cout<<"Shaghayegh Vesali";
	cout<<char(205);
	cout<<char(205);
	cout<<char(205);
	cout<<char(205);
	cout<<char(205);
	cout<<char(205);
	cout<<char(187);
	for ( int i = 0 ; i < 20 ; i++ ) {
		Location(0,i+1);
		cout<<char(186);
		Location(111,i+1);
		cout<<char(186);
	}
	
	Location(0,21);
	cout<<char(200);
	for ( int i = 0 ; i < 60 + 2*X; i++ )
		cout<<char(205);
	cout<<char(188)<<endl;
}
 


