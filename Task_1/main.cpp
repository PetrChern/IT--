#include "Fingerprint.hpp"
#include <string>

int main()
{
    std::string file_name;
    std::cout << "Enter file name for fingerprint (digest): ";
    std::cin >> file_name;
  Fingerprint FP(file_name.c_str());

  FP.show();

  return EXIT_SUCCESS;
}
