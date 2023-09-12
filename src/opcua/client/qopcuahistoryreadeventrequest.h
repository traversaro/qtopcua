// Copyright (C) 2023 basysKom GmbH, opensource@basyskom.com
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QHISTORYREADEVENTREQUEST_H
#define QHISTORYREADEVENTREQUEST_H

#include <QtCore/qobject.h>
#include <QtCore/qdatetime.h>
#include <QtCore/qshareddata.h>

#include <QtOpcUa/qopcuareaditem.h>
#include <QtOpcUa/qopcuahistorydata.h>

#include <QtOpcUa/qopcuaglobal.h>
#include <QtOpcUa/QOpcUaMonitoringParameters>

QT_BEGIN_NAMESPACE

class QOpcUaHistoryReadEventRequestData;
QT_DECLARE_QSDP_SPECIALIZATION_DTOR_WITH_EXPORT(QOpcUaHistoryReadEventRequestData, Q_OPCUA_EXPORT)
class QOpcUaHistoryReadEventRequest
{
public:
    Q_OPCUA_EXPORT QOpcUaHistoryReadEventRequest();
    Q_OPCUA_EXPORT explicit QOpcUaHistoryReadEventRequest(const QList<QOpcUaReadItem> &nodesToRead,
                                                          const QDateTime &startTimestamp,
                                                          const QDateTime &endTimestamp,
                                                          const QOpcUaMonitoringParameters::EventFilter &filter,
                                                          quint32 numValuesPerNode = 0);

    Q_OPCUA_EXPORT QOpcUaHistoryReadEventRequest(const QOpcUaHistoryReadEventRequest &other);
    QOpcUaHistoryReadEventRequest(QOpcUaHistoryReadEventRequest &&other) noexcept = default;
    QT_MOVE_ASSIGNMENT_OPERATOR_IMPL_VIA_PURE_SWAP(QOpcUaHistoryReadEventRequest)
    Q_OPCUA_EXPORT QOpcUaHistoryReadEventRequest &operator=(const QOpcUaHistoryReadEventRequest &other);
    Q_OPCUA_EXPORT ~QOpcUaHistoryReadEventRequest();

    void swap(QOpcUaHistoryReadEventRequest &other) noexcept
    { data.swap(other.data); }

    Q_OPCUA_EXPORT QDateTime startTimestamp() const;
    Q_OPCUA_EXPORT void setStartTimestamp(const QDateTime &startTimestamp);

    Q_OPCUA_EXPORT QDateTime endTimestamp() const;
    Q_OPCUA_EXPORT void setEndTimestamp(const QDateTime &endTimestamp);

    Q_OPCUA_EXPORT quint32 numValuesPerNode() const;
    Q_OPCUA_EXPORT void setNumValuesPerNode(quint32 numValuesPerNode);

    Q_OPCUA_EXPORT QOpcUaMonitoringParameters::EventFilter filter() const;
    Q_OPCUA_EXPORT void setFilter(const QOpcUaMonitoringParameters::EventFilter &filter);

    Q_OPCUA_EXPORT QList<QOpcUaReadItem> nodesToRead() const;
    Q_OPCUA_EXPORT void setNodesToRead(const QList<QOpcUaReadItem> &nodesToRead);

    Q_OPCUA_EXPORT void addNodeToRead(const QOpcUaReadItem &nodeToRead);

    friend Q_OPCUA_EXPORT bool operator==(const QOpcUaHistoryReadEventRequest &lhs,
                                                         const QOpcUaHistoryReadEventRequest &rhs) noexcept;
    friend inline bool operator!=(const QOpcUaHistoryReadEventRequest &lhs,
                                  const QOpcUaHistoryReadEventRequest &rhs) noexcept
    {
        return !(lhs == rhs);
    }

private:
    QSharedDataPointer<QOpcUaHistoryReadEventRequestData> data;
};

Q_DECLARE_SHARED(QOpcUaHistoryReadEventRequest)

QT_END_NAMESPACE

Q_DECLARE_METATYPE(QOpcUaHistoryReadEventRequest)

#endif // QHISTORYREADEVENTREQUEST_H
