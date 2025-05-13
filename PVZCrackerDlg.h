
// PVZCrackerDlg.h: 头文件
//

#pragma once


// CPVZCrackerDlg 对话框
class CPVZCrackerDlg : public CDialogEx
{
// 构造
public:
	CPVZCrackerDlg(CWnd* pParent = nullptr);	// 标准构造函数
	UINT sunvalue;	//阳光
	UINT money_a;	//银币
	UINT money_b;	//金币
	UINT money_c;	//钻石
	int check1;		//锁定阳光	check 的状态
	int check2;		//无冷却	check 的状态
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PVZCRACKER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();

	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	int TIM_X ;
	afx_msg void OnClose();
};
