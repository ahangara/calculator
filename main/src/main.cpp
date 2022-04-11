#include <iostream>
#include <stdlib.h>

#include "addition.h"
#include "division.h"
#include "print_result.h"


int main(int argc, char *argv[]){
	
#ifndef NDEBUG  
  std::wcout << "\n --== This is a debug build! ==-- \n";
#endif

  if(argc == 1){
      std::cout << "\n - Provide 2 numbers separated by space.\n";
	  return 1;
  }

  if(argc > 3){
      std::cout << "\n - Error, captured " << argc << " parameters, exiting...\n";
	  return 1;
  }
  
  float f_number, s_number, res_add, res_div;

  f_number = atof(argv[1]);
  s_number = atof(argv[2]);

  std::cout << "\n = Here is the result on " << f_number << " and " <<  s_number << ":\n";

  res_add = addition(f_number, s_number);
  res_div = division(f_number, s_number);
  
  print_result(" - Addition", res_add);
  print_result(" - Division", res_div);

  return 0;
}
