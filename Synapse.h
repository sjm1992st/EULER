#pragma once
#include "Euler.h"
#include "EulerDlg.h"
#include "K.h"
#include "Na.h"
#include "Nerve.h"
#include "Synapse.h"
#include "NMDA.h"
class CSynapse
{
protected:
	double g_syn;
	double m_threshold;
public:
	double CSynapse::Getthreshold();
	double CSynapse::Getsyn();
	CSynapse(double syn, double Threshold);
	double Synapse_I(double tempV,double Time, double time_s);
	~CSynapse();
};

