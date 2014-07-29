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
#include "wincedeployconfigurationfactory.h"

#include "remotewince_constants.h"

#include <projectexplorer/abi.h>
#include <projectexplorer/toolchain.h>
#include <projectexplorer/kitinformation.h>
#include <projectexplorer/project.h>
#include <projectexplorer/target.h>

#include <QCoreApplication>

using namespace ProjectExplorer;

namespace RemoteWinCE {
namespace Internal {
namespace {
QString genericWinCEDisplayName() {
    return QCoreApplication::translate("WinCE", "Deploy to WinCE Host");
}
} // anonymous namespace

WinCEDeployConfigurationFactory::WinCEDeployConfigurationFactory(QObject *parent)
    : DeployConfigurationFactory(parent)
{ setObjectName(QLatin1String("WinCEDeployConfiguration"));}

QList<Core::Id> WinCEDeployConfigurationFactory::availableCreationIds(Target *parent) const
{
    QList<Core::Id> ids;
    if (!parent->project()->supportsKit(parent->kit()))
        return ids;
    ProjectExplorer::ToolChain *tc
            = ProjectExplorer::ToolChainKitInformation::toolChain(parent->kit());
    if (!tc || tc->targetAbi().os() != ProjectExplorer::Abi::WindowsCEFlavor)
        return ids;
    const Core::Id devType = ProjectExplorer::DeviceTypeKitInformation::deviceTypeId(parent->kit());
    if (devType == Constants::WinCEOsType)
        ids << genericDeployConfigurationId();
    return ids;
}

QString WinCEDeployConfigurationFactory::displayNameForId(const Core::Id id) const
{
    if (id == genericDeployConfigurationId())
        return genericWinCEDisplayName();
    return QString();
}

bool WinCEDeployConfigurationFactory::canCreate(Target *parent, const Core::Id id) const
{
    return false; //availableCreationIds(parent).contains(id);
}


bool WinCEDeployConfigurationFactory::canRestore(Target *parent, const QVariantMap &map) const
{
    return false; //canCreate(parent, idFromMap(map));
}


Core::Id WinCEDeployConfigurationFactory::genericDeployConfigurationId()
{
    return "DeployToWinCE";
}

} // namespace Internal
} // namespace RemoteWinCE
