#include "extrawork.h"
#include "form.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExtraWork w;
    Form f;
    w.setWindowFlags(Qt::WindowCloseButtonHint);
    if(w.exec() == QDialog::Accepted)
    {
        f.show();
        return a.exec();
    }
    else
    {
        return 0;
    }
}
