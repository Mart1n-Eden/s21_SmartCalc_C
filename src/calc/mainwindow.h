#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qcustomplot.h>

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

extern "C" {
#include "smart_calc.h"
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;

 private slots:
  void button_push();
  void on_pushButton_EQ_clicked();
  void on_pushButton_10_clicked();
  void on_pushButton_backspace_clicked();
  void on_pushButton_Grafic_clicked();
  void on_pushButton_Clear_Graf_clicked();
  void on_pushButton_calculateCredit_clicked();
  void on_pushButton_calculateDeposit_clicked();
};
#endif  // MAINWINDOW_H
