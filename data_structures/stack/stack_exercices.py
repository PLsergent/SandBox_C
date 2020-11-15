from pythonds.basic import Stack

# Python3 code to Check for 
# balanced parentheses in an expression 
open_list = ["[","{","("] 
close_list = ["]","}",")"] 

# Function to check parentheses 
def check(input_string): 
	stack = [] 
	for i in input_string: 
		if i in open_list: 
			stack.append(i) # Put all open parentheses in a stack
		elif i in close_list: 
			pos = close_list.index(i) # Get the index of the closing character
            # Then check if the corresponding open character is at the top of the stack
			if ((open_list[pos] == stack[-1])): 
				stack.pop() # If so pop the last character of the stack
			else: 
				return "Unbalanced"
	if len(stack) == 0: 
		return "Balanced"
	else: 
		return "Unbalanced"

def infix_to_postfix(infix_expr):
    prec = {'*': 3, '/': 3, '+': 2, '-': 2, '(': 1}
    op_stack = Stack()
    postfix_list = []
    token_list = infix_expr.split()

    for token in token_list:
        if token in "abcdefghijklmnopqrstuvwxyz" or token in "0123456789":
            postfix_list.append(token)
        elif token == '(':
            op_stack.push(token)
        elif token == ')':
            top_token = op_stack.pop()
            while top_token != '(':
                postfix_list.append(top_token)
                top_token = op_stack.pop()
        else:
            while (not op_stack.isEmpty()) and \
               (prec[op_stack.peek()] >= prec[token]):
                  postfix_list.append(op_stack.pop())
            op_stack.push(token)

    while not op_stack.isEmpty():
        postfix_list.append(op_stack.pop())
    return " ".join(postfix_list)


def postfix_eval(postfix_expr):
    operand_stack = Stack()
    token_list = postfix_expr.split()

    for token in token_list:
        if token in "0123456789":
            operand_stack.push(int(token))
        else:
            operand2 = operand_stack.pop()
            operand1 = operand_stack.pop()
            result = do_math(token, operand1, operand2)
            operand_stack.push(result)
    return operand_stack.pop()

def do_math(op, op1, op2):
    if op == "*":
        return op1 * op2
    elif op == "/":
        return op1 / op2
    elif op == "+":
        return op1 + op2
    else:
        return op1 - op2
				

if __name__ == "__main__":
 
    string = "7 - { [ x * [ ( x + y) / (j – 3) ] + y ] / (4 – 2.5) }"
    print(string,"-", check(string)) 

    string = "[{}{})(]"
    print(string,"-", check(string)) 

    string = "((()"
    print(string,"-",check(string))

    exp1 = "8 * 2 + 3 * 4"
    exp2 = "( 3 + 4 ) * 7 - ( 9 - 2 ) * ( 1 + 2 )"
    post_exp1 = infix_to_postfix(exp1)
    post_exp2 = infix_to_postfix(exp2)
    
    print(post_exp1)
    print(post_exp2)

    print(postfix_eval(post_exp1))
    print(postfix_eval(post_exp2))
