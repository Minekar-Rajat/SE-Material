#include <fstream>
#include <iostream>
using namespace std;
int main()
{
  string str;
  //Creates an instance of ofstream, and opens example.txt
  ofstream a_file("one.txt");
  // Outputs to example.txt through a_file
  a_file<<"This text will now be inside of example.txt";
  // Close the file stream explicitly
  a_file.close();
  //Opens for reading the file
  ifstream b_file("one.txt");
   //Reads one string from the file
  b_file>>str;
  //Should output 'this'
  cout<<str<<"\n";
  cin.get();    // wait for a keypress
  // b_file is closed implicitly here
}


