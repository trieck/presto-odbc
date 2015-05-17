#include "stdafx.h"
#include "Statement.h"
#include "util.h"

///////////////////////////////////////////////////////////////////////////////
Statement::Statement(const Session& session, const wstring & query)
    : m_session(session), m_query(query), m_succeeded(false)
{
    runQuery();
}

///////////////////////////////////////////////////////////////////////////////
Statement::~Statement()
{
    cancelQuery();
}

//////////////////////////////////////////////////////////////////////////////
StatementPtr Statement::makeStatement(const Session& session,
    const wstring & query)
{
    return std::make_shared<Statement>(session, query);
}

//////////////////////////////////////////////////////////////////////////////
wstring Statement::makeHeaders()
{
    wstringstream os;
    os << L"x-presto-user: " << m_session.user << L'\n';
    os << L"x-presto-catalog: " << m_session.catalog << L'\n';
    os << L"x-presto-schema: " << m_session.schema << L'\n';
    os << L"x-presto-source:" << L"presto-odbc\n";
    return os.str();
}

///////////////////////////////////////////////////////////////////////////////
void Statement::runQuery()
{
    CAtlNavigateData data;
    data.SetMethod(L"POST");

    auto headers = makeHeaders();
    data.SetExtraHeaders(headers.c_str());
    data.SetSocketTimeout(DWORD(m_session.timeout * 1000));

    CStringA aQuery = WideToUTF8(m_query.c_str());
    data.SetPostData((LPBYTE)(LPCSTR)aQuery, (DWORD)aQuery.GetLength(), NULL);

    wstringstream url;
    url << L"http://" << m_session.endpoint << L"/v1/statement";

    m_succeeded = m_client.Navigate2(url.str().c_str(), &data);
    if (m_succeeded) {
        m_results.setResults(m_client.GetBody(), m_client.GetBodyLength());
    }
}

///////////////////////////////////////////////////////////////////////////////
void Statement::cancelQuery()
{
    if (m_results.m_nextURI.length() == 0)
        return;

    CAtlNavigateData data;
    data.SetMethod(L"DELETE");

    auto headers = makeHeaders();
    data.SetExtraHeaders(headers.c_str());
    data.SetSocketTimeout(DWORD(m_session.timeout * 1000));

    m_client.Navigate2(m_results.m_nextURI.c_str(), &data);
}