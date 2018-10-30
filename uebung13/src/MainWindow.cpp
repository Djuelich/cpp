#include "MainWindow.hpp"
#include "LevelScene.hpp"

#include <iostream>
using namespace std;

MainWindow::MainWindow(QMainWindow *parent) : QMainWindow(parent)
{
    setupUi(this);
    
    //Connects the pushButton with the MainWindow::pressed() funtion
    connect(pushButton, SIGNAL(pressed()), this, SLOT(pressed()));
}

void MainWindow::pressed()
{   
    //File Selection, only .lvl files can be opened
    QString filename = QFileDialog::getOpenFileName(
                                    this,
                                    tr("Open Level"),
                                    "./",
                                    "Level File (*.lvl)"
                                    );

    LevelScene* ls = new LevelScene(filename, this);

    this->graphicsView->setScene(ls);

}
