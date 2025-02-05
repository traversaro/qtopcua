// Copyright (C) 2015 basysKom GmbH, opensource@basyskom.com
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QOPCUALITERALOPERAND_H
#define QOPCUALITERALOPERAND_H

#include <QtOpcUa/qopcuatype.h>

#include <QtCore/qshareddata.h>

QT_BEGIN_NAMESPACE

// OPC UA 1.05 part 4, 7.7.4.3
class QOpcUaLiteralOperandData;
class Q_OPCUA_EXPORT QOpcUaLiteralOperand
{
public:
    QOpcUaLiteralOperand();
    QOpcUaLiteralOperand(const QOpcUaLiteralOperand &);
    QOpcUaLiteralOperand(const QVariant &value, QOpcUa::Types type = QOpcUa::Types::Undefined);
    QOpcUaLiteralOperand &operator=(const QOpcUaLiteralOperand &);
    operator QVariant() const;
    ~QOpcUaLiteralOperand();

    QVariant value() const;
    void setValue(const QVariant &value);

    QOpcUa::Types type() const;
    void setType(QOpcUa::Types type);

    friend Q_OPCUA_EXPORT bool operator==(const QOpcUaLiteralOperand &lhs, const QOpcUaLiteralOperand &rhs) noexcept;
    friend inline bool operator!=(const QOpcUaLiteralOperand &lhs, const QOpcUaLiteralOperand &rhs) noexcept
    {
        return !(lhs == rhs);
    }


private:
    QSharedDataPointer<QOpcUaLiteralOperandData> data;
};

QT_END_NAMESPACE

Q_DECLARE_METATYPE(QOpcUaLiteralOperand)

#endif // QOPCUALITERALOPERAND_H
