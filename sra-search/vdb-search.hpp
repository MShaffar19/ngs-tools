/*===========================================================================
*
*                            PUBLIC DOMAIN NOTICE
*               National Center for Biotechnology Information
*
*  This software/database is a "United States Government Work" under the
*  terms of the United States Copyright Act.  It was written as part of
*  the author's official duties as a United States Government employee and
*  thus cannot be copyrighted.  This software/database is freely available
*  to the public for use. The National Library of Medicine and the U.S.
*  Government have not placed any restriction on its use or reproduction.
*
*  Although all reasonable efforts have been taken to ensure the accuracy
*  and reliability of the software and data, the NLM and the U.S.
*  Government do not and cannot warrant the performance or results that
*  may be obtained by using this software or data. The NLM and the U.S.
*  Government disclaim all warranties, express or implied, including
*  warranties of performance, merchantability or fitness for any particular
*  purpose.
*
*  Please cite the author in any work or product based on this material.
*
* ===========================================================================
*
*/

#ifndef _hpp_vdb_search_
#define _hpp_vdb_search_

#include "sra-search.hpp"

#include <queue>

#include <ngs/ReadCollection.hpp>

struct Fgrep;

class VdbSearch : public SraSearch
{
public:
    typedef enum
    {
        FgrepDumb, 
        FgrepBoyerMoore,
        
        Default = FgrepDumb
    } Algorithm;

public:
    VdbSearch ( const std::string& query );
    virtual ~VdbSearch ();
    
    void SetAlgorithm ( Algorithm );
    bool SetAlgorithm ( const std :: string& );
    
    Algorithm GetAlgorithm () const { return m_algorithm; }
    
    virtual void AddAccession ( const std::string& ) throw ( ngs :: ErrorMsg );
    
    virtual bool NextMatch ( std::string& accession, std::string& fragmentId ) throw ( ngs :: ErrorMsg );
    
private:
    std::string         m_query;
    Algorithm           m_algorithm;
    
    class Search;
    
    std::queue < Search* > m_searches;
};

#endif
