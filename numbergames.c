/*****************************************************************************
 * numbergames.c
 *****************************************************************************/

#include <stdio.h>
#define ETSI_SOURCE
#include <fract2float_conv.h>
#include <fract_typedef.h>
#include <libetsi.h>
#include <stdlib.h>
#include <math.h>

//more accurate pi in the sky, %.20f 
#define HIPI 3.14159265358979323846
#define PISTRING "3.14159265358979323846"
//           3.14285714285714285714
//           3.14159265358979323846
//           3.14159265358979323846
#define SIN0pt1 0.0998334166468 // from http://www.solvemymath.com/online_math_calculator/complex_number_trigonometry/trigonometry_calculator/index.php
/* Place program arguments in the following string, or delete the definition
   if arguments will be passed from the command line. */
#pragma symbolic_ref
const char __argv_string[] = "-abc -xyz";

const long double ldpi = 3.141592653589793; //23846;

int main( int argc, char *argv[] )
{
/*** first probing code, now superseded 
	float fpi = 2.0*acos(0.0);
	printf("fpi = %.12f\n", fpi);
	double dpi = 2.0*acos(0.0);
	printf("dpi = %.12f\n", dpi);
	fract16 r, s;
	r = 0.0r16;
	fract16 fr16pi = acos_fr16(r);
	float ff = fr16_to_float(fr16pi);
//Ha! This gave nonsense (but no error message) until I included all the other .h's up there apart from math.h
	printf("fr16pi as a fraction of pi/2 = %f, which *pi = %.12f\n", ff , HIPI*ff);
	
	printf("fr16pi as float = %.8f\n", fr16_to_float(fr16pi));
	s = 0.1r16;
	dpi = fr16_to_float(asin_fr16(s))*HIPI*0.5;
	printf("fr16 asin of small angle as float = %.12f\n", dpi);
	fpi = asin(0.1);
	printf("regular asin of same angle = %.12f\n", fpi);
	printf("Error %% %.8f \n", 100.0*(1.0 - dpi/(double)fpi)); 
	
	fract32 p32, q32, r32, fr32pi;
	r32 = 0.0r32;
	fr32pi = acos_fr32(r32);
	ff = fr32_to_float(fr32pi);
	printf("fr32pi as a fraction of pi/2 = %f, which *pi = %.12f\n", ff , HIPI*ff);
***/	
	
/*
	Accuracy and precision evaluation of different arithmetic operations on the Blackfin 355
	I've taken pi to 20 decimal places from the internet, 3 sources gave the same number, one differed!
	I calculate pi using a call to various forms of acos.
	I also compare calculations of the sine of a small angle (0.1 rad) by different methods with a (presumably)
	highly accurate calculation from the internet
	
	N.B. float and double are both 32-bit
	
*/	
	
	float f1, f2;
	long double dd=0.0, dd2=0.0;
	//printf("\tUsing float\n");
	f1 = 2.0*acos(0.0);
	dd2 = f1;
	dd = ldpi;//(long double)HIPI;
	f2 = (dd2-ldpi)*(long double)1000000.0/dd;
	printf("Error of 2.0*acos(0.0) in ppm = \n%.12f\n", f2);
	printf("True value of pi = \n%s\n", PISTRING);
	//printf("\tUsing long double\n");
	dd = 0.0;
	//dd2 = 2.0;
	dd2 = 2.0*acosd(dd);
	dd = HIPI;
	//Can't format printf properly to show long double, so
	f2 = (dd2-dd)*(long double)1000000.0/dd;
	printf("Error of 2.0*acosd(0.0) in ppm = \n%.12f\n", f2);
	
	//printf("Using fract32\n");
	
	 
	return 0;
}
