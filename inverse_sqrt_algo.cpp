# include <math.h>
# include <iostream> 

# define LOG(x) std::cout << x << std::endl

void FastInverseSQRT(float f)
{
 float* f_ptr = &f;

  u_int32_t f_hex = * (u_int32_t * )f_ptr; // evil bit hack

  u_int32_t res_hex = 0x5f3759df - (f_hex >> 1);  // wtf

  float res_flo =  * (float*) &res_hex; // evil bit hack

  float res_flo_nw = res_flo + 0.5 * (1 - res_flo *res_flo* f) * res_flo; // Newton's method

  // LOG("f"); LOG(f);
  // LOG("*f_ptr"); LOG(*f_ptr);
  // LOG("f_ptr"); LOG(f_ptr);
  // LOG("f_hex"); LOG(f_hex);

  LOG("1/sqrt(f)"); LOG(1/sqrt(f));
  LOG("res_flo"); LOG(res_flo);
  LOG("res_flo_nw"); LOG(res_flo_nw);

}

void FastSQRT(float f)
{
  // SQRT version
  // Key difference in Newton's step, as we get division by y :(
// with constant 0x1fc00000 = 127 * 2**22 (assumed mu=0 in log approximation)
 float* f_ptr = &f;

  u_int32_t f_hex = * (u_int32_t * )f_ptr; // evil bit hack

  u_int32_t res_hex = 0x1fc00000 + (f_hex >> 1);  // wtf 

  float res_flo =  * (float*) &res_hex; // evil bit hack

  float res_flo_nw = res_flo - 0.5 * (res_flo - f/res_flo) ; // Newton's method 

  // LOG("f"); LOG(f);
  // LOG("*f_ptr"); LOG(*f_ptr);
  // LOG("f_ptr"); LOG(f_ptr);
  // LOG("f_hex"); LOG(f_hex);
  LOG("sqrt(f)"); LOG(sqrt(f));
  LOG("res_flo"); LOG(res_flo);
  LOG("res_flo_nw"); LOG(res_flo_nw);
  
}

int main(int argc, char const *argv[])
{
  float f = 3765.56;

  FastInverseSQRT(f);
  FastSQRT(f);
 
  return 0;
}
