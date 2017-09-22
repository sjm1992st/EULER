#include "stdafx.h"
#include "Euler.h"
#include "EulerDlg.h"
#include "K.h"
#include "Na.h"
#include "Nerve.h"
#include "Synapse.h"
#include "NMDA.h"

CNMDA::CNMDA(double NMDA,double a,double b,double c,double Ta,double Tb,double v,double A)
{
	g_NMDA=NMDA;
	m_a=a;
	m_b=b;
	m_c=c;
	m_Ta=Ta;
	m_Tb=Tb;
	m_V = v;
	m_A = A;
}

double CNMDA::CNMDA_I(double tempV, double Time)
{
	/////////////
	//double TIME = 0;
	//TIME = TIME + Time;
	///////////////
	double temp = m_A*(tempV - m_V)*g_NMDA;
	if (m_Ta == 0 || m_Tb == 0)
		return 0;

	else 
	{    
		double tempA = (exp(-Time*1.0 / m_Ta) - exp(-Time*1.0 / m_Tb));
		double tempB = (m_Ta - m_Tb)*(1 + m_a*exp(m_b*tempV + m_c));
		return temp*tempA*1.0 / tempB;
		
	}
}
CNMDA::~CNMDA()
{
}
