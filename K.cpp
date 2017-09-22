#include "stdafx.h"
#include "Euler.h"
#include "EulerDlg.h"
#include "K.h"
#include "Na.h"
#include "Nerve.h"
#include "Synapse.h"
#include "NMDA.h"

CK::CK(double gk,double n)
{
	g_K = gk;
	m_Kn=n;
}
double CK::Compute_n(double tempV, CNerve A)
{
		   double an = 0.01*(tempV + 55) / (1 - exp(-0.1*(tempV + 55)));
		   double bn = 0.125*exp(-(tempV + 65) *1.0 / 80);
		   m_Kn = A.Iterative(m_Kn, an, bn,A.GetTimehh());
		   return m_Kn;
}
double CK::Compute_KI(double tempV, CNerve A)
{
	double tmp_n = Compute_n(tempV,A);
	double K_I = 36 * pow(tmp_n, 4)*(tempV-A.GetStart() + 12);
	return K_I;
}
CK::~CK()
{
}
