#include "ast/NullableTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::NullableTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::NullableTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}