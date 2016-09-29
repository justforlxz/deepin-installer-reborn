// Copyright (c) 2016 Deepin Ltd. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef DEEPIN_INSTALLER_REBORN_PARTMAN_OS_PROBER_H
#define DEEPIN_INSTALLER_REBORN_PARTMAN_OS_PROBER_H

#include <QHash>
#include <QString>

#include "partman/structs.h"

namespace partman {

typedef QHash<QString, OsType> OsTypeItems;

// Scan system wide os information with `os-prober`.
OsTypeItems GetOsTypeItems();

}  // namespace partman

#endif  // DEEPIN_INSTALLER_REBORN_PARTMAN_OS_PROBER_H