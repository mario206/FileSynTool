#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
class QFileSystemWatcher;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void init();
public slots:
    void onWatchEditChanged();
    void onCompareEditChanged();
    void onAutoSynChanged(int);
    void onMannualSynClicked();
    void onDirectoryChanged(const QString & path);
    void onFileChanged(const QString & path);
    void timeOut();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
private:
    bool click = false;
    QFileSystemWatcher* watcher;
    QStringList watchList;
    QString compareFolder;
    void setTimer();
    void lastSynTimeNotify();
    void lastSynFileNotify(const QString& fileName);
    void startCopyDirectory(QString& path);
    void startCopyFile(QString& path);

private:
    bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);

private:
    QVector<QString> fileQueue;
    QVector<QString> directoryQueue;
    QTimer* timer;
};

#endif // MAINWINDOW_H
