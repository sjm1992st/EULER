
// EulerDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "Euler.h"
#include "EulerDlg.h"
#include "K.h"
#include "Na.h"
#include "Nerve.h"
#include "Synapse.h"
#include "NMDA.h"
// CEulerDlg 对话框
class CEulerDlg : public CDialogEx
{
// 构造
public:
	CEulerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_EULER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
//	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//double CEulerDlg::Iterative(double temp_n, double an, double bn);
	//double CEulerDlg::EulerIterative(double tempV, double start, double tmp_n, double tmp_m, double tmp_h, double Time);
	double CEulerDlg::RCIterative(double temp, double start, double Time, double Current);
	//double CEulerDlg::Synapse(double g_syn, double Time, double time_s);
	CStringArray *CEulerDlg::Calculationhh(CNerve A, CSynapse Syn_a, CSynapse Syn_b, CSynapse Syn_c, CNMDA Nmda_a);
	CStringArray *CEulerDlg::CalculationTwo(CNerve A, CSynapse Syn_a, CSynapse Syn_b, CSynapse Syn_c, CNMDA Nmda_a, CStringArray *pArrayTwoB);
	void CEulerDlg::DrawPicture(CStringArray *pArray, double num, double Scale,int k);
	//CSynapse CEulerDlg::CreatClassSyn(CSynapse Syn_a);
	DECLARE_MESSAGE_MAP()
public:
//	double m_Current;
//	double m_Resistance;
//	double m_Time;
	//afx_msg void OnEnChangeEditSolution();
//	double m_Capacitance;
//	double m_RCError;
//	double m_Resistance;
	//double m_Current;
//	double m_Capacitance;
	//double m_Time;
	//CEdit m_solution;
	HICON m_hIcon;
	//afx_msg void OnBnClickedButtonCalculation();
	//afx_msg void OnEnChangeEditRcerror();
//	CEdit m_Count;
	afx_msg void OnEnChangeEditSolutionhh();
	afx_msg void OnBnClickedButtonCalculationhh();
	CEdit m_solutionhh;
	double m_Currenthh;
//	double m_HHerror;
	double m_Timehh;
	afx_msg void OnStnClickedStaticPicture();
	afx_msg void OnBnClickedButtonClear();
//	double m_synTime;
	double m_syntime_EA;
	double m_syntime_EB;
	double m_syntime_I;
	//afx_msg void OnBnClickedButtonCalculationtwoneuron();
	//CEdit m_solutionTwo;
	//double m_CurrentTwo;
	double m_TimeTwo;
	//afx_msg void OnBnClickedButtonCalculationtwoneurona();
	double m_CurrentA;
//	double m_CurrentB;
	afx_msg void OnBnClickedButtonCalculationtwoneuronb();
};
