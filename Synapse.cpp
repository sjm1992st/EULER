#include "stdafx.h"
#include "Euler.h"
#include "EulerDlg.h"
#include "K.h"
#include "Na.h"
#include "Nerve.h"
#include "Synapse.h"
#include "NMDA.h"
double CSynapse::Getsyn()
{
	double syn=g_syn;
	return g_syn;
}
double CSynapse::Getthreshold()
{
	double threshold=m_threshold;
	return threshold;
}

CSynapse::CSynapse(double syn, double Threshold)
{
	g_syn = syn;
	m_threshold = Threshold;
}
double CSynapse::Synapse_I(double tempV,double Time, double time_s)
{
	//double TIME = 0;
	//TIME = TIME + Time;
	double T_syn = Time - time_s;
	if (time_s == 0 || T_syn <= 0)
		T_syn = 0;
	double G_syn = g_syn*(T_syn*g_syn)*exp(-T_syn*g_syn);
	return G_syn*(tempV - m_threshold);
}
CSynapse::~CSynapse()
{
}
