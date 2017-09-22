#include "stdafx.h"
#include "Euler.h"
#include "EulerDlg.h"
#include "K.h"
#include "Na.h"
#include "Nerve.h"
#include "Synapse.h"
#include "NMDA.h"
CNerve::CNerve(double start, double syntime_EA, double syntime_EB, double syntime_I,double Currenthh,double Timehh) 
{
	 m_start=start;
	 m_syntime_EA = syntime_EA;
	 m_syntime_EB = syntime_EB;
	 m_syntime_I = syntime_I;
	 m_Timehh = Timehh;
	 m_Currenthh = Currenthh;
}

double  CNerve::GetStart()
{
	double start = m_start;
	return start;
}
double  CNerve::GetSyntime_EA()
{
	double syntime_EA = m_syntime_EA;
	return syntime_EA;
}
double  CNerve::GetSyntime_EB()
{
	double syntime_EB = m_syntime_EB;
	return syntime_EB;
}
double  CNerve::GetSyntime_I()
{
	double syntime_I = m_syntime_I;
	return syntime_I;
}
double  CNerve::GetTimehh()
{
	double 	 Timehh = m_Timehh;;
	return Timehh;
}
double  CNerve::GetCurrenthh()
{
	double 	 Currenthh = m_Currenthh;;
	return Currenthh;
}
double CNerve::Iterative(double tmp_n, double an, double bn,double Timehh)
{
	double y_pre = tmp_n + (an*(1 - tmp_n) - bn*tmp_n)*Timehh;
	double y_next = tmp_n + (an*(1 - y_pre) - bn*y_pre)*Timehh;;
	double tmp_avgn = (y_pre + y_next)*1.0 / 2;
	return tmp_avgn;
}
CNerve::~CNerve()
{
}
