#ifndef EDITOR_AJUSTES_H
#define EDITOR_AJUSTES_H

#include <QDialog>

namespace Ui {
class Ajustes;
}

class Ajustes : public QDialog
{
    Q_OBJECT

public:
    explicit Ajustes(QWidget *parent = 0);
    ~Ajustes();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

    void on_pushButton_clicked();

private:
    Ui::Ajustes *ui;
};

#endif // EDITOR_AJUSTES_H
