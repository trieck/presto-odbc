#pragma once

#include "Session.h"
#include "QueryResults.h"
#include "AtlHttpClient2.h"

class Statement;
typedef std::shared_ptr<Statement> StatementPtr;

///////////////////////////////////////////////////////////////////////////////
class Statement
{
public:
    Statement(const Session& session, const wstring & query);
    ~Statement();
    static StatementPtr makeStatement(const Session& session,
        const wstring & query);

    inline bool succeeded() const {
        return m_succeeded;
    }
private:
    wstring makeHeaders();
    void runQuery();
    void cancelQuery();

    CAtlHttpClient2 m_client;
    Session m_session;
    wstring m_query;
    QueryResults m_results;
    bool m_succeeded;
};

