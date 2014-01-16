/*
Author: Krishna Pattabiraman

*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
 #include <QMessageBox>
#include <QFileDialog>
#include <QPrinter>
#include <QPrinterInfo>
#include <QPrintDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Export PDF",
                                                    QString(), "*.pdf");
    if (!fileName.isEmpty())  {
           if (QFileInfo(fileName).suffix().isEmpty())
               fileName.append(".pdf");
           QPrinter printer(QPrinter::HighResolution);
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setOutputFileName(fileName);


           ui->textEdit->document()->print(&printer);

       }
}

void MainWindow::on_dial_valueChanged(int value)
{

        ui->textEdit->insertPlainText("  "+QString::number(ui->dial->value()));

}

void MainWindow::on_pushButton_2_clicked()
{
}

void MainWindow::on_pushButton_3_clicked()
{
    QPrinter printer;

    QPrintDialog* dialog = new QPrintDialog(&printer, this);
    if (dialog->exec() == QDialog::Accepted)
    {
    ui->textEdit->document()->print(&printer);
    }

}
