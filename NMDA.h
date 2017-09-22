#pragma once
#include "Euler.h"
#include "EulerDlg.h"
#include "K.h"
#include "Na.h"
#include "Nerve.h"
#include "Synapse.h"
#include "NMDA.h"
class CNMDA
{
protected:
	double g_NMDA;
	double m_a;
	double m_b;
	double m_c;
	double m_Ta;
	double m_Tb;
	double m_V;
	double m_A;
public:
	CNMDA(double NMDA, double a, double b, double c, double Ta, double Tb, double v,double A);
	double CNMDA_I(double tempV, double Time);
	~CNMDA();
};

