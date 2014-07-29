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

#include "winceplugin.h"

//#include "embeddedlinuxqtversionfactory.h"
#include "wincedeviceconfigurationfactory.h"
//#include "genericremotelinuxdeploystepfactory.h"
#include "wincedeployconfigurationfactory.h"
//#include "remotelinuxrunconfigurationfactory.h"
//#include "remotelinuxruncontrolfactory.h"

#include <QtPlugin>

namespace RemoteWinCE {
namespace Internal {

WinCEPlugin::WinCEPlugin()
{
    setObjectName(QLatin1String("WinCEPlugin"));
}

bool WinCEPlugin::initialize(const QStringList &arguments,
    QString *errorMessage)
{
    Q_UNUSED(arguments)
    Q_UNUSED(errorMessage)

   //Q_ASSERT(0);
    addObject(this);
    addAutoReleasedObject(new WinCEDeviceConfigurationFactory);
//    addAutoReleasedObject(new RemoteLinuxRunControlFactory);
    addAutoReleasedObject(new WinCEDeployConfigurationFactory);
//    addAutoReleasedObject(new GenericRemoteLinuxDeployStepFactory);

//    addAutoReleasedObject(new EmbeddedLinuxQtVersionFactory);

    return true;
}

WinCEPlugin::~WinCEPlugin()
{
    removeObject(this);
}

void WinCEPlugin::extensionsInitialized()
{
}

} // namespace Internal
} // namespace RemoteWinCE

Q_EXPORT_PLUGIN(RemoteWinCE::Internal::WinCEPlugin)
