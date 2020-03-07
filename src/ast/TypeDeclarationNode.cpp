#include "ast/TypeDeclarationNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::TypeDeclarationNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::TypeDeclarationNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
