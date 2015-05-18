#pragma once

///////////////////////////////////////////////////////////////////////////
class OutputBuffer
{
public:
    OutputBuffer(SQLPOINTER buffer, SQLINTEGER maxLengthBytes, 
        SQLINTEGER* pLengthBytes);
    OutputBuffer(SQLPOINTER buffer, SQLSMALLINT maxLengthBytes,
        SQLSMALLINT* pLengthBytes);
    OutputBuffer(SQLWCHAR* buffer, SQLINTEGER maxLengthBytes,
        SQLINTEGER* pLengthBytes);
    ~OutputBuffer();
    
    void copy(LPCWSTR szValue);
private:
    void OutputBuffer::Initialize(SQLWCHAR* buffer, 
        SQLINTEGER maxLengthBytes, SQLINTEGER* pLengthBytes);
    SQLWCHAR *m_buffer;
    SQLINTEGER m_maxLengthBytes;
    SQLINTEGER* m_pLengthBytes;
};

