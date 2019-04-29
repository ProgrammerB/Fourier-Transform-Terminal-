#include "fourier_algorithm.h"
#include "brute-force.h"
#include "cooley-tukey.h"
#include <random>
#include <cstdbool>
#include <iostream>
#define EPSILON .00001
using std::complex;


bool compare_complex (complex<double> A, complex<double> B)
{
   double diff_real = real(A) - real(B);
   double diff_imag = imag(A) - imag(B);
   return (diff_real < EPSILON) && (-diff_real < EPSILON)
            && (diff_imag < EPSILON) && (-diff_imag < EPSILON);
}

//time vector generation
  //maybe make max and min rand inside some large interval
std::vector<double> makeTimeVector(void)
{
  std::vector<double> sample_vector_time;
  int i;
  for(i = 1; i < 1024; i++){
    sample_vector_time.at(i - 1) = i;
  }
  return sample_vector_time;
}

//..
//amplitude/temperature vector generation
std::vector<double> makeValueVector(void)
{
  std::vector<double> sample_vector_value;
  srand (time(NULL));
  double rand_num = static_cast<double>(rand() % 500 + 1);
  int index;
  for(index = 1; index < 1024; index++){
    sample_vector_value.at(index - 1) = rand_num;
    rand_num = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/500));
  }
  return sample_vector_value;
}

void FOURIER_TEST(void){
  //complex vectors which will be used as references
  std::vector<complex<double>> cooley_ref;
  std::vector<complex<double>> brute_ref;

  //created cooley-tukey and brute force objects
  Brute_force<double> brute();
  Cooley_tukey<double> cooley();

  brute.DFT(makeTimeVector, makeValueVector, brute_ref);
  cooley.FFT(makeTimeVector, makeValueVector, cooley_ref);


  //Compares the vectors side by side (real and imag)
  int i;
  for(i = 0; i < 1024, i++)
  {
    if(compare_complex(cooley_ref.at(i),brute_ref.at(i))){
      num_true++;
    }
  }
  if(num_true/1024 == 1)
  {
    cout<<"Cooley-Tukey & Brute-Force give same result"<<endl;
  }
}



//_____________________________________________________________
//**COMMENTED OUT CONSTRUCTION ZONE
//*
//*
/*


**
TODO:://Implement Unit testing with randomly
  generated txt files
**


int num_true = 0;
for(int i = 0; i < index->size(), i++)
{
  BOOST_CHECK_CLOSE(,,.0001);
  num_true++;
}
if(num_true/1024 == 1)
{
  cout<<"Cooley-Tukey & Brute-Force give same result"<<endl;
}
*/

//Somehow compare the cooley-tukey and brute-force answers
  //*This means it is significantly probable that
    //both fourier algorithms are calculating
    //correctly because they are getting the
    //same value through different methods

//control file will be a file with already "transformed" data
  //*control data will be obtained from an already tested fourier analyzer
    //This will compare both and if they are relatively the same
    //then success is assumed.

//below can be syntax for txt file based unit testing
//void TEST_CALL(std::string control_file, std::string test_file)
