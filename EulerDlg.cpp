
// EulerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Euler.h"
#include "EulerDlg.h"
#include "afxdialogex.h"
#include "string"
#include "math.h"
#include "Nerve.h"
#include "K.h"
#include "Na.h"
#include "Synapse.h"
#include "NMDA.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CEulerDlg 对话框



CEulerDlg::CEulerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEulerDlg::IDD, pParent)
//	, m_RCError(0)
	//, m_Current(0)
	//, m_Time(0)
	, m_Currenthh(0)
	//, m_HHerror(0)
	, m_Timehh(0)
	, m_syntime_EA(0)
	, m_syntime_EB(0)
	, m_syntime_I(0)
	//, m_CurrentTwo(0)
	, m_TimeTwo(0)
	, m_CurrentA(0)
//	, m_CurrentB(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEulerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_RCError, m_RCError);
	//DDX_Text(pDX, IDC_EDIT_Inputcurrent, m_Current);
	//DDX_Text(pDX, IDC_EDIT_Timestep, m_Time);
	//DDX_Control(pDX, IDC_EDIT_Solution, m_solution);
	DDX_Control(pDX, IDC_EDIT_SolutionHH, m_solutionhh);
	DDX_Text(pDX, IDC_EDIT_Currenthh, m_Currenthh);
	//  DDX_Text(pDX, IDC_EDIT_HHError, m_HHerror);
	DDX_Text(pDX, IDC_EDIT_TimestepHH, m_Timehh);
	//DDX_Text(pDX, IDC_EDIT_SYNTIME, m_synTime);
	DDX_Text(pDX, IDC_EDIT_SYNTIME_EA, m_syntime_EA);
	DDX_Text(pDX, IDC_EDIT_SYNTIME_EB, m_syntime_EB);
	DDX_Text(pDX, IDC_EDIT_SYNTIME_I, m_syntime_I);
	//	DDX_Control(pDX, IDC_EDIT_SolutionTwo, m_solutionTwo);
	//DDX_Text(pDX, IDC_EDIT_CurrentTwo, m_CurrentTwo);
	DDX_Text(pDX, IDC_EDIT_TimeStepTwo, m_TimeTwo);
	DDX_Text(pDX, IDC_EDIT_CurrentA, m_CurrentA);
	//  DDX_Text(pDX, IDC_EDIT_CurrentB, m_CurrentB);
}

BEGIN_MESSAGE_MAP(CEulerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_EN_CHANGE(IDC_EDIT_Solution, &CEulerDlg::OnEnChangeEditSolution)
	//ON_BN_CLICKED(IDC_BUTTON_Calculation, &CEulerDlg::OnBnClickedButtonCalculation)
//	ON_EN_CHANGE(IDC_EDIT_RCError, &CEulerDlg::OnEnChangeEditRcerror)
	ON_EN_CHANGE(IDC_EDIT_SolutionHH, &CEulerDlg::OnEnChangeEditSolutionhh)
	ON_BN_CLICKED(IDC_BUTTON_CalculationHH, &CEulerDlg::OnBnClickedButtonCalculationhh)
	ON_STN_CLICKED(IDC_STATIC_Picture, &CEulerDlg::OnStnClickedStaticPicture)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CEulerDlg::OnBnClickedButtonClear)
//	ON_BN_CLICKED(IDC_BUTTON_CalculationTwoNeuron, &CEulerDlg::OnBnClickedButtonCalculationtwoneuron)
//    ON_BN_CLICKED(IDC_BUTTON_CalculationTwoNeuronA, &CEulerDlg::OnBnClickedButtonCalculationtwoneurona)
    ON_BN_CLICKED(IDC_BUTTON_CalculationTwoNeuronB, &CEulerDlg::OnBnClickedButtonCalculationtwoneuronb)
END_MESSAGE_MAP()


// CEulerDlg 消息处理程序

BOOL CEulerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	CString   str_Current = "15";
	CString   str_Time = "0.01";
	//GetDlgItem(IDC_EDIT_Inputcurrent)->SetWindowText(str_Current);
	GetDlgItem(IDC_EDIT_Currenthh)->SetWindowText(str_Current);
	GetDlgItem(IDC_EDIT_TimeStepTwo)->SetWindowText(str_Time);
	GetDlgItem(IDC_EDIT_TimestepHH)->SetWindowText(str_Time);
//	GetDlgItem(IDC_EDIT_TimeTwo)->SetWindowText(str_Time);
	GetDlgItem(IDC_EDIT_CurrentA)->SetWindowText(str_Current);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CEulerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CEulerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
///////////////////

///////////////////
void CEulerDlg::DrawPicture(CStringArray *pArray, double num, double Scale,int k)
{
	CPaintDC dc(this);
	RECT rect;
	CDC *pDc = GetDlgItem(IDC_STATIC_Picture)->GetDC();
	GetDlgItem(IDC_STATIC_Picture)->GetClientRect(&rect);
	int w = rect.right-rect.left;
	int h = rect.bottom-rect.top;
	pDc->MoveTo(30, h - 30);
	pDc->LineTo(w - 30, h - 30);
	pDc->MoveTo(30, h - 30);
	pDc->LineTo(30, 30);
	pDc->MoveTo(w - 35, h - 25);
	pDc->LineTo(w - 30, h - 30);
	pDc->LineTo(w - 35, h - 35);
	pDc->MoveTo(25, 35);
	pDc->LineTo(30, 30);
	pDc->LineTo(35, 35);
	//////x轴刻度
		CString strX;
		strX.Format("%g",num);
		pDc->TextOut(w-40, h - 24, strX);
		//////////y轴刻度
		double divid = (Scale + 80) / 10;
		for (int j = 0; j <= divid; j++)
		{
			CString strY;
			strY.Format("%d",-80+j*10);
			pDc->TextOut(5, h - 30-j * (h - 60) / divid, strY);
		}
		//////////////////
	CBrush *oldbrush;
	CBrush brush;
	if (k==1)
	brush.CreateSolidBrush(RGB(255, 0, 0));
	if (k==2)
	brush.CreateSolidBrush(RGB(255, 255, 0));
	oldbrush = pDc->SelectObject(&brush);
	for (int j = 0; j <=num; j++)////描点
	{
		CString Str_d = pArray->GetAt(j);
		double tempV = atof(Str_d.GetBuffer(0));
		double x = 30 +j*(w-60)/num;
		double y = (h - 30) - (tempV + 80)*(h - 60) / (Scale + 80);
		pDc->Ellipse(x - 2, y - 2, x + 2, y + 2);
	}
	pDc->SelectObject(oldbrush);
	ReleaseDC(pDc);
}
//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CEulerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



double CEulerDlg::RCIterative(double temp, double start,double Time,double Current)
{
	double y_pre = temp + Time*(Current + 0.3*(start - temp)) / 1;
	double y_next = temp + Time*(Current + 0.3*(start - y_pre)) / 1;
	double tmp_avgn = (y_pre + y_next)*1.0 / 2;
	return tmp_avgn;
}


////////////RC
/////////


void CEulerDlg::OnEnChangeEditSolutionhh()
{
	UpdateData(false);
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

/////////////////////HH
///////////////////

CStringArray *CEulerDlg::Calculationhh(CNerve A, CSynapse Syn_a, CSynapse Syn_b, CSynapse Syn_c, CNMDA Nmda_a)
{

	double start = A.GetStart();
	CStringArray *pArrayhh = new CStringArray;
	pArrayhh->SetSize(0, 1);
	CString StrStart;
	StrStart.Format(_T("%f"), start);
	pArrayhh->Add(StrStart);
	int i = 0;
	double Time;
	CK K_a(36, 0.318);
	CNa Na_a(120, 0.053, 0.596);
	//CSynapse Syn_a(0.18, 0);
	//CSynapse Syn_b(0.18, 0);
	//CSynapse Syn_c(0.5, -100);
	//CNMDA    Nmda_a(0.5,0.3,-0.062,0,13,0.5,0,6.1);
	/////////////
	///////////////
	for (int k = 1; k <= 4000; k++)
	{
		CString Stemp, Str_d;
		Str_d = pArrayhh->GetAt(i);
		double tempV = atof(Str_d.GetBuffer(0));

		Time = i*A.GetTimehh();

		double K_I = K_a.Compute_KI(tempV, A);

		double Na_I = Na_a.Compute_NaI(tempV, A);

		double Synapse_aI = Syn_a.Synapse_I(tempV, Time,A.GetSyntime_EA());
		
		double Synapse_bI = Syn_b.Synapse_I(tempV, Time,A.GetSyntime_EB());
		
		double Synapse_cI = Syn_c.Synapse_I(tempV, Time, A.GetSyntime_I());

		double CNMDA_aI=Nmda_a.CNMDA_I(tempV,Time);

		/////////////////////////
		//////////////////////////
		///////////////////////////电流项


		double y_pre = tempV + A.GetTimehh()*(0.3*(start - tempV) + A.GetCurrenthh() - K_I - Na_I -  Synapse_aI - Synapse_bI - Synapse_cI-CNMDA_aI);
		////更新电流项
		K_I = K_a.Compute_KI(y_pre, A);  Na_I = Na_a.Compute_NaI(y_pre, A);
		///////////////////
		//////////////
		///////////////
		Synapse_aI = Syn_a.Synapse_I(y_pre, Time,A.GetSyntime_EA());  Synapse_bI = Syn_b.Synapse_I(y_pre, Time,A.GetSyntime_EB());
		Synapse_cI = Syn_c.Synapse_I(y_pre, Time,A.GetSyntime_I()); CNMDA_aI = Nmda_a.CNMDA_I(y_pre, Time);
		//////////////////////////
		//////////////////////
		double y_next = tempV + A.GetTimehh()*(0.3*(start - y_pre) + A.GetCurrenthh() - K_I - Na_I - Synapse_aI - Synapse_bI - Synapse_cI-CNMDA_aI);
		///////////////////////////
		double temp;
		temp = (y_pre + y_next)*1.0 / 2;
		Stemp.Format(_T("%f"), temp);
		pArrayhh->Add(Stemp);
		i++;

	}
	return pArrayhh;
}
//
///////////////////////////突触后细胞电位计算
CStringArray *CEulerDlg::CalculationTwo(CNerve A, CSynapse Syn_a, CSynapse Syn_b, CSynapse Syn_c, CNMDA Nmda_a, CStringArray *pArrayTwoB)
{
	
	double start = A.GetStart();
	CStringArray *pArrayhh = new CStringArray;
	pArrayhh->SetSize(0, 1);
	CString StrStart;
	StrStart.Format(_T("%f"),start);
	pArrayhh->Add(StrStart);
	int i = 0;
	double Time;
	CK K_a(36, 0.318);
	CNa Na_a(120, 0.053, 0.596);
	double flag_a, flag_b, I_add, tag, tmp, j, In_syn,start_tmp;
	tag = 0; tmp = 0; j = 0; flag_a = 0; flag_b = 0; In_syn = 0; start_tmp = 0;
	int count = 0;
	///////////////
	for (int k = 1; k <= 4000; k++)
	{
		CString Stemp, Str_d,StempB,Str_dB;
		Str_d = pArrayhh->GetAt(i);
		double tempV = atof(Str_d.GetBuffer(0));
		Str_dB = pArrayTwoB->GetAt(i);
		double tempV_B = atof(Str_dB.GetBuffer(0));
		Time =i*A.GetTimehh();
		
		double K_I = K_a.Compute_KI(tempV,A);
		
		double Na_I = Na_a.Compute_NaI(tempV, A);
		//////////////
		//////////////激发态
		if (tempV_B < -40)
			flag_a = 1;
		if (tempV_B >= -40)
			flag_b = 1;
		if (flag_a == 1 && flag_b == 1)
		{
			flag_a = 0;
			flag_b = 0;
			count++;
			tag = 1;
		}
		if (count == 1 && tag == 1)
			start_tmp = Time;  
		if (count == 3 && tag == 1)
			tmp = Time - start_tmp;
		if (count % 2 == 1 && tag == 1)
		{
			j = (count + 1) / 2;
			tag = 0;
			In_syn=0.001+Time-start_tmp;
		}
		/////////////////////////
		//////////////////////////
		///////////使In_syn不为0
		I_add = 0;
		for (int m = 0; m < j; m++)////////////电位叠加
		{
			double t=0.001+Time - start_tmp - tmp*m;
			double tmp_I = Syn_a.Synapse_I(tempV,t, In_syn) + Syn_b.Synapse_I(tempV, t, In_syn)
				+ Syn_c.Synapse_I(tempV,t, In_syn) + Nmda_a.CNMDA_I(tempV, t);
			I_add = I_add+tmp_I;
		}
		////////////////////
		//////////////////////////
		///////////////////////////电流项
		double y_pre = tempV + A.GetTimehh()*(0.3*(start - tempV) + A.GetCurrenthh() - K_I -Na_I -I_add);
		////更新电流项
		K_I = K_a.Compute_KI(y_pre,A);  Na_I = Na_a.Compute_NaI(y_pre,A);
		I_add = 0;
		for (int m = 0; m < j; m++)
		{
			double t = 0.001+Time - start_tmp - tmp*m;
			double tmp_I= Syn_a.Synapse_I(y_pre,t, In_syn) + Syn_b.Synapse_I(y_pre,t, In_syn)
				+ Syn_c.Synapse_I(y_pre,t, In_syn) + Nmda_a.CNMDA_I(y_pre,t);
			I_add = I_add+tmp_I;
		}
		/////////////
		//////////////////////
		double y_next = tempV + A.GetTimehh()*(0.3*(start - y_pre) + A.GetCurrenthh()- K_I - Na_I -I_add);
		///////////////////////////
		double temp;
		temp = (y_pre + y_next)*1.0 / 2;
		Stemp.Format(_T("%f"), temp);
		pArrayhh->Add(Stemp);
		i++;

	}
	return pArrayhh;
}
void CEulerDlg::OnBnClickedButtonCalculationhh()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	CNerve A(-69, m_syntime_EA, m_syntime_EB, m_syntime_I, m_Currenthh, m_Timehh);
	CSynapse Syn_a(0.18, 0);
	CSynapse Syn_b(0.18, 0);
	CSynapse Syn_c(0.5, -100);
	CNMDA  Nmda_a(0,0,0,0,0,0,0,0);
	CStringArray *pArrayHH = Calculationhh(A,Syn_a,Syn_b,Syn_c,Nmda_a);
	DrawPicture(pArrayHH, 4000, 40,1);
	CString str, strtmp;
	CString strA = "数值解";
	str = strA + "\r\n";
	for (int j = 0; j <= 4000; j++)
	{
		strtmp = pArrayHH->GetAt(j);
		str += strtmp ;
		str += "\r\n";
		////
	}
	m_solutionhh.SetWindowText(str);
	delete pArrayHH;
}


void CEulerDlg::OnStnClickedStaticPicture()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CEulerDlg::OnBnClickedButtonClear()
{
	Invalidate();// TODO:  在此添加控件通知处理程序代码
}




void CEulerDlg::OnBnClickedButtonCalculationtwoneuronb()
{
	UpdateData(true);

	////////////////突触前细胞B刺激电流m_CurrentA
	CNerve B(-69, 0, 0, 0, m_CurrentA, m_TimeTwo);
	CSynapse Syn_Ba(0, 0);
	CSynapse Syn_Bb(0, 0);
	CSynapse Syn_Bc(0, 0);
	CNMDA    Nmda_b(0, 0, 0, 0, 0, 0, 0, 0);
	CStringArray *pArrayTwoB = Calculationhh(B, Syn_Ba, Syn_Bb, Syn_Bc, Nmda_b);
	//////////////突触后细胞C无刺激电流//有一兴奋突触Syn_Ca
	CNerve C(-69,0.01, 0, 0,0,m_TimeTwo);
	CSynapse Syn_Ca(0.18, 0);
	CSynapse Syn_Cb(0, 0);
	CSynapse Syn_Cc(0, 0);
	CNMDA    Nmda_c(0.5, 0.3, -0.062, 0, 13,0.5,0,33);
	CStringArray *pArrayTwoC = CalculationTwo(C, Syn_Ca, Syn_Cb, Syn_Cc, Nmda_c,pArrayTwoB);
	/////////////////////////////////
	//////////////////////////
	DrawPicture(pArrayTwoC, 4000, 40,1);
	////////////////////
	DrawPicture(pArrayTwoB, 4000, 40,2);
	delete pArrayTwoB;
	////////////////
	delete pArrayTwoC;
}

