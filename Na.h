#pragma once
#include "Euler.h"
#include "EulerDlg.h"
#include "K.h"
#include "Na.h"
#include "Nerve.h"
#include "Synapse.h"
#include "NMDA.h"
class CNa
{protected:
	double g_Na;
	double m_Nam;
	double m_Nah;
public:
	CNa(double gna, double m, double h);
	double Compute_m(double tempV,CNerve A);
	double Compute_h(double tempV, CNerve A);
	double Compute_NaI(double tempV,CNerve A);
	~CNa();
};

