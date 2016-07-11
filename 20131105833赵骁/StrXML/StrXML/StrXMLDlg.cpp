
// StrXMLDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StrXML.h"
#include "StrXMLDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStrXMLDlg 对话框




CStrXMLDlg::CStrXMLDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStrXMLDlg::IDD, pParent)
	, m_PathName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strFilePath = _T("");
}

void CStrXMLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FilePath, m_PathName);
}

BEGIN_MESSAGE_MAP(CStrXMLDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Browse, &CStrXMLDlg::OnBnClickedBrowse)
	ON_BN_CLICKED(IDC_Read, &CStrXMLDlg::OnBnClickedRead)
END_MESSAGE_MAP()


// CStrXMLDlg 消息处理程序

BOOL CStrXMLDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CStrXMLDlg::OnPaint()
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
HCURSOR CStrXMLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CStrXMLDlg::OnBnClickedBrowse()
{
	
	TCHAR szFilter[]=_T("XML文件(*.xml)|*.xml|gpx文件(*.gpx)|*.gpx|所有文件(*.*)|*.*||");
	
	CFileDialog fileDlg(TRUE,_T("xml"),NULL,0,szFilter,this);
	
	if(IDOK==fileDlg.DoModal())
	{
		strFilePath=fileDlg.GetPathName();
		SetDlgItemText(IDC_FilePath,strFilePath);
	}
	FileName=fileDlg.GetFileName();
}


void CStrXMLDlg::OnBnClickedRead()
{
	CString AllFile=NULL;
	CFile file,write;
	file.Open(strFilePath,CFile::modeRead);
	int L=file.GetLength();
	int loop=0,i=1;
	char *Temp;
	CString number,lat,lon,date,time,Enter=L"\r\n";
	Temp=new char[L+1];
	file.Read(Temp,L);
	AllFile=Temp;
	strFilePath.Replace(FileName,L"");
	file.Close();
	write.Open(strFilePath+"123456.csv",CFile::modeCreate|CFile::modeWrite);
	loop=AllFile.Find(L"trkpt",0);
	while(loop<L)
	{
		lat=AllFile.Mid(loop+11,9);
		lon=AllFile.Mid(loop+27,10);
		date=AllFile.Mid(loop+50,10);
		time=AllFile.Mid(loop+61,8);
		number.Format(L"%d",i);
		write.Write((char*)(_bstr_t)number,number.GetLength());
		write.Write(L",",1);
		write.Write((char*)(_bstr_t)lat,9);
		write.Write(L",",1);
		write.Write((char*)(_bstr_t)lon,10);
		write.Write(L",",1);
		write.Write((char*)(_bstr_t)date,10);
		write.Write(L",",1);
		write.Write((char*)(_bstr_t)time,8);
		write.Write((char*)(_bstr_t)Enter,Enter.GetLength());
		loop=loop+94;
		i++;
	}
	write.Close();
	MessageBox(L"生成成功");

}
