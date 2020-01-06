#include <iostream>
#include <string>
#include <fstream>
#include "instructions.h"

using namespace std;

void ProcessInstruction(string type, string first, string second, int conditionals)
{
	if(type == "0"){ I0(first, second, conditionals); }
	else if(type == "1"){ i_I1(first, second, conditionals); }
	else if(type == "2"){ i_I2(first, second, conditionals); }
	else if(type == "3"){ i_I3(first, second, conditionals); }
	else if(type == "4"){ i_I4(first, second, conditionals); }
	else if(type == "5"){ i_I5(first, second, conditionals); }
	else if(type == "6"){ i_I6(first, second, conditionals); }
	else if(type == "7"){ i_I7(first, second, conditionals); }
	else if(type == "8"){ i_I8(first, second, conditionals); }
	else if(type == "9"){ i_I9(first, second, conditionals); }
	else if(type == "A"){ i_A(first, second, conditionals); }
	else if(type == "B"){ i_B(first, second, conditionals); }
	else if(type == "C"){ i_C(first, second, conditionals); }
	else if(type == "D0"){ i_D0(first, second, conditionals); }
	else if(type == "D1"){ i_D1(first, second, conditionals); }
	else if(type == "D2"){ i_D2(first, second, conditionals); }
	else if(type == "D3"){ i_D3(first, second, conditionals); }
	else if(type == "D4"){ i_D4(first, second, conditionals); }
	else if(type == "D5"){ i_D5(first, second, conditionals); }
	else if(type == "D6"){ i_D6(first, second, conditionals); }
	else if(type == "D7"){ i_D7(first, second, conditionals); }
	else if(type == "D8"){ i_D8(first, second, conditionals); }
	else if(type == "D9"){ i_D9(first, second, conditionals); }
	else if(type == "DA"){ i_DA(first, second, conditionals); }
	else if(type == "DB"){ i_DB(first, second, conditionals); }
	else if(type == "DC"){ i_DC(first, second, conditionals); }
	else if(type == "E"){ i_E(first, second, conditionals); }
	else if(type == "F"){ i_F(first, second, conditionals); }
}

int main(int argc, char* argv[])
{ 
	if(argc > 1)
	{
		ifstream input(argv[1]);
		string type;
		string first; 
		string second; 
		
		cout << ".section .text" << endl;
		cout << ".global _start" << endl;
		cout << "\n_start:" << endl;
		cout << "mov r1, 0x00000000" << endl; //offset
		cout << "mov r2, 0x00000000" << endl; //basevar
		
		for(string line; getline(input, line);)
		{
			type = line.at(0);
			if(type == "D") // Check for D types 
			{
				type += line.at(1);
			}
			
			string::size_type pos = line.find(' ');
			if(line.npos != pos) {
				first = line.substr(pos + 1);
				second = line.substr(0, pos);
			}
			
			ProcessInstruction(type, first, second, conditionals);
			
		}
	}
}

	