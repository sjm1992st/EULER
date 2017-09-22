#pragma once
#include "Euler.h"
#include "EulerDlg.h"
#include "K.h"
#include "Na.h"
#include "Nerve.h"
#include "Synapse.h"
#include "NMDA.h"
class CNerve
{
protected:
	double m_start;
	double m_syntime_EA;
	double m_syntime_EB;
	double m_syntime_I;
	//double m_tmp_n;
	//double m_tmp_m;
	//double m_tmp_h;
	double m_Timehh;
	double m_Currenthh;
	double m_starttime;
public:
	/*double Time(double time);*/
	double GetStart();
	double  GetSyntime_EA();
	double  GetSyntime_EB();
	double  GetSyntime_I();
	double  GetTimehh();
	double  GetCurrenthh();
	double  GetStartTime();
	double Iterative(double tmp_n, double an, double bn,double Timehh);
	double Synapse(double g_syn, double Time, double time_s);
	double EulerIterative(double tempV,double start,double K_I,double Na_I,double Synapse_aI,double Synapse_bI,double Synapse_cI,double Time);
	CStringArray *Calculationhh();
public:
	CNerve(double start, double syntime_EA, double syntime_EB, double syntime_I, double Currenthh, double Timehh);
	~CNerve();
};

