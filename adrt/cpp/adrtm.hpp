#pragma once
#include <stdlib.h>
#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

#ifdef __cplusplus
extern "C" {  // only need to export C interface if
			  // used by C++ source code
#endif
	DLLEXPORT void density(int n, double* da);
	DLLEXPORT void drt(double* a, double* da, int n);
	DLLEXPORT void pdrt(double* a, int a_sz1, int a_sz2, int pl, double* da);
	DLLEXPORT void pdrtq(double*a, int p, int q, double* da);
	DLLEXPORT void bdrtq(double* da, int q, double* ba);
	DLLEXPORT void bdrt(double* da, double* ba, int n);
	DLLEXPORT void drtaq(double* a, double* daa, double* dab, double* dac, double* dad);
	DLLEXPORT void bdrtaq(double* daa, double* dab, double* dac, double* dad, double* ba);
	DLLEXPORT void pdrtaq(int a, int pl, double* daa, double* dab, double* dac, double* dad);
	DLLEXPORT void pdrtqaq(int a, int p, int q, double* daa, double* dab, double* dac, double* dad);
	DLLEXPORT void rbdrtaq(double* daa, double* dab, double* dac, double* dad, int pl, double* rba);
	DLLEXPORT void rbdrtqaq(double* daa, double* dab, double* dac, double* dad, int pl, int ql, double* rba);
	DLLEXPORT void pmatmul(double* x, int pl, double* ax);
	DLLEXPORT void pmatmulq(double* x, int pl, int ql, double* ax);
#ifdef __cplusplus
}
#endif