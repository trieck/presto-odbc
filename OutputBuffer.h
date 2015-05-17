#pragma once

///////////////////////////////////////////////////////////////////////////
class OutputBuffer
{
public:
    OutputBuffer(SQLPOINTER buffer, SQLSMALLINT maxLengthBytes, 
        SQLSMALLINT* pLengthBytes);
    ~OutputBuffer();
    
    void copy(LPCWSTR szValue);
private:
    SQLWCHAR *m_buffer;
    SQLSMALLINT m_maxLengthBytes;
    SQLSMALLINT* m_pLengthBytes;
};

