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

#include "wincedeviceconfigurationwizardpages.h"
#include "ui_winceconfigurationwizardsetuppage.h"

#include <projectexplorer/devicesupport/idevice.h>

namespace RemoteWinCE {
namespace Internal {

class WinCEDeviceConfigurationWizardSetupPagePrivate
{
public:
    Ui::WinCEDeviceConfigurationWizardSetupPage ui;
};

class WinCEDeviceConfigurationWizardFinalPagePrivate
{
public:
    QLabel infoLabel;
};

} // namespace Internal

using namespace Utils;

WinCEDeviceConfigurationWizardSetupPage::WinCEDeviceConfigurationWizardSetupPage(QWidget *parent) :
    QWizardPage(parent), d(new Internal::WinCEDeviceConfigurationWizardSetupPagePrivate)
{
    d->ui.setupUi(this);
    setTitle(tr("Connection"));
    setSubTitle(QLatin1String(" ")); // For Qt bug (background color)

    connect(d->ui.nameLineEdit, SIGNAL(textChanged(QString)), SIGNAL(completeChanged()));
    connect(d->ui.hostNameLineEdit, SIGNAL(textChanged(QString)), SIGNAL(completeChanged()));
}

WinCEDeviceConfigurationWizardSetupPage::~WinCEDeviceConfigurationWizardSetupPage()
{
    delete d;
}

void WinCEDeviceConfigurationWizardSetupPage::initializePage()
{
    d->ui.nameLineEdit->setText(tr("WinCE Device"));
    d->ui.hostNameLineEdit->setText(QString());
}

bool WinCEDeviceConfigurationWizardSetupPage::isComplete() const
{
    return !configurationName().isEmpty() && !hostName().isEmpty();
}

QString WinCEDeviceConfigurationWizardSetupPage::configurationName() const
{
    return d->ui.nameLineEdit->text().trimmed();
}

QString WinCEDeviceConfigurationWizardSetupPage::hostName() const
{
    return d->ui.hostNameLineEdit->text().trimmed();
}


WinCEDeviceConfigurationWizardFinalPage::WinCEDeviceConfigurationWizardFinalPage(QWidget *parent)
    : QWizardPage(parent), d(new Internal::WinCEDeviceConfigurationWizardFinalPagePrivate)
{
    setTitle(tr("Summary"));
    setSubTitle(QLatin1String(" ")); // For Qt bug (background color)
    d->infoLabel.setWordWrap(true);
    QVBoxLayout * const layout = new QVBoxLayout(this);
    layout->addWidget(&d->infoLabel);
}

WinCEDeviceConfigurationWizardFinalPage::~WinCEDeviceConfigurationWizardFinalPage()
{
    delete d;
}

void WinCEDeviceConfigurationWizardFinalPage::initializePage()
{
    d->infoLabel.setText(infoText());
}

QString WinCEDeviceConfigurationWizardFinalPage::infoText() const
{
    return tr("The new device configuration will now be created.\n"
        "In addition, device connectivity will be tested.");
}

} // namespace RemoteWinCE
