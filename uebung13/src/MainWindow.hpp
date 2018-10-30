#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QtGui>

#include "MainWindowInterface.h"

class MainWindow : public QMainWindow, public Ui::MainWindow{
    Q_OBJECT
    
public:
    MainWindow (QMainWindow *parent = 0);
    ~MainWindow() {};
    
public Q_SLOTS:
    /* Opens File Dialog */
    void pressed();
};

#endif
