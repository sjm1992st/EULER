#include "stdafx.h"
#include "Euler.h"
#include "EulerDlg.h"
#include "K.h"
#include "Na.h"
#include "Nerve.h"
#include "Synapse.h"
#include "NMDA.h"
CNa::CNa(double gna, double m,double h)
{
	g_Na = gna;
	m_Nam = m;
	m_Nah = h;
}
double CNa::Compute_m(double tempV,CNerve A)
{
	double am = 0.1*(tempV + 40) / (1 - exp(-0.1*(tempV + 40)));
	double bm = 4 * exp(-(tempV + 65) *1.0 / 18);
	m_Nam = A.Iterative(m_Nam, am, bm,A.GetTimehh());
	return m_Nam;
}
double CNa::Compute_h(double tempV,CNerve A)
{
	double ah = 0.07*exp(-(tempV + 65)*1.0 / 20);
	double bh = 1.0 / (exp(-0.1*(tempV + 35)) + 1);
	m_Nah = A.Iterative(m_Nah, ah, bh, A.GetTimehh());
	return m_Nah;
}
double CNa::Compute_NaI(double tempV,CNerve A)
{
	double tmp_m = Compute_m(tempV,A);
	double tmp_h = Compute_h(tempV,A);
	double Na_I = 120 * pow(tmp_m, 3)*tmp_h*(tempV-A.GetStart() - 115);
	return Na_I;
}
CNa::~CNa()
{
}
