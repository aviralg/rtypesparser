#ifndef R_TYPE_AST_NODE_GROUP_TYPE_H
#define R_TYPE_AST_NODE_GROUP_TYPE_H

#include "CompositeType.h"
#include <memory>

namespace rtype::ast::node {

class GroupType final: public CompositeType {
  public:
    explicit GroupType(std::unique_ptr<Type> inner_type)
        : CompositeType(), inner_type_(std::move(inner_type)) {
    }

    ~GroupType() {
    }

    void accept(rtype::ast::visitor::Visitor& visitor) const override final;

    const rtype::ast::node::Type& get_inner_type() const {
        return *inner_type_.get();
    }

  private:
    std::unique_ptr<Type> inner_type_;
};

using GroupTypePtr = GroupType*;
using GroupTypeUPtr = std::unique_ptr<GroupType>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_GROUP_TYPE_H */
