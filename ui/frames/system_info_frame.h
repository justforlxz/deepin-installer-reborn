// Copyright (c) 2016 Deepin Ltd. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef DEEPIN_INSTALLER_REBORN_UI_FRAMES_SYSTEM_INFO_FRAME_H
#define DEEPIN_INSTALLER_REBORN_UI_FRAMES_SYSTEM_INFO_FRAME_H

#include <QFrame>

namespace ui {

class NavButton;

class SystemInfoFrame : public QFrame {
  Q_OBJECT

 public:
  explicit SystemInfoFrame(QWidget* parent = nullptr);

 signals:
  void finished();

 private:
  void initConnections();
  void initUI();

  NavButton* next_button_ = nullptr;

 private slots:
  // Validate form content.
  void onNextButtonClicked();
};

}  // namespace ui

#endif  // DEEPIN_INSTALLER_REBORN_UI_FRAMES_SYSTEM_INFO_FRAME_H
