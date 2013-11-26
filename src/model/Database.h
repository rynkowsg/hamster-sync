#ifndef DATABASE_H
#define DATABASE_H

#include <string>   // string
#include <vector>   // vector
#include "Data.h"
#include <cppdb/frontend.h> // cppdb::session


typedef unsigned int id;
typedef std::vector<id> idList;

namespace Model {

class Database {
public:
    /*
        Steps:
        1. Add Category -> return category_id.
        2. Add Activity -> return activity_id.
        4. Add TagsList -> return vector of tag_id.
        3. Add Fact -> return fact_id.
        5. Add pair (fact_id,tag_id) to fact_tags table.
    */
    // TODO: check it (explicit)
    explicit Database();
    // TODO: change to boost::filesystem::path
    Database(const std::string& p);
    ~Database();

    id getCategoryId(const std::string& search_name);
    id getActivityId(const std::string& search_name, id activity_id);
    id getTagId(const std::string& search_name);
    id addCategory(const std::string& name);
    id addActivity(const std::string& name, id category_id);
    id addTag(const std::string& name);

    //idList addTags(const TagsList& tags);
    //id addFact(const Fact& fact);
    //id addFact(id activity_id, const Time& start,
    //              const Time& end, Description& desc);
    //id addFactTag(const id fact_id, const idList& tag_idList);

    //void addData(const Data& data);

    void test();
  private:
    cppdb::session sql;
};
} // namespace Model

#endif  // DATABASE_H
