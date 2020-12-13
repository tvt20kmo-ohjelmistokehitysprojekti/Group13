#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <QWidget>

namespace Ui {
class transactions;
}

class transactions : public QWidget
{
    Q_OBJECT

public:
    explicit transactions(QWidget *parent = nullptr);
    ~transactions();

private:
    Ui::transactions *ui;
};

#endif // TRANSACTIONS_H
