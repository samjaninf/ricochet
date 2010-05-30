/* TorIM - http://gitorious.org/torim
 * Copyright (C) 2010, John Brooks <special@dereferenced.net>
 *
 * TorIM is free software: you can redistribute it and/or modify
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
 * along with TorIM. If not, see http://www.gnu.org/licenses/
 */

#ifndef NICKNAMEVALIDATOR_H
#define NICKNAMEVALIDATOR_H

#include <QValidator>

class QWidget;
class ContactUser;

class NicknameValidator : public QValidator
{
    Q_OBJECT
    Q_DISABLE_COPY(NicknameValidator)

public:
    explicit NicknameValidator(QObject *parent = 0);

    void setWidget(QWidget *widget);
    void setValidateUnique(bool unique, ContactUser *exception = 0);

    virtual State validate(QString &text, int &pos) const;

private:
    QWidget *m_widget;
    ContactUser *m_uniqueException;
    bool m_validateUnique;

    void showMessage(const QString &message) const;
};

#endif // NICKNAMEVALIDATOR_H
