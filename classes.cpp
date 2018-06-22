// To be inherited by variable and terminal
#include "classes.h"


struct Symbol
{
  virtual void print() = 0;
};


struct Variable: Symbol
{
  void print(); //prints all constituent variables
};


struct Terminal: Symbol
{
  void print();
};


class Rule
{
public:
  Rule();
private:
  Variable leftSide;
  Variable rightSide;
};


// A context-free grammar class
class CFG
{
public:
  CFG();
  void addRule(Rule r);
  void reduceToCNF(); //called every time a new rule is added
  void generateLanguage();  //generates all possible languages of the grammar. Stops after a set point if infinite.


private:
 vector<Variable> variables;
 vector<Terminal> terminals;
 vector<Rule> rules;
 Variable start;
};
