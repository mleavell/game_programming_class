#include <iostream>
#include <math.h>

double randomNumber() {
  return (double)rand()/(double)RAND_MAX;
}

double getRandDistance() {
  double x = randomNumber();
  double y = randomNumber();
  return sqrt(pow(x,2) + pow(y,2));
}

int main(void){
  int numIter = 10000000;
  int numHits = 0;
  for (int i = 0; i < numIter; i++) {
  if (getRandDistance() <= 1) {
  numHits++;
  }
  }
  double pi = 4.0 * ((double)numHits / (double)numIter);
  std::cout << pi;
  std::cout << "\n";
  return 0;
}