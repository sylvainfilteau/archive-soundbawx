/*! \file Delay.cpp
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 0.1
 *
 * \brief Corp de la classe CDelay
 */
#include "delay.h"

CDelay::CDelay(CWAVE *son) : CEffet(son){}

int CDelay::AppliquerDelais(int ms, float feedback, float mix)
{
	m_son->Backup();
	return 0;
}