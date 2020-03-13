#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <QAbstractButton>
#include <iostream>
#include <map>
#include <QTest>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    shuffle();
    //if any button is cliked from the buttongroup go to hello() slot
    connect(ui->buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(hello(int)));
    //if RESET button is clicked go to reset() slot
    connect(ui->RESET,SIGNAL(pressed()),this,SLOT(reset()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::hello(int num){
    //if the user tries to push more buttons when already two of them is open, disable it
    if(shouldWait){
        return;
    }
    //if no button is pressed
    if(this->count==0){
        QString label =QChar(buttonDict[ui->buttonGroup->button(num)]);
        ui->buttonGroup->button(num)->setText(label);
        ui->buttonGroup->button(num)->setEnabled(false);//make pressed one disabled
        //make previousbutton = currently pressed button
        previousButton = ui->buttonGroup->button(num);
        count++;
        tries++;//increment trying number
        ui->tries_num->display(tries);
    }
    else{
        prevprevButton = previousButton;
        QString label =QChar(buttonDict[ui->buttonGroup->button(num)]);
        ui->buttonGroup->button(num)->setText(label);
        ui->buttonGroup->button(num)->setEnabled(false);
        shouldWait = true;
        QTest::qWait(1000);
        shouldWait = false;
        //make previousbutton = currently pressed button
        previousButton = ui->buttonGroup->button(num);
        int previd = ui->buttonGroup->id(previousButton);
        int prevprevid = ui->buttonGroup->id(prevprevButton);
        QString prevlabel =QChar(buttonDict[previousButton]);
        QString prevprevlabel =QChar(buttonDict[prevprevButton]);
        count = 0;
        //if the letters on the cards are the same
        if(prevlabel==prevprevlabel){
            //make them disabled, increment the found pair number
            ui->buttonGroup->button( ui->buttonGroup->id(previousButton))->setEnabled(false);
            ui->buttonGroup->button( ui->buttonGroup->id(prevprevButton))->setEnabled(false);
            ui->buttonGroup->button( ui->buttonGroup->id(previousButton))->setText("");
            ui->buttonGroup->button( ui->buttonGroup->id(prevprevButton))->setText("");
            pairs++;
            ui->pair_num->display(pairs);
        }
        else {
            //else turn them over again
            ui->buttonGroup->button( ui->buttonGroup->id(previousButton))->setEnabled(true);
            ui->buttonGroup->button( ui->buttonGroup->id(prevprevButton))->setEnabled(true);
            ui->buttonGroup->button(previd)->setText("X");
            ui->buttonGroup->button(prevprevid)->setText("X");
        }
    }
}
//buttonDict is a map holding button names and their letters
void MainWindow::shuffle(){
    //randomly assigning letters to pushbuttons
    random_shuffle(letters.begin(),letters.end());
    buttonDict[ui->pushButton00] = letters[0];
    buttonDict[ui->pushButton01] = letters[1];
    buttonDict[ui->pushButton02] = letters[2];
    buttonDict[ui->pushButton03] = letters[3];
    buttonDict[ui->pushButton04] = letters[4];
    buttonDict[ui->pushButton05] = letters[5];
    buttonDict[ui->pushButton06] = letters[6];
    buttonDict[ui->pushButton07] = letters[7];
    buttonDict[ui->pushButton08] = letters[8];
    buttonDict[ui->pushButton09] = letters[9];
    buttonDict[ui->pushButton10] = letters[10];
    buttonDict[ui->pushButton11] = letters[11];
    buttonDict[ui->pushButton12] = letters[12];
    buttonDict[ui->pushButton13] = letters[13];
    buttonDict[ui->pushButton14] = letters[14];
    buttonDict[ui->pushButton15] = letters[15];
    buttonDict[ui->pushButton16] = letters[16];
    buttonDict[ui->pushButton17] = letters[17];
    buttonDict[ui->pushButton18] = letters[18];
    buttonDict[ui->pushButton19] = letters[19];
    buttonDict[ui->pushButton20] = letters[20];
    buttonDict[ui->pushButton21] = letters[21];
    buttonDict[ui->pushButton22] = letters[22];
    buttonDict[ui->pushButton23] = letters[23];

}
void MainWindow::reset(){
    //restart the game again
    shuffle();
    count = 0;
    tries = 0;
    pairs = 0;
    ui->pair_num->display(pairs);
    ui->tries_num->display(tries);
    foreach(QAbstractButton *button, ui->buttonGroup->buttons()) {
        button->setText("X");
        button->setEnabled(true);
    }
}
