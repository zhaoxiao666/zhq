
// StrXMLDlg.h : ͷ�ļ�
//

#pragma once


// CStrXMLDlg �Ի���
class CStrXMLDlg : public CDialogEx
{
// ����
public:
	CStrXMLDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_STRXML_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBrowse();
	CString strFilePath;
	CString m_PathName;
	CString FileName;
	afx_msg void OnBnClickedRead();
};
