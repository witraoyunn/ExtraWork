#ifndef EXTRAWORK_H
#define EXTRAWORK_H

#include <QDialog>

namespace Ui {
class ExtraWork;
}

class ExtraWork : public QDialog
{
    Q_OBJECT

public:
    explicit ExtraWork(QWidget *parent = 0);
    ~ExtraWork();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::ExtraWork *ui;
    int m_nPasswd;

};

#endif // EXTRAWORK_H
