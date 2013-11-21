#ifndef DATABASE_H
#define DATABASE_H

#include <string>   // string
#include <vector>   // vector
#include "Data.h"

typedef std::size_t id;
typedef std::vector<id> idList;

namespace Model {

struct DatabaseOperation {
    /*
        Steps:
        1. Add Category -> return category_id.
        2. Add Activity -> return activity_id.
        4. Add TagsList -> return vector of tag_id.
        3. Add Fact -> return fact_id.
        5. Add pair (fact_id,tag_id) to fact_tags table.
    */

    id addCategory(const Category& name);
    id addActivity(const Activity& name, id category_id);
    id addTag(const Tag& name);
    idList addTags(const TagsList& tags);
    id addFact(const Fact& fact);
    //id addFact(id activity_id, const Time& start,
    //              const Time& end, Description& desc);
    id addFactTag(const id fact_id, const idList& tag_idList);

    void addData(const Data& data);
};
} // namepspace Model

#endif  // DATABASE_H
