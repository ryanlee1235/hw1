#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  
  ULListStr dat;
  dat.push_front("sup");
  dat.push_back("er");


  /*
  dat.push_back("cal");
  dat.push_back("i");
  dat.push_back("frag");
  dat.push_back("il");
  dat.push_back("ist");
  dat.push_back("ic");
  dat.push_back("exp");
  dat.push_back("i");
  dat.push_back("alo");
  dat.push_back("doc");
  dat.push_back("ious");
  //"sup", "er", "cal", "i", "frag", "il", "ist", "ic", "exp", "i", "alo", "doc", "ious"
  //dat.pop_back();
  //dat.pop_front();
  */
  for(int i = 0; i < (int)dat.size(); i++)
  {
    std::cout << dat.get(i) << " ";
  }
  //std::cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << std::endl;
  // prints: 8 7 9
  std::cout << std::endl;
  std::cout << dat.back() << std::endl;
  std::cout << dat.size() << std::endl;  // prints 3 since there are 3 strings stored
  /*
  ULListStr list;

	list.push_back("a");

	std::cout << list.get(0) << std::endl;

	list.pop_front();

	std::cout << list.size() << std::endl;
  */
}
