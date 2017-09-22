#pragma once
#include "Euler.h"
#include "EulerDlg.h"
#include "K.h"
#include "Na.h"
#include "Nerve.h"
#include "Synapse.h"
#include "NMDA.h"
class CK
{
protected:
	double g_K;
	double m_Kn;
public:
CK(double gk,double n);
double Compute_n(double tempV, CNerve A);
double Compute_KI(double tempV, CNerve A);
	~CK();
};

