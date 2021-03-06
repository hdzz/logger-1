﻿/*
 * logger_mgt.cpp
 *
 *  Created on: 2013年12月14日
 *      Author: jimm
 */

#include "logger_mgt.h"

LOGGER_NAMESPACE_BEGIN

void CLoggerMgt::RegistLogger(const char *strLoggerName, CLoggerWriter *pLogger)
{
	m_stLoggerMgt[string(strLoggerName)] = pLogger;
}

CLoggerWriter *CLoggerMgt::GetLogger(const char *strLoggerName)
{
	CLoggerWriter *pLogger = NULL;
	if(strLoggerName == NULL)
	{
		return NULL;
	}

	LoggerMap::iterator it = m_stLoggerMgt.find(string(strLoggerName));
	if(it != m_stLoggerMgt.end())
	{
		pLogger = it->second;
	}
	else
	{
		pLogger = new CLoggerWriter(strLoggerName);
		RegistLogger(strLoggerName, pLogger);
	}

	return pLogger;
}

LoggerMap::iterator CLoggerMgt::GetBeginIterator()
{
	return m_stLoggerMgt.begin();
}

LoggerMap::iterator CLoggerMgt::GetEndIterator()
{
	return m_stLoggerMgt.end();
}

LOGGER_NAMESPACE_END
