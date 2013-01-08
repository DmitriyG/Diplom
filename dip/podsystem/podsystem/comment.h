#ifndef COMMENT_H
#define COMMENT_H
#include <QDialog>
#include "ui_comment.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

class Comment : public QDialog, public Ui::Dialog
{
    Q_OBJECT
public:
    Comment (QWidget *parent = 0);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};
#endif
