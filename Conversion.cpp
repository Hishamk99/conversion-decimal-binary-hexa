#include <iostream>
using namespace std;

char result[15];
int BinaryToDicimal(int input)
{
	int res = 0 , x = 1;
	while(input)
	{
		int last = input % 10;
		res += last*x;
		input /= 10;
		x *= 2;
	}
	return res;
}
char* DicimalToBinary(int n)
{
	int index = 0;
	char tmp[15];
	while(n)
	{
		int mod = n % 2;
		tmp[index] = mod + '0';
		n /= 2;
		index++;
	}
	tmp[index] = '\0';
	for(int i = strlen(tmp)-1 , j = 0; i>=0; i--,j++)
	{
		result[j] = tmp[i];
	}
	result[index] = '\0';
	return result;
}
char* DicimalToHexa(int n)
{
	int index = 0;
	char tmp[15];
	while(n)
	{
		int mod = n % 16;
		if(mod < 10)
		{
			mod += '0';
		}
		else
		{
			mod -= 10;
			mod += 'A';
		}
		n /= 16;
		tmp[index] = mod;
		index++;
	}
	tmp[index] = '\0';
	for(int i = strlen(tmp)-1 , j = 0; i>=0; i--,j++)
	{
		result[j] = tmp[i];
	}
	result[index] = '\0';
	return result;
}
int HexaToDicimal(const char* input)
{
	int res = 0 , x = 1;
	for(int i = strlen(input)-1; i >= 0; i--)
	{
		char mod = input[i];
		if(mod <= '9')
		{
			mod -= '0';
		}
		else
		{
			mod -= 'A';
			mod += 10;
		}
		res += mod * x;
		x *= 16;
	}
	return res;
}
char* DicimalToOctal(int n)
{
	int index = 0;
	char tmp[15];
	while(n)
	{
		int mod = n % 8;
		tmp[index] = mod + '0';
		n /= 8;
		index++;
	}
	tmp[index] = '\0';
	for(int i = strlen(tmp)-1 , j = 0; i>=0; i--,j++)
	{
		result[j] = tmp[i];
	}
	result[index] = '\0';
	return result;
}
int OctalToDicimal(int input)
{
	int res = 0 , x = 1;
	while(input)
	{
		int last = input % 10;
		res += last*x;
		input /= 10;
		x *= 8;
	}
	return res;
}
int main()
{
	int input;
	//cout << OctalToDicimal(input) << endl;
	//cout << DicimalToHexa(1010) << endl;
	//cout << DicimalToHexa(OctalToDicimal(input));
	do
	{
		cout << "Enter:(1) to convert from Dicimal to Binary.\n"
		    << "Enter:(2) to convert from Binary to Dicimal.\n"   
		    << "Enter:(3) to convert from Binary to Hexa.\n"
		    << "Enter:(4) to convert from Hexa to Binary.\n"
		    << "Enter:(5) to convert from Hexa to Dicimal.\n"
		    << "Enter:(6) to convert from Decimal to Hexa.\n"
		    << "Enter:(7) to convert from Decimal to Octal.\n"
		    << "Enter:(8) to convert from Octal to Dicimal.\n"
		    << "Enter:(9) to convert from Binary to Octal.\n"
		    << "Enter:(10) to convert from Octal to Binary.\n"
		    << "Enter:(11) to convert from Octal to Hexa.\n"
		    << "Enter:(12) to convert from Hexa to Octal.\n"
		    << "Enter:(13) to Exit.\n";
			    
		cout << "\nEnter the number of process: ";    
		cin >> input; 
		system("cls");   
		switch(input)
		{
			int n;
			char s[15];
			case 1:
				cout << "Enter the Dicimal number: ";
				cin >> n;
				cout << "The equivelant Binary = " << DicimalToBinary(n) << endl;
				break;
			case 2:
				cout << "Enter the Binary number: ";
				cin >> n;
				cout << "The equivelant Dicimal = " << BinaryToDicimal(n) << endl;
				break;
			case 3:	
			    cout << "Enter the Binary number: ";
				cin >> n;
				cout << "The equivelant Hexa = " << DicimalToHexa(BinaryToDicimal(n)) << endl;
				break;
			case 4:
				cout << "Enter the Hexa number: ";
				cin >> s;
				cout << "The equivelant Binary = " << DicimalToBinary(HexaToDicimal(s)) << endl;
			    break;
			case 5:
				cout << "Enter the Hexa number: ";
				cin >> s;
				cout << "The equivelant Dicimal = " << HexaToDicimal(s) << endl;
			    break;
			case 6:    
			    cout << "Enter the Hexa number: ";
				cin >> n;
				cout << "The equivelant Dicimal = " << DicimalToHexa(n) << endl;
			    break;
			case 7:    
			    cout << "Enter the Decimal number: ";
				cin >> n;
				cout << "The equivelant Octal = " << DicimalToOctal(n) << endl;
			    break;	
			case 8:    
			    cout << "Enter the Octal number: ";
				cin >> n;
				cout << "The equivelant Dicimal = " << OctalToDicimal(n) << endl;
			    break;	
			case 9:    
			    cout << "Enter the Binary number: ";
				cin >> n;
				cout << "The equivelant Octal = " << DicimalToOctal(BinaryToDicimal(n)) << endl;
			    break;
			case 10:    
			    cout << "Enter the Octal number: ";
				cin >> n;
				cout << "The equivelant Binary = " << DicimalToBinary(OctalToDicimal(n)) << endl;
			    break;	
			case 11:    
			    cout << "Enter the Octal number: ";
				cin >> n;
				cout << "The equivelant Hexa = " << DicimalToHexa(OctalToDicimal(n)) << endl;
			    break;	
			case 12:    
			    cout << "Enter the Hexa number: ";
				cin >> s;
				cout << "The equivelant Octal = " << DicimalToOctal(HexaToDicimal(s)) << endl;
			    break;																										
			case 13:    
			    cout << "The programm ended\n";
			    break;	
			default:
			    cout << "Please enter the number from 1 to 13\n";  
				  
		}  
		cout << "\n"; 
		cout << "      ==============================================";
		cout << "\n      ==============================================\n\n"; 
	}while(input != 13);
	
		
    return 0;
}

