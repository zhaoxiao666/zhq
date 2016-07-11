
// StrXMLDlg.h : 头文件
//

#pragma once


// CStrXMLDlg 对话框
class CStrXMLDlg : public CDialogEx
{
// 构造
public:
	CStrXMLDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_STRXML_DIALOG };

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
	afx_msg void OnBnClickedBrowse();
	CString strFilePath;
	CString m_PathName;
	CString FileName;
	afx_msg void OnBnClickedRead();
};
