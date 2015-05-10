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
    rapidjson::Document m_doc;
};

