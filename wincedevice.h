/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#ifndef WINCEDEVICE_H
#define WINCEDEVICE_H

#include "remotewince_export.h"

#include <projectexplorer/devicesupport/idevice.h>

#include <QCoreApplication>


namespace RemoteWinCE {
namespace Internal { class WinCEDevicePrivate; }

class REMOTEWINCE_EXPORT WinCEDevice : public ProjectExplorer::IDevice
{
    Q_DECLARE_TR_FUNCTIONS(RemoteLinux::Internal::WinCEDevice)

public:
    typedef QSharedPointer<WinCEDevice> Ptr;
    typedef QSharedPointer<const WinCEDevice> ConstPtr;

    static Ptr create();
    static Ptr create(const QString &name, Core::Id type, MachineType machineType,
                      Origin origin = ManuallyAdded, Core::Id id = Core::Id());

    QString displayType() const;
    ProjectExplorer::IDeviceWidget *createWidget();
    QList<Core::Id> actionIds() const;
    QString displayNameForActionId(Core::Id actionId) const;
    void executeAction(Core::Id actionId, QWidget *parent);
    ProjectExplorer::IDevice::Ptr clone() const;

    bool canCreateProcess() const { return false; }
    //ProjectExplorer::DeviceProcess *createProcess(QObject *parent) const;
    bool canAutoDetectPorts() const { return false; }
    //ProjectExplorer::PortsGatheringMethod::Ptr portsGatheringMethod() const;
    bool canCreateProcessModel() const { return false; }
    //ProjectExplorer::DeviceProcessList *createProcessListModel(QObject *parent) const;
    bool hasDeviceTester() const { return false; }
    //ProjectExplorer::DeviceTester *createDeviceTester() const;
    ProjectExplorer::DeviceProcessSignalOperation::Ptr signalOperation() const;

protected:
    WinCEDevice() {}
    WinCEDevice(const QString &name, Core::Id type,
                             MachineType machineType, Origin origin, Core::Id id);
    WinCEDevice(const WinCEDevice &other);

private:
    WinCEDevice &operator=(const WinCEDevice &);
};

} // namespace RemoteWinCE

#endif // WINCEDEVICE_H
