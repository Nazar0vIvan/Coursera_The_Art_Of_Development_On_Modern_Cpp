#include "node.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
  return true;
}

template <typename T>
bool CompareTo(const T& lhs, const T& rhs, Comparison cmp) {
  switch (cmp) {
  case Comparison::Less:
    return lhs < rhs;
  case Comparison::LessOrEqual:
    return lhs <= rhs;
  case Comparison::Equal:
    return lhs == rhs;
  case Comparison::NotEqual:
    return lhs != rhs;
  case Comparison::Greater:
    return lhs > rhs;
  case Comparison::GreaterOrEqual:
    return lhs >= rhs;
  }
  return false;
}

DateComparisonNode::DateComparisonNode(Comparison comparison, const Date& value) : m_comparison(comparison) , m_value(value){}

bool DateComparisonNode::Evaluate(const Date& date, const string&) const {
  return CompareTo(date, m_value, m_comparison);
}

EventComparisonNode::EventComparisonNode(Comparison comparison, const string& value) : m_comparison(comparison), m_value(value){}

bool EventComparisonNode::Evaluate(const Date&, const string& event) const {
  return CompareTo(event, m_value, m_comparison);
}

LogicalOperationNode::LogicalOperationNode(LogicalOperation operation, shared_ptr<Node> left, shared_ptr<Node> right) :
  m_operation(operation),
  m_left(left),
  m_right(right)
{}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
  switch (m_operation) {
  case LogicalOperation::And:
    return m_left->Evaluate(date, event) && m_right->Evaluate(date, event);
  case LogicalOperation::Or:
    return m_left->Evaluate(date, event) || m_right->Evaluate(date, event);
  }
  return false;
}
