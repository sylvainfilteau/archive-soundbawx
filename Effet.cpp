/*! \file Effet.cpp
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 1.0
 *
 * \brief Corp de la classe CEffet
 */
#include "effet.h"

CEffet::CEffet(CWAVE *son)
{
	m_son = son;
}

CEffet::~CEffet(void){}
