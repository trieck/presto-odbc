#include "stdafx.h"
#include "OutputBuffer.h"

///////////////////////////////////////////////////////////////////////////
OutputBuffer::OutputBuffer(SQLPOINTER buffer, SQLSMALLINT maxLengthBytes,
    SQLSMALLINT* pLengthBytes)
{
    m_buffer = (SQLWCHAR*)buffer;
    m_maxLengthBytes = maxLengthBytes;
    m_pLengthBytes = pLengthBytes;
    if (m_pLengthBytes) {
        *m_pLengthBytes = 0;
    }
}

///////////////////////////////////////////////////////////////////////////
OutputBuffer::~OutputBuffer()
{
}

///////////////////////////////////////////////////////////////////////////
void OutputBuffer::copy(LPCWSTR szValue)
{
    size_t copied = min(wcslen(szValue), m_maxLengthBytes / 2 - 1);

    memcpy(m_buffer, szValue, copied * sizeof(wchar_t));
    m_buffer[copied] = L'\0';

    *m_pLengthBytes = (SQLSMALLINT)copied * sizeof(wchar_t);
}