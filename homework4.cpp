/* Jason Bell CSCE1030.001 jtb0192 Homework4 jasonbell2@my.unt.edu */

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;

void id(); // declaring the functions to be used later
void encryption();
void decryption();

ifstream in_stream; // global declaration of variables to be used in the functions
ofstream out_stream;
int key, y;
char infile[32], outfile[32], x;



int main()
{
	id(); // call the function to display my name and info

	string action;

	while ((action != "encrypt") && (action != "decrypt")) // prompt for encrypt or decrypt
	{
		cout << "Would you like to encrypt of decrypt a file?\n";
		cin >> action;
	}

	if (action == "encrypt") // call  encryption function if needed
	{
		encryption();
	}

	if (action == "decrypt") // call the decryption function if needed
	{
		decryption();
	}

	return 0;
}


/*
A function to encrypt the file. It reads in a file, adjusts the values based on ASCII
and then outputs it to a different file.
*/

void encryption()
{
		cout << "Enter the name of your input file you want to encrypt: "; // prompt for the file to encypt
		cin >> infile;
		in_stream.open(infile); // open said file
		if (in_stream.fail()) // failure clause
		{
			cout << "Input file opening failed.\n";
			exit(1);
		}

		cout << "\nEnter the name of your output file to write the ciphertext: "; // prompt for ouput file
		cin >> outfile;
		out_stream.open(outfile); // open said file
		if (out_stream.fail()) // failure clause
		{
			cout << "Output file opening failed.\n";
			exit (1);
		}

		cout << "\nEnter the numerical key (i.e. an integer) used to encrypt: "; // prompt for encryption key
		cin >> key;


		while (!in_stream.eof()) // set limit for how long it runs
		{
			in_stream >> x; // read in the characters
			if (((int) x >= 65) && ((int) x < 91)) // reads for capital letters
			{
				y = (((int) x - 65)+ key)% 26; // math to adjust the value based on ASCII
				y += 65;
				out_stream << (char) y; // write out to file
			}


			else  if (((int) x >= 97) && ((int) x < 123)) // reads for lowercase letters
			{
				y = (((int) x - 97) + key) % 26; // math to adjust the value based on ASCII
				y += 97;
				out_stream << (char) y; // write out to file
			}

			else if ((x >= 48) && (x < 58)) // reads in numbers
			{
				y = ((x - 48) + key) % 10; // math to adjust the value based on ASCII
				out_stream << y; // write out ot file
			}

			x = 0; // keeps from repeating the final value
		}
}

/*
A function to decypt an encrypted file. It accepts the file, adjusts the ASCII value to decrypt it,
and then outputs it into a different file.
*/

void decryption()
{
	cout << "Enter the name of your input file you want to decrypt: "; // prompt for file to decrypt
		cin >> infile; 
		in_stream.open(infile); // open said file
		if (in_stream.fail()) // clause for failed file

		{
			cout << "Input file opening failed.\n"; 
			exit(1);
		}

		cout << "\nEnter the name of the output file to write the the plaintext: "; // prompt for file to send to
		cin >> outfile;
		out_stream.open(outfile); // open said file
		if (out_stream.fail()) // clause for failed file
		{
			cout << "Output file opening failed.\n";
			exit (1);
		}

		cout << "\nEnter the numerical key: "; // prompt for key to decrypt with
		cin >> key;

		while (!in_stream.eof()) // sets length of input
		{
			in_stream >> x; // reads in characters
			if (((int) x >= 65) && ((int) x < 91)) // reads in capital letters
			{
				y = (26 + ((int) x - 65) - key) % 26; // math to decrypt them
				y += 65;
				out_stream << (char) y; // writes out to file
			}

			else if (((int) x >= 97) && ((int) x < 123)) // read in lowercase letters
			{
				y = (26 + ((int) x - 97) - key) % 26; // math to decrypt them
				y += 97;
				out_stream << (char) y; // writes out to file
			}

			else if ((x >= 48) && (x < 58)) // reads in numbers
			{
				y = (10 + (x - 48) - key) % 10; // math to decrypt them
				out_stream << y; // writes out to file
			}

			x = 0; // keeps from repeating last value
		}
	}

/*
a program to output my class information
*/

void id()
{
cout << "Jason Bell CSCE1030.001 jtb0192 jasonbell2@my.unt.edu\n"
     << "Homework4\n" << endl;
}

