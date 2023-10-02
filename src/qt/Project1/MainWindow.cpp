#include "MainWindow.h"
#include "ui_MainWindow.h"
#include  <QDebug>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      mTasks()
{
    ui->setupUi(this);
    // connect(sender, &Sender::signalName, receiver, &Receiver::slotName);
    //connect(ui->btnAddTask, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);
    connect(ui->btnAddTask, &QPushButton::clicked, this, &MainWindow::addTask);
    updateStatus();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::addTask(){
    bool ok;
    QString name =QInputDialog::getText(this,
                                         tr("Add Task"),
                                         tr("Task Name"),
                                         QLineEdit::Normal,
                                         tr("Untitled task"),   &ok);
    if (ok &&!name.isEmpty()) {

    qDebug() << "Adding a new task";
     Task *task = new Task(name);
     connect(task, &Task::removed, this, &MainWindow::removeTask);
     connect(task, &Task::statusChanged, this, &MainWindow::taskStatusChanged);
     mTasks.append(task);
     ui->tasksLayout->addWidget(task);
     updateStatus();
    }
}
void MainWindow::removeTask(Task* task) {
  mTasks.removeOne( task);
  ui->tasksLayout->removeWidget(task);
  delete task;
  updateStatus();
}
void MainWindow::taskStatusChanged(Task* /*task*/) {
    updateStatus();
}
void MainWindow::updateStatus() {
    int completedCount = 0;
    for (auto t : mTasks) {
        if (t->isCompleted()) {
            completedCount++;
        }
    }
    int todoCount = mTasks.size() - completedCount;
    ui->lblStatus->setText(QString("Status: %1 todo / %2 completed") .arg(todoCount).arg(completedCount));
}
