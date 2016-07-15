// Copyright (c) 2016 Deepin Ltd. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/frames/install_progress_frame.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include "ui/frames/consts.h"
#include "ui/widgets/comment_label.h"
#include "ui/widgets/title_label.h"

namespace ui {

InstallProgressFrame::InstallProgressFrame(QWidget* parent)
    : QFrame(parent),
      state_(State::InProcess) {
  this->setObjectName(QStringLiteral("install_progress_frame"));

  this->initUI();
  this->initConnections();
}

void InstallProgressFrame::initConnections() {

}

void InstallProgressFrame::initUI() {
  TitleLabel* title_label = new TitleLabel(tr("Installing"));
  QHBoxLayout* title_layout = new QHBoxLayout();
  title_layout->addWidget(title_label);

  CommentLabel* comment_label = new CommentLabel(
      tr("You will be experiencing the incredible pleasant of deepin after "
         "the time for just a cup of coffee"));
  QHBoxLayout* comment_layout = new QHBoxLayout();
  comment_layout->addWidget(comment_label);

  QVBoxLayout* layout = new QVBoxLayout();
  layout->setSpacing(kMainLayoutSpacing);
  layout->addStretch();
  layout->addLayout(title_layout);
  layout->addLayout(comment_layout);
  layout->addStretch();

  this->setLayout(layout);
}

}  // namespace ui