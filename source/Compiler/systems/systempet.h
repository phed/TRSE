#ifndef SYSTEMPET_H
#define SYSTEMPET_H

#include "systemmos6502.h"

class SystemPET : public SystemMOS6502
{
public:
    SystemPET(QSharedPointer<CIniFile> settings, QSharedPointer<CIniFile> proj);
    void DefaultValues() override;
    void InitSystemPreprocessors(QMap<QString, QString>& defines) override;;


};


#endif // SYSTEMPET_H
