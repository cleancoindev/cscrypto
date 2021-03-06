#ifndef STORAGE_WIDGET_HPP
#define STORAGE_WIDGET_HPP

#include <QWidget>

class QCheckBox;
class QDialog;
class QLineEdit;
class QStatusBar;
class QSqlTableModel;
class QTableView;

namespace cscrypto {
namespace gui {

class StorageWidget : public QWidget {
    Q_OBJECT

public:
    StorageWidget(QStatusBar& sb, QSqlTableModel& keysModel, QWidget* parent = nullptr);

private:
    void setUpModel();
    void setUpView();
    void tuneLayouts();

    void importNewKey();
    void addKeyToDatabase();
    void removeKeyFromDatabase();
    void removeKey();
    QDialog* setUpImportKeyDialog();

    QStatusBar& statusBar_;
    QSqlTableModel& keysModel_;
    QTableView* keysTableView_;
    QLineEdit* importedKeyLineEdit_;
    QLineEdit* holderNameLineEdit_;
    QCheckBox* trustedKeyCheckBox_;
    QLineEdit* idToRemoveLineEdit_;
    int recordId_;
};

} // namespace gui
} // namespace cscrypto
#endif // STORAGE_WIDGET_HPP