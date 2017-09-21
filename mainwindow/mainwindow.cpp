// ========== mainwindow.cpp
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QDebug>
#include <QToolBar>
#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));
    openAction = new QAction(QIcon(":/images/doc-open"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, &QAction::triggered, this, &MainWindow::open);
    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    statusBar() ;
}

MainWindow::~MainWindow()
{ 
}

void MainWindow::open()
{
#if 0
    QMessageBox::information(this, tr("Information"), tr("Open"));
#endif

#if 0
    QDialog dialog;

    dialog.setWindowTitle(tr("Hello, dialog!"));
    dialog.exec();
#endif

#if 0
    QDialog dialog(this);

    dialog.setWindowTitle(tr("Hello, dialog!"));
    dialog.exec();
#endif

#if 0
    QDialog dialog(this);

    dialog.setWindowTitle(tr("Hello, dialog!"));
    dialog.show();
#endif

#if 0
    QDialog *dialog = new QDialog;  /* memory leak */

    dialog->setWindowTitle(tr("Hello, dialog!"));
    dialog->show();
#endif

#if 0
    QDialog *dialog = new QDialog;

    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setWindowTitle(tr("Hello, dialog!"));
    dialog->show();
#endif

#if 0
    if (QMessageBox::Yes == QMessageBox::question(this,
                tr("Question"),
                tr("Are you OK?"),
                QMessageBox::Yes | QMessageBox::No,
                QMessageBox::Yes)) {
        QMessageBox::information(this, tr("Hmmm..."), tr("I'm glad to hear that!"));
    } else {
        QMessageBox::information(this, tr("Hmmm..."), tr("I'm sorry!"));
    }
#endif

#if 1
    QMessageBox msgBox;
    msgBox.setText(tr("The document has been modified."));
    msgBox.setInformativeText(tr("Do you want to save your changes?"));
    msgBox.setDetailedText(tr("Differences here..."));
    msgBox.setStandardButtons(QMessageBox::Save
            | QMessageBox::Discard
            | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    switch (ret) {
        case QMessageBox::Save:
            qDebug() << "Save document!";
            break;
        case QMessageBox::Discard:
            qDebug() << "Discard changes!";
            break;
        case QMessageBox::Cancel:
            qDebug() << "Close document!";
            break;
    }
#endif

}
