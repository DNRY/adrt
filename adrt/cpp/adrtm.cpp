#include <stdio.h>
#include <stdlib.h>
#include "adrtm.hpp"

DLLEXPORT void density(int n, double* da)
{

}

DLLEXPORT void drt(double* a, double* da, int n)
{
	int nn = 2*n;
	int nnn = 3*n;
	double* dat = (double*) malloc(nnn * n * sizeof(double));

    for (int i = 0; i < nnn; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		if ( (i >= n) & (i+1 <= nn))
    		{
    			dat[i * n + j] = a[(i-n) * n + j];
    		}
    		else
    		{
    			dat[i * n + j] = 0.0;

    		}
    		da[i * n + j] = 0.0;
    	}
    }

    int m = 2;
    int mh = 1;
    while (m <= n)
    {
    	for (int s = 0; s < mh; ++s)
    		for (int i = 0; i < n; i+=m)
    			for (int h = 0; h < nnn; ++h)
    			{
    				if ( h + 1 <= nnn - s)
    					da[h*n + (i+2*s)] = dat[h*n + (i+s)] + dat[(h+s)*n + (i+mh+s)];
    				if ( h + 1 <= nnn - s - 1 )
    					da[h*n + (i+1+2*s)] = dat[h*n + (i+s)] + dat[(h+s+1)*n + (i+mh+s)];
    			}
    	for (int i = 0; i < nnn; ++i)
    		for (int j = 0; j < n; ++j)
    			dat[i*n + j] = da[i*n + j];
    	m = 2 * m;
    	mh = 2 * mh;
    }

    free(dat);
}

DLLEXPORT void pdrt(double* a, int a_sz1, int a_sz2, int pl, double* da)
{
    int n = a_sz1;
    int nn = 2*n;
    int nnn = 3*n;

    int pn = pl*a_sz2;
    int pnn = 2*pl*n;
    int pnnn = 3*pl*n;

    int da_rows = 3 * pl * a_sz1;
    int da_cols = pl * a_sz2;

    double* dat = (double*) malloc(pnnn * pn * sizeof(double));

    for (int i = 0; i < pnnn; ++i)
    {
        for (int j = 0; j < pn; ++j)
        {
            if ((i+1 >= pn+1) & (i+1 <= pnn))
            {
                dat[i*pnnn + j] = a[(i+1 - pn - 1)/pl] * a_sz2 + (j+1-1)/pl;
            }
            else
            {
                dat[i*pnnn + j] = 0.0;
            }
        }
    }

    int m = 2;
    int mh = 1;

    while (m <= pn)
    {
        for (int s = 0; s < mh; ++s)
            for (int i = 0; i < n; i+=m)
                for (int h = 0; h < nnn; ++h)
                {
                    if (h+1 <= pnnn-s)
                        da[h * da_cols + i+1+2*s-1] = dat[h * da_cols + i+s] + dat[(h+s) * da_cols + i+mh+s];
                    if (h+1 <= pnnn-s-1)
                        da[h * da_cols + i+2*s+1] = dat[h * da_cols + i+s] + dat[(h+s+1) * da_cols + i+mh+s];
                }

        for (int i = 0; i < da_rows; ++i)
            for (int j = 0; j < da_cols; ++j)
                dat[i*da_cols + j] = da[i*da_cols + j];

        m = 2*m;
        mh = 2*mh;
    }

    free(dat);
}

DLLEXPORT void pdrtq(double*a, int p, int q, double* da)
{

}

DLLEXPORT void bdrtq(double* da, int q, double* ba)
{

}

DLLEXPORT void bdrt(double* da, double* ba, int n)
{
    int nn = 2 * n;
    int nnn = 3 * n;

    double* bat = (double*) malloc(nnn * n * sizeof(double));
    double* batwork = (double*) malloc(nnn * n * sizeof(double));

    for (int i = 0; i < nnn; ++i)
        for (int j = 0; j < n; ++j)
        {
            batwork[i*n + j] = 0.0;
            bat[i*n + j] = da[i*n + j];
        }

    int m = n;
    int mh = 0;
    while (m >= 2)
    {
        mh = m/2;
        for (int h = 0; h < nnn; ++h)
        {
            for (int s = 0; s < mh; ++s)
            {
                for (int i = 0; i < n; i+=m)
                {
                    batwork[ h * n + i+s] = bat[h*n + i+2*s] + bat[h*n + i+2*s+1];
                    if ((h >=1) & (h+1+s <= nnn))
                    {
                        batwork[(h+s)*n + i+s+mh] = bat[h*n + i+2*s] + bat[(h-1)*n + i+2*s+1];
                    }
                    else if (h == 0)
                    {
                        batwork[(h+s)*n + i+s+mh] = bat[h * n + i+2*s];
                    }
                }
            }
        }
        for (int i = 0; i < nnn; ++i)
            for (int j = 0; j < n; ++j)
                bat[i*n+j] = batwork[i*n+j];

        m = m / 2;
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ba[ i * n + j] = bat[(i+n) * n + j];

    free(bat);
    free(batwork);
}

DLLEXPORT void drtaq(double* a, double* daa, double* dab, double* dac, double* dad)
{

}

DLLEXPORT void bdrtaq(double* daa, double* dab, double* dac, double* dad, double* ba)
{

}

DLLEXPORT void pdrtaq(int a, int pl, double* daa, double* dab, double* dac, double* dad)
{

}

DLLEXPORT void pdrtqaq(int a, int p, int q, double* daa, double* dab, double* dac, double* dad)
{

}

DLLEXPORT void rbdrtaq(double* daa, double* dab, double* dac, double* dad, int pl, double* rba)
{

}

DLLEXPORT void rbdrtqaq(double* daa, double* dab, double* dac, double* dad, int pl, int ql, double* rba)
{

}

DLLEXPORT void pmatmul(double* x, int pl, double* ax)
{

}

DLLEXPORT void pmatmulq(double* x, int pl, int ql, double* ax)
{

}