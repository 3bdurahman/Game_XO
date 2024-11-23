#pragma once

#include <QtWidgets/QWidget>
#include "ui_App.h"
#include <QPushButton>
#include <QFont>
#include <QMessageBox>
#include <cstdlib>

QT_BEGIN_NAMESPACE
namespace Ui { class AppClass; };
QT_END_NAMESPACE

class App : public QWidget
{
  Q_OBJECT

public:
  App(QWidget *parent = nullptr);
  ~App();

private:
  Ui::AppClass *ui;
  QPushButton* button[3][3];
  QMessageBox* msg;
  QChar z = 'X';
  void Message(const char str);
  void Widget();
  void Button();
  void event();
  void Qmsg();
  void b1();
  void b2();
  void b3();
  void b4();
  void b5();
  void b6();
  void b7();
  void b8();
  void b9();
};
