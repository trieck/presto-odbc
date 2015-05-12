#pragma once

#include "rapidjson/document.h"

///////////////////////////////////////////////////////////////////////////////
class QueryResults
{
public:
    QueryResults();
    ~QueryResults();

    void setResults(const BYTE* pResponse, DWORD dwResponseLength);
private:
    wstring m_id, m_infoURI, m_partialCancelURI, m_nextURI;
    rapidjson::Value m_data;
};

