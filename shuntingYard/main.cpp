#include <iostream>
#include "Node.h"
#include <cstring>
#include <cctype>

using namespace std;

struct Stack
{
  Node* top = NULL;

  //Push a new node onto the stack
  void push(Node* newNode)
  {
    newNode->setNext(top);
    top = newNode;
  }

  //Pop and return the top node from the stack
  Node* pop()
  {
    if(top == NULL)
      return NULL;
    Node* temp = top;
    top = top->getNext();
    return temp;
  }

  //Return the top node without removing it
  Node* peek()
  {
    return top;
  }

  //Check if the stack is empty
  bool isEmpty()
  {
    return top == NULL;
  }
};

struct Queue
{
  Node* front = NULL;
  Node* back = NULL;

  //Add a new value to the back of the queue
  void enqueue(char value)
  {
    Node* newNode = new Node();
    newNode->setValue(value);
    if(back == NULL)
      {
	front = back = newNode;
	return;
      }
    back->setNext(newNode);
    back = newNode;
  }

  //Remove and return the front value form the queue
  char dequeue()
  {
    if(front == NULL)
      return '\0';
    char value = front->getValue();
    Node* temp = front;
    front = front->getNext();
    if(front == NULL)
      back = NULL;
    delete temp;
    return value;
  }

  //Check is the queue is empty
  bool isEmpty()
  {
    return front == NULL;
  }
};

//Function prototypes
int precedence(char op);
void shuntingYard(const char* infix, Queue & outputQueue);
Node* buildExpressionTree(Queue & postfixQueue);
void printInfix(Node* root);
void printPrefix(Node* root);
void printPostfix(Node* root);

int main()
{
  char infix [100];
  cout << "Enter an infix expression (use spaces between tokens):" << endl;
  cin.getline(infix, 100);

  Queue outputQueue;
  shuntingYard(infix, outputQueue);
  Node* root = buildExpressionTree(outputQueue);
  
  cout << "Postfix notation:" << endl;
  printPostfix(root);
  cout << endl;

  while(true)
    {
      char command[80];
      cout << "Enter command (INFIX/PREFIX/POSTFIX/QUIT):" << endl;
      cin.getline(command, 80);
      
      if(strcmp(command, "INFIX") == 0)
	{
	  cout << "Infix notation:" << endl;
	  printInfix(root);
	  cout << endl;
	}
      else if(strcmp(command, "PREFIX") == 0)
	{
	  cout << "Prefix notation:" << endl;
	  printPrefix(root);
	  cout << endl;
	}
      else if(strcmp(command, "POSTFIX") == 0)
	{
	  cout << "Postfix notation:" << endl;
	  printPostfix(root);
	  cout << endl;
	}
      else if(strcmp(command, "QUIT") == 0)
	{
	  exit(0);
	  break;
	}
    }
  return 0;
}

//Function to determine operator precedence
int precedence(char op)
{
  if(op == '+' || op == '-')
    return 1;
  if(op == '*' || op == '/')
    return 2;
  return 0;
}

//Convert infix to postfix using  the shunting yard algorithm
void shuntingYard(const char* infix, Queue & outputQueue)
{
  Stack opStack;
  char token[10];
  int index = 0;
  while (*infix)
    {
      //If digit, enqueue in to output
      if (isdigit(*infix)) 
	outputQueue.enqueue(*infix);

      //If opening parenthesis, push to operator stack
      else if (*infix == '(')
	{
	  Node* newNode = new Node();
	  newNode->setValue(*infix);
	  opStack.push(newNode);
	}

      //If closing parenthesis, pop until matching '('
      else if (*infix == ')')
	{
	  while (!opStack.isEmpty() && opStack.peek()->getValue() != '(') 
	    outputQueue.enqueue(opStack.pop()->getValue());
	  opStack.pop();
        }

      //If operator, pop higher precedence operators to output
      else if (*infix == '+' || *infix == '-' || *infix == '*' || *infix == '/')
	{
	  while (!opStack.isEmpty() && precedence(opStack.peek()->getValue()) >= precedence(*infix)) 
	    outputQueue.enqueue(opStack.pop()->getValue());
	  
	  Node* newNode = new Node();
	  newNode->setValue(*infix);
	  opStack.push(newNode);
	}
      infix++;
    }
  //Pop remaining operators to output
  while (!opStack.isEmpty()) 
    outputQueue.enqueue(opStack.pop()->getValue());
}

//Build expression tree from postfix queue
Node* buildExpressionTree(Queue & postfixQueue)
{
  Stack treeStack;

  while(!postfixQueue.isEmpty())
    {
      char token = postfixQueue.dequeue();
      Node* newNode = new Node();
      newNode->setValue(token);

      //If digit, push to tree stack
      if(isdigit(token))
	treeStack.push(newNode);
      else
	{
	  //If operator, pop two digits, create tree, and push back to stack
	  newNode->setRight(treeStack.pop());
	  newNode->setLeft(treeStack.pop());
	  treeStack.push(newNode);
	}
    }
  return treeStack.pop();
}

//Print the infix expression from the tree
void printInfix(Node* root)
{
  if (!root)
    return;

  if (!isdigit(root->getValue()))
    cout << "(";

  printInfix(root->getLeft());
  cout << root->getValue() << " ";
  printInfix(root->getRight());

  if (!isdigit(root->getValue()))
    cout << ")";
}

//Print the prefix expression from the tree
void printPrefix(Node* root)
{
  if (!root)
    return;

  cout << root->getValue() << " ";
  printPrefix(root->getLeft());
  printPrefix(root->getRight());
}

//Print the postfix expression from the tree
void printPostfix(Node* root)
{
  if (!root)
    return;

  printPostfix(root->getLeft());
  printPostfix(root->getRight());
  cout << root->getValue() << " ";
}
