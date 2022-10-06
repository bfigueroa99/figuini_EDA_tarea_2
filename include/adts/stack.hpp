/*
 * stack.hpp
 *
 *  Created on: Aug 18, 2022
 *      Author: jsaavedr
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#include "/home/figue/Documents/Codigos/EDA/Tareas/tarea2/figuini_EDA_tarea_2/include/adts/node.hpp"

namespace eda {

class Stack {
private:
	Node* head;
public:
	Stack();
	void push(Node* node);
	void pop();
	Node* top();
	bool isEmpty();
	void clear();
	virtual ~Stack();
};

} /* namespace eda */

#endif /* STACK_HPP_ */
