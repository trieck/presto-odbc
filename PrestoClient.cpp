#include "stdafx.h"
#include "PrestoClient.h"
#include "util.h"

///////////////////////////////////////////////////////////////////////////////
PrestoClient::PrestoClient()
{
}

///////////////////////////////////////////////////////////////////////////////
PrestoClient::~PrestoClient()
{
}

///////////////////////////////////////////////////////////////////////////////
wstring PrestoClient::makeHeaders(const Session& session)
{
    wstringstream os;
    os << L"x-presto-user: " << session.user << L'\n';
    os << L"x-presto-catalog: " << session.catalog << L'\n';
    os << L"x-presto-schema: " << session.schema << L'\n';
    os << L"x-presto-source:" << L"presto-odbc\n";
    return os.str();
}

///////////////////////////////////////////////////////////////////////////////
wstring PrestoClient::query(const Session& session, const wstring & query)
{
    CAtlNavigateData data;
    data.SetMethod(L"POST");

    wstring headers = makeHeaders(session);
    data.SetExtraHeaders(headers.c_str());
    data.SetSocketTimeout(DWORD(session.timeout * 1000));

    CStringA aQuery = CW2A(query.c_str(), CP_UTF8);
    data.SetPostData((LPBYTE)(LPCSTR)aQuery, (DWORD)aQuery.GetLength(), NULL);

    wstringstream url;
    url << L"http://" << session.endpoint << L"/v1/statement";

    bool response = m_client.Navigate(url.str().c_str(), &data);

    return wstring();
}