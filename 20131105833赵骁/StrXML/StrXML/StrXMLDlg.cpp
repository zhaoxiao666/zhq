
// StrXMLDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StrXML.h"
#include "StrXMLDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStrXMLDlg �Ի���




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


// CStrXMLDlg ��Ϣ�������

BOOL CStrXMLDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CStrXMLDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CStrXMLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CStrXMLDlg::OnBnClickedBrowse()
{
	
	TCHAR szFilter[]=_T("XML�ļ�(*.xml)|*.xml|gpx�ļ�(*.gpx)|*.gpx|�����ļ�(*.*)|*.*||");
	
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
	MessageBox(L"���ɳɹ�");

}
