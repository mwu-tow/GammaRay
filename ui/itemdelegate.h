/*
 * This file is part of GammaRay, the Qt application inspection and
 * manipulation tool.
 *
 * Copyright (C) 2014-2016 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
 * Author: Filipe Azevedo <filipe.azevedo@kdab.com>
 *
 * Licensees holding valid commercial KDAB GammaRay licenses may use this file in
 * accordance with GammaRay Commercial License Agreement provided with the Software.
 *
 * Contact info@kdab.com if any conditions of this licensing are not clear to you.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef GAMMARAY_ITEMDELEGATE_H
#define GAMMARAY_ITEMDELEGATE_H

#include "gammaray_ui_export.h"

#include <QStyledItemDelegate>
#include <QSet>

namespace GammaRay {

/** @brief A simple delegate that avoid empty display role texts.
 */

class GAMMARAY_UI_EXPORT ItemDelegate : public QStyledItemDelegate
{
  Q_OBJECT

public:
  ItemDelegate(QObject *parent = 0);

  // You can put 2 placeholders for row/column using %r and %c
  QString placeholderText() const;
  void setPlaceholderText(const QString &placeholderText);

  // which columns do show place holders, default all (empty)
  QSet<int> placeholderColumns() const;
  void setPlaceholderColumns(const QSet<int> &placeholderColumns);

  void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;

private:
  QString defaultDisplayText(const QModelIndex &index) const;

private:
  QString m_placeholderText;
  QSet<int> m_placeholderColumns;
};

} // Namespace GammaRay

#endif // GAMMARAY_ITEMDELEGATE_H
