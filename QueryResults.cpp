#include "stdafx.h"
#include "QueryResults.h"
#include "util.h"

///////////////////////////////////////////////////////////////////////////////
QueryResults::QueryResults()
{
}

///////////////////////////////////////////////////////////////////////////////
QueryResults::~QueryResults()
{
}

///////////////////////////////////////////////////////////////////////////////
void QueryResults::setResults(const BYTE* pResponse, DWORD dwResponseLength)
{
    using namespace rapidjson;

    CStringA response = CStringA((LPCSTR)pResponse, dwResponseLength);

    Document doc;
    doc.Parse(response);
    if (doc.HasParseError())
        return;

    m_id = UTF8toWide(doc["id"].GetString());
    m_infoURI = UTF8toWide(doc["infoUri"].GetString());

    if (doc.HasMember("partialCancelUri")) {
        m_partialCancelURI = UTF8toWide(doc["partialCancelUri"].GetString());
    }

    if (doc.HasMember("nextUri")) {
        m_nextURI = UTF8toWide(doc["nextUri"].GetString());
    }

    if (doc.HasMember("data")) {
        m_data = doc["data"];
    }
}