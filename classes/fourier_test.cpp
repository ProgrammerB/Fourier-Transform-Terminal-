#include "fourier_algorithm.h"
#include "brute-force.h"
#include "cooley-tukey.h"
#include <random>
#include <cstdbool>
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
std::vector<double> sample_vector_time;
int i;
for(i = 1; i < 1024; i++){
  sample_vector.at(i - min) = i;
}
//..
//amplitude/temperature vector generation
std::vector<double> sample_vector_value;
srand (time(NULL));
double rand_num = (double)rand() % 500 + 1;
int index;
for(index = 1; index < 1024; index++){
  sample_vector_value.at(i - min) = i;
  rand_num = (double)rand() % 500 + 1;
}

std::vector<complex<double>> cooley;
std::vector<complex<double>> brute;

DFT(sample_vector_time, sample_vector_value, brute);
FFT(sample_vector_time, sample_vector_value, cooley);


//Compares the vectors side by side (real and imag)
for(int i = 0; i < index->size(), i++)
{
  if(compare_complex(cooley,brute)){
    num_true++;
  }
}
if(num_true/1024 == 1)
{
  cout<<"Cooley-Tukey & Brute-Force give same result"<<endl;
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
