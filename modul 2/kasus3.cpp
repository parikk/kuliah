#include <iostream>

int main() {
  long int drumA, drumB;
  long int temp;

  std::cout << "Masukkan nilai drum-A: ";
  std::cin >> drumA;
  std::cout << "Masukkan nilai drum-B: ";
  std::cin >> drumB;

  temp = drumA;
  drumA = drumB;
  drumB = temp;

  std::cout << "Nilai drum-A setelah pertukaran: " << drumA << std::endl;
  std::cout << "Nilai drum-B setelah pertukaran: " << drumB << std::endl;

  return 0;
}
