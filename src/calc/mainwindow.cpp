#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  ui->widget->xAxis->setRange(-10, 10);
  ui->widget->yAxis->setRange(-10, 10);

  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_10, SIGNAL(clicked()), this,
          SLOT(on_pushButton_10_clicked()));
  connect(ui->pushButton_POINT, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_PLUS, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_MINUS, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_DIV, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_MUL, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_POW, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_LN, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_LOG, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_MOD, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_SIN, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_COS, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_TAN, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_ASIN, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_ACOS, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_ATAN, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_OP, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_CL, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_X, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_SQRT, SIGNAL(clicked()), this, SLOT(button_push()));
  connect(ui->pushButton_EQ, SIGNAL(clicked()), this,
          SLOT(on_pushButton_EQ_clicked()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::button_push() {
  QPushButton *button = (QPushButton *)sender();

  QString new_label = ui->result->text() + button->text();

  ui->result->setText(new_label);
}

void MainWindow::on_pushButton_EQ_clicked() {
  char *str = new char(ui->result->text().length());
  QByteArray barr = ui->result->text().toLatin1();
  strlcpy(str, barr, ui->result->text().length() + 1);

  if (verification(str)) {
    ui->result->setText("Incorrect expression");
  } else {
    str = parser(str);
    stack *work = NULL;
    double result = calculate(&work, str, 0);

    QString numberResult = QString::number(result);
    ui->result->setText(numberResult);
  }
  delete (str);
}

void MainWindow::on_pushButton_10_clicked() { ui->result->setText(""); }

void MainWindow::on_pushButton_backspace_clicked() { ui->result->backspace(); }

void MainWindow::on_pushButton_Grafic_clicked() {
  double x_min, x_max, y_min, y_max;
  x_min = ui->doubleSpinBox_1minX->text().toDouble();
  x_max = ui->doubleSpinBox_2maxX->text().toDouble();
  y_min = ui->doubleSpinBox_3minY->text().toDouble();
  y_max = ui->doubleSpinBox_4maxY->text().toDouble();
  ui->widget->xAxis->setRange(x_min, x_max);
  ui->widget->yAxis->setRange(y_min, y_max);
  QVector<double> x, y;
  x.clear();
  y.clear();
  int N = ui->spinBox_N->value();
  double h = (x_max - x_min) / N;
  double X = x_min, Y = 0;
  char *str = new char(ui->result->text().length());
  QByteArray barr = ui->result->text().toLatin1();
  strlcpy(str, barr, ui->result->text().length() + 1);
  if (verification(str)) {
    ui->result->setText("Incorrect expression");
  } else {
    str = parser(str);
    stack *work = NULL;
    for (int i = 0; i <= N; i++) {
      Y = calculate(&work, str, X);
      if (Y >= y_min && Y <= y_max) {
        x.push_back(X);
        y.push_back(Y);
      }
      X += h;
    }
    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    // ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle,
    // 4));
    ui->widget->replot();
  }
  delete (str);
}

void MainWindow::on_pushButton_Clear_Graf_clicked() {
  ui->widget->clearGraphs();
  ui->widget->replot();
}

void MainWindow::on_pushButton_calculateCredit_clicked() {
  double sum = 0, term = 0, per = 0, payment1 = 0, payment2 = 0, total = 0,
         over = 0;
  sum = ui->doubleSpinBox_sum->text().toDouble();
  term = ui->doubleSpinBox_term->text().toDouble();
  per = ui->doubleSpinBox_per->text().toDouble();
  if (ui->comboBox_type->currentIndex() == 0) {
    credit_an(sum, term, per, &payment1, &over, &total);
    ui->label_paymenOut->setText(QString::number(payment1));
    ui->label_overOut->setText(QString::number(over));
    ui->label_totalOut->setText(QString::number(total));
  } else {
    credit_diff(sum, term, per, &payment1, &payment2, &over, &total);
    ui->label_paymenOut->setText(QString::number(payment1));
    ui->label_paymenOut->setText(ui->label_paymenOut->text() += "...");
    ui->label_paymenOut->setText(ui->label_paymenOut->text() +=
                                 QString::number(payment2));
    ui->label_paymenOut->setText(QString::number(payment1));
    ui->label_overOut->setText(QString::number(over));
    ui->label_totalOut->setText(QString::number(total));
  }
}

void MainWindow::on_pushButton_calculateDeposit_clicked() {
  double sum, per = 0, nalog_per = 0, add = 0, take = 0, payment = 0, total = 0,
              nalog_sum = 0;
  int term = 0, term_payment = 0, kapital = 0, list_add = 0, list_take = 0;
  sum = ui->doubleSpinBox_sum_2->text().toDouble();
  per = ui->doubleSpinBox_per_2->text().toDouble();
  term = ui->doubleSpinBox_term_2->text().toDouble();
  nalog_per = ui->doubleSpinBox_nalog_per->text().toDouble();
  term_payment = ui->comboBox_term->currentIndex();
  kapital = ui->checkBox->checkState();
  list_add = ui->comboBox_term_add->currentIndex();
  list_take = ui->comboBox_term_take->currentIndex();
  add = ui->doubleSpinBox_add->text().toDouble();
  take = ui->doubleSpinBox_take->text().toDouble();
  deposit(sum, term, per, nalog_per, term_payment, kapital, list_add, add,
          list_take, take, &payment, &total, &nalog_sum);
  ui->label_paymenOut_1->setText(QString::number(payment));
  ui->label_nalog->setText(QString::number(nalog_sum));
  ui->label_totalOut_1->setText(QString::number(total));
}
