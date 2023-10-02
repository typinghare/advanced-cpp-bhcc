#include "Task.h"
#include "ui_Task.h"
#include <QInputDialog>

Task::Task(const QString& name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name);
    connect(ui->btnEdit, &QPushButton::clicked, this, &Task::rename);
    connect(ui->btnRemove, &QPushButton::clicked, [this] {emit removed(this);});
    connect(ui->checkBox, &QCheckBox::toggled,this, &Task::checked);
}

Task::~Task()
{
    delete ui;
}

void Task::setName(const QString & name) {
    ui->checkBox->setText(name);
}
QString Task::name() const {
    return ui->checkBox->text();
}
bool Task::isCompleted() const {
    return ui->checkBox->isChecked();
}
void Task::rename() {
    bool ok;
    QString value=QInputDialog::getText(this,
                                        tr("Edit Task"),
                                        tr("Task Name"),
                                        QLineEdit::Normal,
                                        this->name(), &ok);
    if (ok && !value.isEmpty()) {
        setName(value);
    }
}
void Task::checked(bool checked) {
    QFont font(ui->checkBox->font());
    font.setStrikeOut(checked);
    ui->checkBox->setFont(font);
    emit statusChanged(this);
}
