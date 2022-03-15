#include "extrawork.h"
#include "ui_extrawork.h"
#include <QLibrary>

typedef int (*getPasswd)();

ExtraWork::ExtraWork(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExtraWork)
{
    m_nPasswd = -999;
    //获取了博客访问量 作为授权码
    QLibrary library(QCoreApplication::applicationDirPath() + "/GetMyPasswd.dll");
    if(!library.load())
    {
        return;
    }
    getPasswd getfunc = (getPasswd)library.resolve("getMyPasswd");
    m_nPasswd = getfunc();

    //输入授权码，完成登录
    ui->setupUi(this);
    ui->lineEdit->setFocus();
}

ExtraWork::~ExtraWork()
{
    delete ui;
}

void ExtraWork::on_lineEdit_textChanged(const QString &arg1)
{
    if(arg1.toInt() == m_nPasswd)
    {
        accept();
    }
}
