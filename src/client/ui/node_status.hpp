#ifndef NODE_STATUS_HPP
#define NODE_STATUS_HPP

#include <QGroupBox>
#include <QStandardItemModel>

namespace Ui {
class NodeStatus;
}

class NodeStatus : public QGroupBox
{
    Q_OBJECT

public:
    explicit NodeStatus(QWidget *parent = 0);
    ~NodeStatus();

    /**
     * @brief 解析参数xml字符串，并在表格中填充数据
    */
    void addContents(const std::string & strXML);

private:
    Ui::NodeStatus *ui;
    QStandardItemModel * n_FIBModel;
    QStandardItemModel * n_RIBModel;
    QStandardItemModel * n_CSModel;
};

#endif // NODE_STATUS_HPP
