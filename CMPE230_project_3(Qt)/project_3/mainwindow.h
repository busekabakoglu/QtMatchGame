#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QAbstractButton>
#include <QMainWindow>
#include <iostream>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool shouldWait = false;
    int count = 0;
    int tries = 0;
    int pairs = 0;
    vector <char> letters{'A','A','B','B','C','C','D','D','E','E','F','F','G','G','H','H','I','I','J','J','K','K','L','L'};
    QAbstractButton* previousButton;
    QAbstractButton* prevprevButton;
    map<QAbstractButton *, char> buttonDict;
    void shuffle();



private:
    Ui::MainWindow *ui;
private slots:
    void hello(int num) ;
    void reset();
};


#endif // MAINWINDOW_H
