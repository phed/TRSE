#ifndef FORMPAW_H
#define FORMPAW_H

#include <QWidget>
#include <QVector>
#include <QDir>
#include "trsedocument.h"
#include "source/LeLib/util/cinifile.h"
#include "source/LeLib/util/util.h"

namespace Ui {
class FormPaw;
}

class PawFile {
public:
    QString inFile, cFile, address, name;
    QString incCFile;
    int packedSize=0;

    PawFile(QString ifile, QString cfile, QString addr, QString n)
    {
        name = n;
        address = addr;
        cFile = cfile;
        inFile = ifile;

    }
    PawFile() {}
};


class PawThread : public QThread
{
    Q_OBJECT
public:
    CIniFile* m_pawData,* m_projectData,* m_iniFile;
    QVector<PawFile>* m_files;
    QString isExomizer3, output;

    PawThread(CIniFile* pawData, CIniFile* projectData, CIniFile* iniFile,  QVector<PawFile> *files) {
        m_pawData = pawData;
        m_projectData = projectData;
        m_iniFile = iniFile;
        m_files = files;
    }

    void CreateIncludefile();


protected:
    void run();

signals:
    void EmitTextUpdate();
};

class FormPaw : public TRSEDocument
{
    Q_OBJECT

    CIniFile m_pawData;
    QVector<PawFile> m_files;
    PawThread* pt = nullptr;
public:
    explicit FormPaw(QWidget *parent = nullptr);
    ~FormPaw();


    void FillFromIni();
    void FillToIni();

    void Save(QString filename) override;
    void Load(QString filename) override;
    void Build() override;
    void CreateIncludefile();

    void Destroy() override {}

private slots:
    void on_pushButton_clicked();

    void onTextUpdate();

    void on_pushButton_2_clicked();

    void Clear();
    void on_lePackedAddress_cursorPositionChanged(int arg1, int arg2);

    void on_leOutDir_cursorPositionChanged(int arg1, int arg2);

    void on_leOutfile_cursorPositionChanged(int arg1, int arg2);

    void on_tabData_cellChanged(int row, int column);

private:
    Ui::FormPaw *ui;
};

#endif // FORMPAW_H
