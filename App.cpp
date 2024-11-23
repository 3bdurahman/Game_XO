#include "App.h"

App::App(QWidget *parent) : QWidget(parent), ui(new Ui::AppClass())
{
  ui->setupUi(this);
  for (size_t i = 0; i < 3; i++)
  {
    for (size_t j = 0; j < 3; j++) button[i][j] = new QPushButton(this);
  }
  msg = new QMessageBox;
  Widget();
  Button();
  event();
  Qmsg();
}

App::~App()
{
   delete ui;
   delete msg;
   for (size_t i = 0; i < 3; i++)
   {
     for (size_t j = 0; j < 3; j++) delete button[i][j];
   }
}

void App::Qmsg()
{
  msg->setText("Do you want to play again?");
  msg->setIcon(QMessageBox::Question);
  msg->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
}

void App::Widget()
{
  setStyleSheet("background-color: #848482; ");
  resize(500, 500);
}

void App::Message(const char c)
{
  if (c == 48) msg->setWindowTitle("Draw");
  else msg->setWindowTitle(QString("Win user ") + c);

  if (msg->exec() == QMessageBox::Yes)
  {
    Button();
    z = 'X';
  }
  else
  {
    system("cmd.exe /c start chrome https://github.com/3bdurahman");
    exit(1);
  }
}

void App::Button()
{
  QFont* font = new QFont("Consolas", 28);
  QString buttonStyle =
    "QPushButton"
    "{"
    "background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, "
    "stop:0 #00ffff, stop:1 #4b5320);"
    "border-radius: 10px;"
    "border: 1px solid white;"
    "}"

    "QPushButton:Pressed"
    "{"
    "background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, "
    "stop:0 white, stop:1 red);"
    "}";
  int y = 80;
  for (size_t i = 0; i < 3; i++)
  {
    int x = 120;
    for (size_t j = 0; j < 3; j++)
    {
      button[i][j]->setFont(*font);
      button[i][j]->setText("_");
      button[i][j]->setGeometry(x, y, 80, 50);
      button[i][j]->setStyleSheet(buttonStyle);
      x += 100;
    }
    y += 60;
  }
}

void App::b1()
{
  if (button[0][0]->text() == '_')
  {
    button[0][0]->setText(z);
    z = (z == 'X' ? 'O' : 'X');
  }
  if (button[0][0]->text() == button[0][1]->text() && button[0][1] == button[0][2] && button[0][0]->text() == 'X')
    Message('1');
  else if (button[0][0]->text() == button[0][1]->text() && button[0][1] == button[0][2] && button[0][0]->text() == 'O')
    Message('2');
  else if (button[0][0]->text() == button[1][0]->text() && button[1][0]->text() == button[2][0]->text() && button[0][0]->text() == 'X')
    Message('1');
  else if (button[0][0]->text() == button[1][0]->text() && button[1][0]->text() == button[2][0]->text() && button[0][0]->text() == 'O')
    Message('2');
  else if (button[0][0]->text() == button[1][1]->text() && button[1][1]->text() == button[2][2]->text() && button[0][0]->text() == 'X')
    Message('1');
  else if (button[0][0]->text() == button[1][1]->text() && button[1][1]->text() == button[2][2]->text() && button[0][0]->text() == 'O')
    Message('2');
  else
  {
    bool check = true;
    for (size_t i = 0; i < 3; i++)
    {
      for (size_t j = 0; j < 3; j++)
      {
        if (button[i][j]->text() == '_')
        {
          check = false;
          break;
        }
      }
      if (!check) break;
    }
    if (check) Message('0');
  }
}

void App::b2()
{
  if (button[0][1]->text() == '_')
  {
    button[0][1]->setText(z);
    z = (z == 'X' ? 'O' : 'X');
  }
  if (button[0][0]->text() == button[0][1]->text() && button[0][1] == button[0][2] && button[0][0]->text() == 'X')
    Message('1');
  else if (button[0][0]->text() == button[0][1]->text() && button[0][1] == button[0][2] && button[0][0]->text() == 'O')
    Message('2');
  else if (button[0][1]->text() == button[1][1]->text() && button[1][1]->text() == button[2][1]->text() && button[0][1]->text() == 'X')
    Message('1');
  else if (button[0][1]->text() == button[1][1]->text() && button[1][1]->text() == button[2][1]->text() && button[0][1]->text() == 'O')
    Message('2');
  else
  {
    bool check = true;
    for (size_t i = 0; i < 3; i++)
    {
      for (size_t j = 0; j < 3; j++)
      {
        if (button[i][j]->text() == '_')
        {
          check = false;
          break;
        }
      }
      if (!check) break;
    }
    if (check) Message('0');
  }
}

void App::b3()
{
  if (button[0][2]->text() == '_')
  {
    button[0][2]->setText(z);
    z = (z == 'X' ? 'O' : 'X');
  }
  if (button[0][0]->text() == button[0][1]->text() && button[0][1] == button[0][2] && button[0][0]->text() == 'X')
    Message('1');
  else if (button[0][0]->text() == button[0][1]->text() && button[0][1] == button[0][2] && button[0][0]->text() == 'O')
    Message('2');
  else if (button[0][2]->text() == button[1][2]->text() && button[1][2]->text() == button[2][2]->text() && button[0][2]->text() == 'X')
    Message('1');
  else if (button[0][2]->text() == button[1][2]->text() && button[1][2]->text() == button[2][2]->text() && button[0][2]->text() == 'O')
    Message('2');
  else if (button[0][2]->text() == button[1][1]->text() && button[1][1]->text() == button[2][0]->text() && button[0][2]->text() == 'X')
    Message('1');
  else if (button[0][2]->text() == button[1][1]->text() && button[1][1]->text() == button[2][0]->text() && button[0][2]->text() == 'O')
    Message('2');
  else
  {
    bool check = true;
    for (size_t i = 0; i < 3; i++)
    {
      for (size_t j = 0; j < 3; j++)
      {
        if (button[i][j]->text() == '_')
        {
          check = false;
          break;
        }
      }
      if (!check) break;
    }
    if (check) Message('0');
  }
}

void App::b4()
{
  if (button[1][0]->text() == '_')
  {
    button[1][0]->setText(z);
    z = (z == 'X' ? 'O' : 'X');
  }
  
  if (button[0][0]->text() == button[1][0]->text() && button[1][0]->text() == button[2][0]->text() && button[0][0]->text() == 'X')
    Message('1');
  else if (button[0][0]->text() == button[1][0]->text() && button[1][0]->text() == button[2][0]->text() && button[0][0]->text() == 'O')
    Message('2');
  else if (button[1][0]->text() == button[1][1]->text() && button[1][1]->text() == button[1][2]->text() && button[1][0]->text() == 'X')
    Message('1');
  else if (button[1][0]->text() == button[1][1]->text() && button[1][1]->text() == button[1][2]->text() && button[1][0]->text() == 'O')
    Message('2');
  else
  {
    bool check = true;
    for (size_t i = 0; i < 3; i++)
    {
      for (size_t j = 0; j < 3; j++)
      {
        if (button[i][j]->text() == '_')
        {
          check = false;
          break;
        }
      }
      if (!check) break;
    }
    if (check) Message('0');
  }
}

void App::b5()
{
  if (button[1][1]->text() == '_')
  {
    button[1][1]->setText(z);
    z = (z == 'X' ? 'O' : 'X');
  }
  
  if (button[0][1]->text() == button[1][1]->text() && button[1][1]->text() == button[2][1]->text() && button[0][1]->text() == 'X')
    Message('1');
  else if (button[0][1]->text() == button[1][1]->text() && button[1][1]->text() == button[2][1]->text() && button[0][1]->text() == 'O')
    Message('2');
  else if (button[0][0]->text() == button[1][1]->text() && button[1][1]->text() == button[2][2]->text() && button[0][0]->text() == 'X')
    Message('1');
  else if (button[0][0]->text() == button[1][1]->text() && button[1][1]->text() == button[2][2]->text() && button[0][0]->text() == 'O')
    Message('2');
  else if (button[0][2]->text() == button[1][1]->text() && button[1][1]->text() == button[2][0]->text() && button[0][2]->text() == 'X')
    Message('1');
  else if (button[0][2]->text() == button[1][1]->text() && button[1][1]->text() == button[2][0]->text() && button[0][2]->text() == 'O')
    Message('2');
  else if (button[1][1]->text() == button[1][0]->text() && button[1][0]->text() == button[1][2]->text() && button[1][1]->text() == 'X')
    Message('1');
  else if (button[1][1]->text() == button[1][0]->text() && button[1][0]->text() == button[1][2]->text() && button[1][1]->text() == 'O')
    Message('2');
  else
  {
    bool check = true;
    for (size_t i = 0; i < 3; i++)
    {
      for (size_t j = 0; j < 3; j++)
      {
        if (button[i][j]->text() == '_')
        {
          check = false;
          break;
        }
      }
      if (!check) break;
    }
    if (check) Message('0');
  }
}

void App::b6()
{
  if (button[1][2]->text() == '_')
  {
    button[1][2]->setText(z);
    z = (z == 'X' ? 'O' : 'X');
  }
  
  if (button[1][1]->text() == button[1][0]->text() && button[1][0]->text() == button[1][2]->text() && button[1][1]->text() == 'X')
    Message('1');
  else if (button[1][1]->text() == button[1][0]->text() && button[1][0]->text() == button[1][2]->text() && button[1][1]->text() == 'O')
    Message('2');
  else if (button[0][2]->text() == button[1][2]->text() && button[1][2]->text() == button[2][2]->text() && button[0][2]->text() == 'X')
    Message('1');
  else if (button[0][2]->text() == button[1][2]->text() && button[1][2]->text() == button[2][2]->text() && button[0][2]->text() == 'O')
    Message('2');
  else
  {
    bool check = true;
    for (size_t i = 0; i < 3; i++)
    {
      for (size_t j = 0; j < 3; j++)
      {
        if (button[i][j]->text() == '_')
        {
          check = false;
          break;
        }
      }
      if (!check) break;
    }
    if (check) Message('0');
  }
}

void App::b7()
{
  if (button[2][0]->text() == '_')
  {
    button[2][0]->setText(z);
    z = (z == 'X' ? 'O' : 'X');
  }
  
  if (button[0][0]->text() == button[1][0]->text() && button[1][0]->text() == button[2][0]->text() && button[0][0]->text() == 'X')
    Message('1');
  else if (button[0][0]->text() == button[1][0]->text() && button[1][0]->text() == button[2][0]->text() && button[0][0]->text() == 'O')
    Message('2');
  else if (button[0][2]->text() == button[1][1]->text() && button[1][1]->text() == button[2][0]->text() && button[0][2]->text() == 'X')
    Message('1');
  else if (button[0][2]->text() == button[1][1]->text() && button[1][1]->text() == button[2][0]->text() && button[0][2]->text() == 'O')
    Message('2');
  else if (button[2][0]->text() == button[2][1]->text() && button[2][1]->text() == button[2][2]->text() && button[2][0]->text() == 'X')
    Message('1');
  else if (button[2][0]->text() == button[2][1]->text() && button[2][1]->text() == button[2][2]->text() && button[2][0]->text() == 'O')
    Message('2');
  else
  {
    bool check = true;
    for (size_t i = 0; i < 3; i++)
    {
      for (size_t j = 0; j < 3; j++)
      {
        if (button[i][j]->text() == '_')
        {
          check = false;
          break;
        }
      }
      if (!check) break;
    }
    if (check) Message('0');
  }
}

void App::b8()
{
  if (button[2][1]->text() == '_')
  {
    button[2][1]->setText(z);
    z = (z == 'X' ? 'O' : 'X');
  }
  
  if (button[2][0]->text() == button[2][1]->text() && button[2][1]->text() == button[2][2]->text() && button[2][0]->text() == 'X')
    Message('1');
  else if (button[2][0]->text() == button[2][1]->text() && button[2][1]->text() == button[2][2]->text() && button[2][0]->text() == 'O')
    Message('2');
  if (button[0][1]->text() == button[1][1]->text() && button[1][1]->text() == button[2][1]->text() && button[0][1]->text() == 'X')
    Message('1');
  else if (button[0][1]->text() == button[1][1]->text() && button[1][1]->text() == button[2][1]->text() && button[0][1]->text() == 'O')
    Message('2');
  else
  {
    bool check = true;
    for (size_t i = 0; i < 3; i++)
    {
      for (size_t j = 0; j < 3; j++)
      {
        if (button[i][j]->text() == '_')
        {
          check = false;
          break;
        }
      }
      if (!check) break;
    }
    if (check) Message('0');
  }
}

void App::b9()
{
  if (button[2][2]->text() == '_')
  {
    button[2][2]->setText(z);
    z = (z == 'X' ? 'O' : 'X');
  }

  if (button[2][0]->text() == button[2][1]->text() && button[2][1]->text() == button[2][2]->text() && button[2][0]->text() == 'X')
    Message('1');
  else if (button[2][0]->text() == button[2][1]->text() && button[2][1]->text() == button[2][2]->text() && button[2][0]->text() == 'O')
    Message('2');
  else if (button[0][2]->text() == button[1][2]->text() && button[1][2]->text() == button[2][2]->text() && button[0][2]->text() == 'X')
    Message('1');
  else if (button[0][2]->text() == button[1][2]->text() && button[1][2]->text() == button[2][2]->text() && button[0][2]->text() == 'O')
    Message('2');
  else if (button[0][0]->text() == button[1][1]->text() && button[1][1]->text() == button[2][2]->text() && button[0][0]->text() == 'X')
    Message('1');
  else if (button[0][0]->text() == button[1][1]->text() && button[1][1]->text() == button[2][2]->text() && button[0][0]->text() == 'O')
    Message('2');
  else
  {
    bool check = true;
    for (size_t i = 0; i < 3; i++)
    {
      for (size_t j = 0; j < 3; j++)
      {
        if (button[i][j]->text() == '_')
        {
          check = false;
          break;
        }
      }
      if (!check) break;
    }
    if (check) Message('0');
  }
}

void App::event()
{
  connect(button[0][0], &QPushButton::clicked, this, &App::b1);
  connect(button[0][1], &QPushButton::clicked, this, &App::b2);
  connect(button[0][2], &QPushButton::clicked, this, &App::b3);
  connect(button[1][0], &QPushButton::clicked, this, &App::b4);
  connect(button[1][1], &QPushButton::clicked, this, &App::b5);
  connect(button[1][2], &QPushButton::clicked, this, &App::b6);
  connect(button[2][0], &QPushButton::clicked, this, &App::b7);
  connect(button[2][1], &QPushButton::clicked, this, &App::b8);
  connect(button[2][2], &QPushButton::clicked, this, &App::b9);
}