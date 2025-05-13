
// PVZCrackerDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "PVZCracker.h"
#include "PVZCrackerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPVZCrackerDlg 对话框



CPVZCrackerDlg::CPVZCrackerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PVZCRACKER_DIALOG, pParent){
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	check1 = 0;
	check2 = 0;
	sunvalue = 5000;
	money_a = 10000;
	money_b = 10000;
	money_c = 10000;
	TIM_X = 0;
}

void CPVZCrackerDlg::DoDataExchange(CDataExchange* pDX){
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, sunvalue);	//将edit1的内容与sunvalue绑定，以下同理
	DDX_Text(pDX, IDC_EDIT2, money_a);	
	DDX_Text(pDX, IDC_EDIT3, money_b);	
	DDX_Text(pDX, IDC_EDIT4, money_c);	
	DDX_Check(pDX, CHECK1, check1);
	DDX_Check(pDX, CHECK2, check2);

}

BEGIN_MESSAGE_MAP(CPVZCrackerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CPVZCrackerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPVZCrackerDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CPVZCrackerDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CPVZCrackerDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CPVZCrackerDlg::OnBnClickedButton5)

	
	ON_BN_CLICKED(CHECK1, &CPVZCrackerDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(CHECK2, &CPVZCrackerDlg::OnBnClickedCheck2)
	ON_WM_TIMER()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CPVZCrackerDlg 消息处理程序

BOOL CPVZCrackerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	this->SetWindowTextW(L"植物大战僵尸杂交版破解 by 朱季委");
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CPVZCrackerDlg::OnPaint()
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

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CPVZCrackerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPVZCrackerDlg::OnBnClickedButton1(){
	// TODO: 在此添加控件通知处理程序代码
	// 修改阳光
	UpdateData(TRUE);
	HWND PVZ;
	PVZ = ::FindWindow(L"MAINWINDOW", L"植物大战僵尸杂交版v2.0");//这里需要对应游戏窗口名。
	DWORD pid = 0;
	GetWindowThreadProcessId(PVZ, &pid);
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);//打开进程，获取所有权

	SIZE_T ipread = 0;           //下面要用的参数，实际上往往忽略,但不写又不行

	DWORD base = 0x006A9EC0;	 //数据基地址偏移量等由CE给出。
	DWORD offset1 = 0x00000768;
	DWORD offset2 = 0x00005560;

	//[base]->sunbase
	DWORD sunbase = 0;
	ReadProcessMemory(handle, LPCVOID(base), &sunbase, sizeof(DWORD), &ipread);

	//[sunbase+offset1]->sunoffset1
	DWORD sunoffset1 = 0;
	ReadProcessMemory(handle, LPCVOID(sunbase + offset1), &sunoffset1, sizeof(DWORD), &ipread);

	//sunvalue -> [sunoffset1+offset2]
	DWORD svalue = sunvalue;
	WriteProcessMemory(handle, LPVOID(sunoffset1 + offset2), &svalue, sizeof(DWORD), &ipread);
}

void CPVZCrackerDlg::OnBnClickedButton2(){
	// TODO: 在此添加控件通知处理程序代码
	// 修改银币
	UpdateData(TRUE);
	HWND PVZ;
	PVZ = ::FindWindow(L"MAINWINDOW", L"植物大战僵尸杂交版v2.0");
	DWORD pid = 0;
	GetWindowThreadProcessId(PVZ, &pid);
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	SIZE_T ipread = 0;           //下面要用的参数

	DWORD base = 0x006A9EC0;	 //数据基地址偏移量等由CE给出。
	DWORD offset1 = 0x0000082C;
	DWORD offset2 = 0x00000208;

	//[base]->moneybase
	DWORD moneybase = 0;
	ReadProcessMemory(handle, LPCVOID(base), &moneybase, sizeof(DWORD), &ipread);

	//[moneybase+offset1]->moneyoffset1
	DWORD moneyoffset1 = 0;
	ReadProcessMemory(handle, LPCVOID(moneybase + offset1), &moneyoffset1, sizeof(DWORD), &ipread);

	//money_a -> [moneyoffset1+offset2]
	DWORD svalue = money_a;
	WriteProcessMemory(handle, LPVOID(moneyoffset1 + offset2), &svalue, sizeof(DWORD), &ipread);

}

void CPVZCrackerDlg::OnBnClickedButton3(){
	// TODO: 在此添加控件通知处理程序代码
	// 修改金币
	UpdateData(TRUE);
	HWND PVZ;
	PVZ = ::FindWindow(L"MAINWINDOW", L"植物大战僵尸杂交版v2.0");
	DWORD pid = 0;
	GetWindowThreadProcessId(PVZ, &pid);
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	SIZE_T ipread = 0;           //下面要用的参数

	DWORD base = 0x006A9EC0;	 //数据基地址偏移量等由CE给出。
	DWORD offset1 = 0x0000082C;
	DWORD offset2 = 0x0000020C;

	//[base]->moneybase
	DWORD moneybase = 0;
	ReadProcessMemory(handle, LPCVOID(base), &moneybase, sizeof(DWORD), &ipread);

	//[moneybase+offset1]->moneyoffset1
	DWORD moneyoffset1 = 0;
	ReadProcessMemory(handle, LPCVOID(moneybase + offset1), &moneyoffset1, sizeof(DWORD), &ipread);

	//money_b -> [moneyoffset1+offset2]
	DWORD svalue = money_b;
	WriteProcessMemory(handle, LPVOID(moneyoffset1 + offset2), &svalue, sizeof(DWORD), &ipread);
}

void CPVZCrackerDlg::OnBnClickedButton4(){
	// TODO: 在此添加控件通知处理程序代码
	// 修改钻石
	UpdateData(TRUE);
	HWND PVZ;
	PVZ = ::FindWindow(L"MAINWINDOW", L"植物大战僵尸杂交版v2.0");
	DWORD pid = 0;
	GetWindowThreadProcessId(PVZ, &pid);
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	SIZE_T ipread = 0;           //下面要用的参数

	DWORD base = 0x006A9EC0;	 //数据基地址偏移量等由CE给出。
	DWORD offset1 = 0x0000082C;
	DWORD offset2 = 0x00000210;

	//[base]->moneybase
	DWORD moneybase = 0;
	ReadProcessMemory(handle, LPCVOID(base), &moneybase, sizeof(DWORD), &ipread);

	//[moneybase+offset1]->moneyoffset1
	DWORD moneyoffset1 = 0;
	ReadProcessMemory(handle, LPCVOID(moneybase + offset1), &moneyoffset1, sizeof(DWORD), &ipread);

	//money_a -> [moneyoffset1+offset2]
	DWORD svalue = money_c;
	WriteProcessMemory(handle, LPVOID(moneyoffset1 + offset2), &svalue, sizeof(DWORD), &ipread);
}

void CPVZCrackerDlg::OnBnClickedButton5(){
	// 修改冷却
	UpdateData(TRUE);
	HWND PVZ;
	PVZ = ::FindWindow(L"MAINWINDOW", L"植物大战僵尸杂交版v2.0");
	DWORD pid = 0;
	GetWindowThreadProcessId(PVZ, &pid);
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	SIZE_T ipread = 0;           //下面要用的参数

	DWORD base = 0x006A9EC0;	 //数据基地址偏移量等由CE给出。
	DWORD offset1 = 0x00000768;
	DWORD offset2 = 0x00000144;
	DWORD offset3[16] = {
		0x00000070, 0x000000C0, 0x00000110, 0x00000160,
		0x000001B0, 0x00000200, 0x00000250, 0x000002A0,
		0x000002F0, 0x00000340, 0x00000390, 0x000003E0,
		0x00000430, 0x00000480, 0x000004D0, 0x00000520
	};

	//[base]->freshbase
	DWORD freshbase = 0;
	ReadProcessMemory(handle, LPCVOID(base), &freshbase, sizeof(DWORD), &ipread);

	//[freshbase+offset1]->freshoffset1
	DWORD freshoffset1 = 0;
	ReadProcessMemory(handle, LPCVOID(freshbase + offset1), &freshoffset1, sizeof(DWORD), &ipread);

	//[freshoffset1+offset2]->freshoffset2
	DWORD freshoffset2 = 0;
	ReadProcessMemory(handle, LPVOID(freshoffset1 + offset2), &freshoffset2, sizeof(DWORD), &ipread);

	//1 ->[freshoffset2+offset3]
	DWORD freshvalue = 1;	//1代表冷却完毕	其他代表正在冷却
	for (int i = 0; i < 16; ++i)
		WriteProcessMemory(handle, LPVOID(freshoffset2 + offset3[i]), &freshvalue, sizeof(DWORD), &ipread);
}


void CPVZCrackerDlg::OnBnClickedCheck1(){
	// TODO: 在此添加控件通知处理程序代码
	CButton* pBtn = (CButton*)GetDlgItem(CHECK1);
	int checked = pBtn->GetCheck();	//获取check状态

	switch (checked){
	case 1: {
		SetTimer(1, 500, NULL);	//设置500ms为周期的定时器，标签为1，并开启
		break;
	}
	case 0: {
		KillTimer(1);			//关闭标签为1的定时器
		break;
	}
	default:
		break;
	}
}


void CPVZCrackerDlg::OnBnClickedCheck2(){
	// TODO: 在此添加控件通知处理程序代码
	CButton* pBtn = (CButton*)GetDlgItem(CHECK2);
	int checked = pBtn->GetCheck();

	switch (checked) {
	case 1: {
		SetTimer(2, 500, NULL);
		break;
	}
	case 0: {
		KillTimer(2);
		break;
	}
	default:
		break;
	}
}


void CPVZCrackerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent){
	case 1: OnBnClickedButton1(); break;
	case 2: OnBnClickedButton5(); break;
	default:
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CPVZCrackerDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	KillTimer(1);
	KillTimer(2);
	CDialogEx::OnClose();
}
