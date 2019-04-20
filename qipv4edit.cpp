/*****************************************************************************/
/* \file qipv4edit.cpp
 *
 * \brief  creates custom widget- subclass of QWidget for IPv4 Address.
 *
 * \author  Shreyas Joshi
 *
 * \copyright
 * The copyright in this material is owned by Shreyas Joshi.
 * It may not be reproduced, used, sold or in any other way exploited or
 * transferred to any third party without the prior written permission of author.
 *
 ******************************************************************************/
#include "qipv4edit.h"

/******************************************************************************/
/* \fn  QIPv4Edit
 *
 * \param none
 *
 * \return This is the constructor of QIPv4Edit;
 *
 * \brief - This creates the custom widget and it to the layout
 * It sets up the input mask to allow user to add IPv4 Address
 * It sets the validator
 * It connects the editing finish signal to its slot.
 *
 * \verbatim
 * \endverbatim
 *****************************************************************************/
QIPv4Edit::QIPv4Edit(QWidget *parent) : QWidget(parent)
{
    pLayout = new QHBoxLayout(this);
    pLayout->setMargin(0);
    pLineEditIPv4 = new QLineEdit(this);
    pLineEditIPv4->setInputMask( "000.000.000.000" );
    pIpValidator = new QIPv4AddressValidator(this);
    pLineEditIPv4->setValidator(pIpValidator);
    pLineEditIPv4->setCursorPosition(0);
    pLayout->addWidget(pLineEditIPv4);
    QObject::connect(pLineEditIPv4, SIGNAL(editingFinished()), this, SLOT(slotUpdateIpAddress()));
}

/******************************************************************************/
/* \fn  setIpv4Address
 *
 * \param ipv4address to set
 *
 * \return None
 *
 * \brief It sets the IPv4 address only if it is changed and then emits the signal.
 * \verbatim
 * \endverbatim
 *****************************************************************************/
void QIPv4Edit::setIpv4Address(QString &ipv4Address)
{
      if(ipv4Address != m_ip4Address)
      {
          m_ip4Address = ipv4Address;
          emit signalIp4AddressChanged();
      }
}

/******************************************************************************/
/* \fn  getIp4Address
 *
 * \param None
 *
 * \return current IPv4Address
 *
 * \brief This is a getter function with QProperty read to get the ipv4Address.
 * \verbatim
 * \endverbatim
 *****************************************************************************/
QString QIPv4Edit::getIp4Address() const
{
   return m_ip4Address;
}

/******************************************************************************/
/* \fn  slotUpdateIpAddress
 *
 * \param ipv4address to set
 *
 * \return None
 *
 * \brief This is invoked whenever the linedit has finished editing.
 * This removes the spaces from the user input and store ip adress in
 * XXXX.XXXX.XXXX.XXXX format where X are digits only by calling setIpv4Address
 *
 * \verbatim
 * \endverbatim
 *****************************************************************************/
void QIPv4Edit::slotUpdateIpAddress()
{
   QString ipv4Address;
   int index = 0;
   foreach(QChar octet, pLineEditIPv4->text() )
   {
       if(octet.isDigit() || octet == '.')
       {
           ipv4Address[index] = octet;
           index++;
       }
   }
   // setIP address
   setIpv4Address(ipv4Address);
}
