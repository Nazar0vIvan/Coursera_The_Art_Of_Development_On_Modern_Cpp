#pragma once

#include <string>
#include <memory>

#include "date.h"

using namespace std;

struct Node {
  virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

struct EmptyNode : public Node {
  bool Evaluate(const Date& date, const string& event) const override;
};

enum class Comparison {
  Less,
  LessOrEqual,
  Equal,
  NotEqual,
  Greater,
  GreaterOrEqual,
};

class DateComparisonNode : public Node {
public:
  DateComparisonNode(Comparison comparison, const Date& value);
  bool Evaluate(const Date& date, const string& event) const override;

private:
  Comparison m_comparison;
  Date m_value;
};

class EventComparisonNode : public Node {
public:
  EventComparisonNode(Comparison comparison, const string& value);
  bool Evaluate(const Date& date, const string& event) const override;

private:
  Comparison m_comparison;
  string m_value;
};

enum class LogicalOperation {
  And,
  Or,
};

class LogicalOperationNode : public Node {
public:
  LogicalOperationNode(LogicalOperation operation, shared_ptr<Node> left, shared_ptr<Node> right);
  bool Evaluate(const Date& date, const string& event) const override;

private:
  LogicalOperation m_operation;
  shared_ptr<Node> m_left, m_right;
};

void TestDateComparisonNode();
void TestEventComparisonNode();
void TestLogicalOperationNode();
