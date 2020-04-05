#include "Parser.h"

void printAST(AST *tree) //hello.c
{
	DataTypeAST *data_type = static_cast<DataTypeAST*>(tree); //int
	cout<<"-|"<<data_type->definition<<endl;

	MainFunctionAST *main_func = static_cast<MainFunctionAST*>(data_type->identificator); //main
	cout<<"---|"<<main_func->definition<<endl;

	MainFunctionArgsAST *main_func_args = static_cast<MainFunctionArgsAST*>(main_func->args); //main args
	cout<<"-------|"<<main_func_args->definition<<endl;

	data_type = static_cast<DataTypeAST*>(main_func_args->args[0]); //int
	cout<<"-----------|"<<data_type->definition<<endl;

	SymbolIdAST *var = static_cast<SymbolIdAST*>(data_type->identificator); //argc
	cout<<"---------------|"<<var->definition<<endl;

	ConstAST *key_word_const = static_cast<ConstAST*>(main_func_args->args[1]); //const
	cout<<"-----------|"<<key_word_const->definition<<endl;

	data_type = static_cast<DataTypeAST*>(key_word_const->identificator); //char
	cout<<"---------------|"<<data_type->definition<<endl;

	PointerAST *ptr = static_cast<PointerAST*>(data_type->identificator); //*
	cout<<"-------------------|"<<ptr->definition<<endl;

	ptr = static_cast<PointerAST*>(ptr->identificator); //*
	cout<<"-----------------------|"<<ptr->definition<<endl;

	var = static_cast<SymbolIdAST*>(ptr->identificator); //argv
	cout<<"---------------------------|"<<var->definition<<endl;

	MainFunctionBodyAST *main_func_body = static_cast<MainFunctionBodyAST*>(main_func->body); //main body
	cout<<"-------|"<<main_func_body->definition<<endl;

	AssignmentAST *assignment = static_cast<AssignmentAST*>(main_func_body->blocks[0]); //=
	cout<<"-----------|"<<assignment->definition<<endl;

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int
	cout<<"---------------|"<<data_type->definition<<endl;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //a
	cout<<"-------------------|"<<var->definition<<endl;

	BinOperationAST *bin_op = static_cast<BinOperationAST*>(assignment->r_operand); // /
	cout<<"---------------|"<<bin_op->definition<<endl;

	DigitIdAST *val = static_cast<DigitIdAST*>(bin_op->l_operand); //10
	cout<<"-------------------|"<<val->definition<<endl;

	val = static_cast<DigitIdAST*>(bin_op->r_operand); //2
	cout<<"-------------------|"<<val->definition<<endl;

	IfAST *key_word_if = static_cast<IfAST*>(main_func_body->blocks[1]); //if
	cout<<"-----------|"<<key_word_if->definition<<endl;

	IfConditionAST *if_cond = static_cast<IfConditionAST*>(key_word_if->condition); //if condition
	cout<<"---------------|"<<if_cond->definition<<endl;

	bin_op = static_cast<BinOperationAST*>(if_cond->blocks[0]); //==
	cout<<"-------------------|"<<bin_op->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op->l_operand); //a
	cout<<"-----------------------|"<<var->definition<<endl;

	val = static_cast<DigitIdAST*>(bin_op->r_operand); //5
	cout<<"-----------------------|"<<val->definition<<endl;

	IfBodyAST *if_body = static_cast<IfBodyAST*>(key_word_if->body); //if body
	cout<<"---------------|"<<if_body->definition<<endl;

	assignment = static_cast<AssignmentAST*>(if_body->blocks[0]); //=
	cout<<"-------------------|"<<assignment->definition<<endl;

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //double
	cout<<"-----------------------|"<<data_type->definition<<endl;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //b
	cout<<"---------------------------|"<<var->definition<<endl;

	bin_op = static_cast<BinOperationAST*>(assignment->r_operand); // -
	cout<<"-----------------------|"<<bin_op->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op->l_operand); //a
	cout<<"---------------------------|"<<var->definition<<endl;

	val = static_cast<DigitIdAST*>(bin_op->r_operand); //2
	cout<<"---------------------------|"<<val->definition<<endl;

	WhileAST *key_word_while = static_cast<WhileAST*>(main_func_body->blocks[2]); //while
	cout<<"-----------|"<<key_word_while->definition<<endl;

	WhileConditionAST *while_cond = static_cast<WhileConditionAST*>(key_word_while->condition); //while condition
	cout<<"---------------|"<<while_cond->definition<<endl;

	bin_op = static_cast<BinOperationAST*>(while_cond->blocks[0]); //==
	cout<<"-----------------------|"<<bin_op->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op->l_operand); //b
	cout<<"---------------------------|"<<var->definition<<endl;

	val = static_cast<DigitIdAST*>(bin_op->r_operand); //3
	cout<<"---------------------------|"<<val->definition<<endl;

	WhileBodyAST *while_body = static_cast<WhileBodyAST*>(key_word_while->body); //while body
	cout<<"---------------|"<<while_body->definition<<endl;

	data_type = static_cast<DataTypeAST*>(while_body->blocks[0]); //int
	cout<<"-------------------|"<<data_type->definition<<endl;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //a
	cout<<"-----------------------|"<<var->definition<<endl;

	key_word_if = static_cast<IfAST*>(while_body->blocks[1]); //if
	cout<<"-------------------|"<<key_word_if->definition<<endl;

	if_cond = static_cast<IfConditionAST*>(key_word_if->condition); //if condition
	cout<<"-----------------------|"<<if_cond->definition<<endl;

	bin_op = static_cast<BinOperationAST*>(if_cond->blocks[0]); //==
	cout<<"---------------------------|"<<bin_op->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op->l_operand); //a
	cout<<"-------------------------------|"<<val->definition<<endl;

	val = static_cast<DigitIdAST*>(bin_op->r_operand); //5
	cout<<"-------------------------------|"<<val->definition<<endl;

	if_body = static_cast<IfBodyAST*>(key_word_if->body); //if body
	cout<<"-----------------------|"<<if_body->definition<<endl;

	assignment = static_cast<AssignmentAST*>(if_body->blocks[0]); //=
	cout<<"---------------------------|"<<assignment->definition<<endl;

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //double
	cout<<"-------------------------------|"<<data_type->definition<<endl;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //b
	cout<<"-----------------------------------|"<<var->definition<<endl;

	bin_op = static_cast<BinOperationAST*>(assignment->r_operand); // -
	cout<<"-------------------------------|"<<bin_op->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op->l_operand); //a
	cout<<"----------------------------------|"<<var->definition<<endl;

	val = static_cast<DigitIdAST*>(bin_op->r_operand); //1
	cout<<"----------------------------------|"<<val->definition<<endl;

	ForAST *key_word_for = static_cast<ForAST*>(main_func_body->blocks[3]); //for
	cout<<"-----------|"<<key_word_for->definition<<endl;

	ForConditionAST *for_cond = static_cast<ForConditionAST*>(key_word_for->condition); //for condition
	cout<<"---------------|"<<for_cond->definition<<endl;

	assignment = static_cast<AssignmentAST*>(for_cond->blocks[0]); //=
	cout<<"-------------------|"<<assignment->definition<<endl;

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int
	cout<<"-----------------------|"<<data_type->definition<<endl;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //i
	cout<<"---------------------------|"<<var->definition<<endl;

	bin_op = static_cast<BinOperationAST*>(assignment->r_operand); // +
	cout<<"-----------------------|"<<bin_op->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op->l_operand); //b
	cout<<"---------------------------|"<<var->definition<<endl;

	val = static_cast<DigitIdAST*>(bin_op->r_operand); //1
	cout<<"---------------------------|"<<val->definition<<endl;

	bin_op = static_cast<BinOperationAST*>(for_cond->blocks[1]); //<
	cout<<"-------------------|"<<bin_op->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op->l_operand); //i
	cout<<"-----------------------|"<<var->definition<<endl;

	val = static_cast<DigitIdAST*>(bin_op->r_operand); //0
	cout<<"-----------------------|"<<val->definition<<endl;

	UnaryOperationAST *unary_op = static_cast<UnaryOperationAST*>(for_cond->blocks[2]); //++
	cout<<"-------------------|"<<unary_op->definition<<endl;

	var = static_cast<SymbolIdAST*>(unary_op->operand); //i
	cout<<"-----------------------|"<<var->definition<<endl;

	ForBodyAST *for_body = static_cast<ForBodyAST*>(key_word_for->body); //for body
	cout<<"---------------|"<<for_body->definition<<endl;

	assignment = static_cast<AssignmentAST*>(for_body->blocks[0]); //=
	cout<<"-------------------|"<<assignment->definition<<endl;

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int
	cout<<"-----------------------|"<<data_type->definition<<endl;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //c
	cout<<"---------------------------|"<<var->definition<<endl;

	var = static_cast<SymbolIdAST*>(assignment->r_operand); //b
	cout<<"-----------------------|"<<var->definition<<endl;

	ReturnAST *key_word_return = static_cast<ReturnAST*>(main_func_body->blocks[4]); //return
	cout<<"-----------|"<<key_word_return->definition<<endl;

	val = static_cast<DigitIdAST*>(key_word_return->identificator); //0
	cout<<"---------------|"<<val->definition<<endl;
}

void printAST1(AST *tree) //array_min.c
{
	DataTypeAST *data_type = static_cast<DataTypeAST*>(tree); //int
	cout<<"-|"<<data_type->definition<<endl;

	MainFunctionAST *main_func = static_cast<MainFunctionAST*>(data_type->identificator); //main
	cout<<"---|"<<main_func->definition<<endl;

	MainFunctionArgsAST *main_func_args = static_cast<MainFunctionArgsAST*>(main_func->args); //main args
	cout<<"-------|"<<main_func_args->definition<<endl;

	data_type = static_cast<DataTypeAST*>(main_func_args->args[0]); //int
	cout<<"-----------|"<<data_type->definition<<endl;

	SymbolIdAST *var = static_cast<SymbolIdAST*>(data_type->identificator); //argc
	cout<<"---------------|"<<var->definition<<endl;

	ConstAST *key_word_const = static_cast<ConstAST*>(main_func_args->args[1]); //const
	cout<<"-----------|"<<key_word_const->definition<<endl;

	data_type = static_cast<DataTypeAST*>(key_word_const->identificator); //char
	cout<<"---------------|"<<data_type->definition<<endl;

	PointerAST *ptr = static_cast<PointerAST*>(data_type->identificator); //*
	cout<<"-------------------|"<<ptr->definition<<endl;

	ptr = static_cast<PointerAST*>(ptr->identificator); //*
	cout<<"-----------------------|"<<ptr->definition<<endl;

	var = static_cast<SymbolIdAST*>(ptr->identificator); //argv
	cout<<"---------------------------|"<<var->definition<<endl;

	MainFunctionBodyAST *main_func_body = static_cast<MainFunctionBodyAST*>(main_func->body); //main body
	cout<<"-------|"<<main_func_body->definition<<endl;

	AssignmentAST *assignment = static_cast<AssignmentAST*>(main_func_body->blocks[0]); //=
	cout<<"-----------|"<<assignment->definition<<endl;

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int
	cout<<"---------------|"<<data_type->definition<<endl;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //N
	cout<<"-------------------|"<<var->definition<<endl;

	DigitIdAST *val = static_cast<DigitIdAST*>(assignment->r_operand); //10
	cout<<"---------------|"<<val->definition<<endl;

	assignment = static_cast<AssignmentAST*>(main_func_body->blocks[1]); //=
	cout<<"-----------|"<<assignment->definition<<endl;

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int
	cout<<"---------------|"<<data_type->definition<<endl;

	ArrayNameAST *arr_name = static_cast<ArrayNameAST*>(data_type->identificator); //arr[]
	cout<<"-------------------|"<<arr_name->definition<<endl;

	ArrayDataAST *arr_data = static_cast<ArrayDataAST*>(assignment->r_operand); //{...}

	for (int i = 0; i < 10; ++i) {
		val = static_cast<DigitIdAST*>(arr_data->blocks[i]); //1,2,3,4,5...
		cout<<"---------------|"<<val->definition<<endl;
	}

	assignment = static_cast<AssignmentAST*>(main_func_body->blocks[2]); //=
	cout<<"-----------|"<<assignment->definition<<endl;

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int
	cout<<"---------------|"<<data_type->definition<<endl;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //min
	cout<<"-------------------|"<<var->definition<<endl;

	arr_name = static_cast<ArrayNameAST*>(assignment->r_operand); //arr[]
	cout<<"---------------|"<<arr_name->definition<<endl;

	val = static_cast<DigitIdAST*>(arr_name->identificator); //0
	cout<<"-------------------|"<<val->definition<<endl;

	ForAST *key_word_for = static_cast<ForAST*>(main_func_body->blocks[3]); //for
	cout<<"-----------|"<<key_word_for->definition<<endl;

	ForConditionAST *for_cond = static_cast<ForConditionAST*>(key_word_for->condition); //for condition
	cout<<"---------------|"<<for_cond->definition<<endl;

	assignment = static_cast<AssignmentAST*>(for_cond->blocks[0]); //=
	cout<<"-------------------|"<<assignment->definition<<endl;

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int
	cout<<"-----------------------|"<<data_type->definition<<endl;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //i
	cout<<"---------------------------|"<<var->definition<<endl;

	val = static_cast<DigitIdAST*>(assignment->r_operand); // 1
	cout<<"-----------------------|"<<val->definition<<endl;

	BinOperationAST *bin_op = static_cast<BinOperationAST*>(for_cond->blocks[1]); //<
	cout<<"-------------------|"<<bin_op->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op->l_operand); //i
	cout<<"-----------------------|"<<var->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op->r_operand); //N
	cout<<"-----------------------|"<<var->definition<<endl;

	UnaryOperationAST *unaryOp = static_cast<UnaryOperationAST*>(for_cond->blocks[2]); //++
	cout<<"-------------------|"<<unaryOp->definition<<endl;

	var = static_cast<SymbolIdAST*>(unaryOp->operand); //i
	cout<<"-----------------------|"<<var->definition<<endl;

	ForBodyAST *for_body = static_cast<ForBodyAST*>(key_word_for->body); //for body
	cout<<"---------------|"<<for_body->definition<<endl;

	IfAST *key_word_if = static_cast<IfAST*>(for_body->blocks[0]); //if
	cout<<"-------------------|"<<key_word_if->definition<<endl;

	IfConditionAST *ifCond = static_cast<IfConditionAST*>(key_word_if->condition); //if condition
	cout<<"-----------------------|"<<ifCond->definition<<endl;

	bin_op = static_cast<BinOperationAST*>(ifCond->blocks[0]); //<
	cout<<"---------------------------|"<<bin_op->definition<<endl;

	arr_name = static_cast<ArrayNameAST*>(bin_op->l_operand); //arr[]
	cout<<"-------------------------------|"<<arr_name->definition<<endl;

	var = static_cast<SymbolIdAST*>(arr_name->identificator); //i
	cout<<"-----------------------------------|"<<var->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op->r_operand); //min
	cout<<"-------------------------------|"<<var->definition<<endl;

	IfConditionAST *ifBody = static_cast<IfConditionAST*>(key_word_if->body); //if body
	cout<<"-----------------------|"<<ifBody->definition<<endl;

	assignment = static_cast<AssignmentAST*>(ifBody->blocks[0]); //=
	cout<<"---------------------------|"<<assignment->definition<<endl;

	var = static_cast<SymbolIdAST*>(assignment->l_operand); //min
	cout<<"-------------------------------|"<<var->definition<<endl;

	arr_name = static_cast<ArrayNameAST*>(assignment->r_operand); //arr[]
	cout<<"-------------------------------|"<<arr_name->definition<<endl;

	var = static_cast<SymbolIdAST*>(arr_name->identificator); //i
	cout<<"-----------------------------------|"<<var->definition<<endl;

	PrintfAST *func_printf = static_cast<PrintfAST*>(main_func_body->blocks[4]); //printf
	cout<<"-----------|"<<func_printf->definition<<endl;

	StringLexemeAST *text = static_cast<StringLexemeAST*>(func_printf->params[0]); //"min: %d\n"
	cout<<"---------------|"<<text->definition<<endl;

	var = static_cast<SymbolIdAST*>(func_printf->params[1]); //min
	cout<<"---------------|"<<var->definition<<endl;

	ReturnAST *key_word_return = static_cast<ReturnAST*>(main_func_body->blocks[5]); //return
	cout<<"-----------|"<<key_word_return->definition<<endl;

	val = static_cast<DigitIdAST*>(key_word_return->identificator); //0
	cout<<"---------------|"<<val->definition<<endl;
}

void printAST2(AST *tree) //substr.c
{
	DataTypeAST *data_type = static_cast<DataTypeAST*>(tree); //int
	cout<<"-|"<<data_type->definition<<endl;

	MainFunctionAST *main_func = static_cast<MainFunctionAST*>(data_type->identificator); //main
	cout<<"---|"<<main_func->definition<<endl;

	MainFunctionArgsAST *main_func_args = static_cast<MainFunctionArgsAST*>(main_func->args); //main args
	cout<<"-------|"<<main_func_args->definition<<endl;

	data_type = static_cast<DataTypeAST*>(main_func_args->args[0]); //int
	cout<<"-----------|"<<data_type->definition<<endl;

	SymbolIdAST *var = static_cast<SymbolIdAST*>(data_type->identificator); //argc
	cout<<"---------------|"<<var->definition<<endl;

	ConstAST *key_word_const = static_cast<ConstAST*>(main_func_args->args[1]); //const
	cout<<"-----------|"<<key_word_const->definition<<endl;

	data_type = static_cast<DataTypeAST*>(key_word_const->identificator); //char
	cout<<"---------------|"<<data_type->definition<<endl;

	PointerAST *ptr = static_cast<PointerAST*>(data_type->identificator); //*
	cout<<"-------------------|"<<ptr->definition<<endl;

	ptr = static_cast<PointerAST*>(ptr->identificator); //*
	cout<<"-----------------------|"<<ptr->definition<<endl;

	var = static_cast<SymbolIdAST*>(ptr->identificator); //argv
	cout<<"---------------------------|"<<var->definition<<endl;

	MainFunctionBodyAST *main_func_body = static_cast<MainFunctionBodyAST*>(main_func->body); //main body
	cout<<"-------|"<<main_func_body->definition<<endl;

	AssignmentAST *assignment = static_cast<AssignmentAST*>(main_func_body->blocks[0]); //=
	cout<<"-----------|"<<assignment->definition<<endl;

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int
	cout<<"---------------|"<<data_type->definition<<endl;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //N
	cout<<"-------------------|"<<var->definition<<endl;

	DigitIdAST *val = static_cast<DigitIdAST*>(assignment->r_operand); //10
	cout<<"---------------|"<<val->definition<<endl;

	assignment = static_cast<AssignmentAST*>(main_func_body->blocks[1]); //=
	cout<<"-----------|"<<assignment->definition<<endl;

	var = static_cast<SymbolIdAST*>(assignment->l_operand); //token_size
	cout<<"---------------|"<<var->definition<<endl;

	val = static_cast<DigitIdAST*>(assignment->r_operand); //4
	cout<<"---------------|"<<val->definition<<endl;

	assignment = static_cast<AssignmentAST*>(main_func_body->blocks[2]); //=
	cout<<"-----------|"<<assignment->definition<<endl;

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //char
	cout<<"---------------|"<<data_type->definition<<endl;

	ArrayNameAST *arr_name = static_cast<ArrayNameAST*>(data_type->identificator); //s_str[]
	cout<<"-------------------|"<<arr_name->definition<<endl;

	StringLexemeAST *text = static_cast<StringLexemeAST*>(assignment->r_operand); //"AlexeyGenaEugeneAlexey"
	cout<<"-----------------------|"<<text->definition<<endl;

	assignment = static_cast<AssignmentAST*>(main_func_body->blocks[3]); //=
	cout<<"-----------|"<<assignment->definition<<endl;

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //char
	cout<<"---------------|"<<data_type->definition<<endl;

	arr_name = static_cast<ArrayNameAST*>(data_type->identificator); //token[]
	cout<<"-------------------|"<<arr_name->definition<<endl;

	text = static_cast<StringLexemeAST*>(assignment->r_operand); //"Gena"
	cout<<"-----------------------|"<<text->definition<<endl;

	assignment = static_cast<AssignmentAST*>(main_func_body->blocks[4]); //=
	cout<<"-----------|"<<assignment->definition<<endl;

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int
	cout<<"---------------|"<<data_type->definition<<endl;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //j
	cout<<"-------------------|"<<var->definition<<endl;

	val = static_cast<DigitIdAST*>(assignment->r_operand); //0
	cout<<"---------------|"<<val->definition<<endl;

	var = static_cast<SymbolIdAST*>(main_func_body->blocks[5]); //pos
	cout<<"-----------|"<<var->definition<<endl;

	ForAST *key_word_for = static_cast<ForAST*>(main_func_body->blocks[6]); //for
	cout<<"-----------|"<<key_word_for->definition<<endl;

	ForConditionAST *for_cond = static_cast<ForConditionAST*>(key_word_for->condition); //for condition
	cout<<"---------------|"<<for_cond->definition<<endl;

	assignment = static_cast<AssignmentAST*>(for_cond->blocks[0]); //=
	cout<<"-------------------|"<<assignment->definition<<endl;

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int
	cout<<"-----------------------|"<<data_type->definition<<endl;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //i
	cout<<"---------------------------|"<<var->definition<<endl;

	val = static_cast<DigitIdAST*>(assignment->r_operand); // 0
	cout<<"-----------------------|"<<val->definition<<endl;

	BinOperationAST *bin_op = static_cast<BinOperationAST*>(for_cond->blocks[1]); //<
	cout<<"-------------------|"<<bin_op->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op->l_operand); //i
	cout<<"-----------------------|"<<var->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op->r_operand); //N
	cout<<"-----------------------|"<<var->definition<<endl;

	UnaryOperationAST *unaryOp = static_cast<UnaryOperationAST*>(for_cond->blocks[2]); //++
	cout<<"-------------------|"<<unaryOp->definition<<endl;

	var = static_cast<SymbolIdAST*>(unaryOp->operand); //i
	cout<<"-----------------------|"<<var->definition<<endl;

	ForBodyAST *for_body = static_cast<ForBodyAST*>(key_word_for->body); //for body
	cout<<"---------------|"<<for_body->definition<<endl;

	IfAST *key_word_if = static_cast<IfAST*>(for_body->blocks[0]); //if
	cout<<"-------------------|"<<key_word_if->definition<<endl;

	IfConditionAST *ifCond = static_cast<IfConditionAST*>(key_word_if->condition); //if condition
	cout<<"-----------------------|"<<ifCond->definition<<endl;

	bin_op = static_cast<BinOperationAST*>(ifCond->blocks[0]); //==
	cout<<"---------------------------|"<<bin_op->definition<<endl;

	arr_name = static_cast<ArrayNameAST*>(bin_op->l_operand); //s_str[]
	cout<<"-------------------------------|"<<arr_name->definition<<endl;

	var = static_cast<SymbolIdAST*>(arr_name->identificator); //i
	cout<<"-----------------------------------|"<<var->definition<<endl;

	arr_name = static_cast<ArrayNameAST*>(bin_op->r_operand); //token[]
	cout<<"-------------------------------|"<<arr_name->definition<<endl;

	var = static_cast<SymbolIdAST*>(arr_name->identificator); //j
	cout<<"-----------------------------------|"<<var->definition<<endl;

	IfBodyAST *ifBody = static_cast<IfBodyAST*>(key_word_if->body); //if body
	cout<<"-----------------------|"<<ifBody->definition<<endl;

	unaryOp = static_cast<UnaryOperationAST*>(ifBody->blocks[0]); //++
	cout<<"---------------------------|"<<unaryOp->definition<<endl;

	var = static_cast<SymbolIdAST*>(unaryOp->operand); //j
	cout<<"-------------------------------|"<<var->definition<<endl;

	key_word_if = static_cast<IfAST*>(for_body->blocks[1]); //if
	cout<<"-------------------|"<<key_word_if->definition<<endl;

	ifCond = static_cast<IfConditionAST*>(key_word_if->condition); //if condition
	cout<<"-----------------------|"<<ifCond->definition<<endl;

	bin_op = static_cast<BinOperationAST*>(ifCond->blocks[0]); //==
	cout<<"---------------------------|"<<bin_op->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op->l_operand); //j
	cout<<"-------------------------------|"<<var->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op->r_operand); //token_size
	cout<<"-------------------------------|"<<var->definition<<endl;

	ifBody = static_cast<IfBodyAST*>(key_word_if->body); //if body
	cout<<"-----------------------|"<<ifBody->definition<<endl;

	assignment = static_cast<AssignmentAST*>(ifBody->blocks[0]); //=
	cout<<"---------------------------|"<<assignment->definition<<endl;

	var = static_cast<SymbolIdAST*>(assignment->l_operand); //pos
	cout<<"-------------------------------|"<<var->definition<<endl;

	bin_op = static_cast<BinOperationAST*>(assignment->r_operand); //+
	cout<<"-------------------------------|"<<bin_op->definition<<endl;

	BinOperationAST *bin_op1 = static_cast<BinOperationAST*>(bin_op->l_operand); //-
	cout<<"-----------------------------------|"<<bin_op1->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op1->l_operand); //i
	cout<<"---------------------------------------|"<<var->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op1->r_operand); //token_size
	cout<<"---------------------------------------|"<<var->definition<<endl;

	val = static_cast<DigitIdAST*>(bin_op->r_operand); //1
	cout<<"-----------------------------------|"<<val->definition<<endl;

	BreakAST *key_word_break = static_cast<BreakAST*>(ifBody->blocks[1]); //break
	cout<<"---------------------------|"<<key_word_break->definition<<endl;

	PrintfAST *func_printf = static_cast<PrintfAST*>(main_func_body->blocks[7]); //printf
	cout<<"-----------|"<<func_printf->definition<<endl;

	text = static_cast<StringLexemeAST*>(func_printf->params[0]); //"substr start pos: %d\n"
	cout<<"---------------|"<<text->definition<<endl;

	var = static_cast<SymbolIdAST*>(func_printf->params[1]); //pos
	cout<<"---------------|"<<var->definition<<endl;

	ReturnAST *key_word_return = static_cast<ReturnAST*>(main_func_body->blocks[8]); //return
	cout<<"-----------|"<<key_word_return->definition<<endl;

	val = static_cast<DigitIdAST*>(key_word_return->identificator); //0
	cout<<"---------------|"<<val->definition<<endl;
}

void printAST3(AST *tree) //nod.c
{
	DataTypeAST *data_type = static_cast<DataTypeAST*>(tree); //int
	cout<<"-|"<<data_type->definition<<endl;

	MainFunctionAST *main_func = static_cast<MainFunctionAST*>(data_type->identificator); //main
	cout<<"---|"<<main_func->definition<<endl;

	MainFunctionArgsAST *main_func_args = static_cast<MainFunctionArgsAST*>(main_func->args); //main args
	cout<<"-------|"<<main_func_args->definition<<endl;

	data_type = static_cast<DataTypeAST*>(main_func_args->args[0]); //int
	cout<<"-----------|"<<data_type->definition<<endl;

	SymbolIdAST *var = static_cast<SymbolIdAST*>(data_type->identificator); //argc
	cout<<"---------------|"<<var->definition<<endl;

	ConstAST *key_word_const = static_cast<ConstAST*>(main_func_args->args[1]); //const
	cout<<"-----------|"<<key_word_const->definition<<endl;

	data_type = static_cast<DataTypeAST*>(key_word_const->identificator); //char
	cout<<"---------------|"<<data_type->definition<<endl;

	PointerAST *ptr = static_cast<PointerAST*>(data_type->identificator); //*
	cout<<"-------------------|"<<ptr->definition<<endl;

	ptr = static_cast<PointerAST*>(ptr->identificator); //*
	cout<<"-----------------------|"<<ptr->definition<<endl;

	var = static_cast<SymbolIdAST*>(ptr->identificator); //argv
	cout<<"---------------------------|"<<var->definition<<endl;

	MainFunctionBodyAST *main_func_body = static_cast<MainFunctionBodyAST*>(main_func->body); //main body
	cout<<"-------|"<<main_func_body->definition<<endl;

	AssignmentAST *assignment = static_cast<AssignmentAST*>(main_func_body->blocks[0]); //=
	cout<<"-----------|"<<assignment->definition<<endl;

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int
	cout<<"---------------|"<<data_type->definition<<endl;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //a
	cout<<"-------------------|"<<var->definition<<endl;

	DigitIdAST *val = static_cast<DigitIdAST*>(assignment->r_operand); //24
	cout<<"---------------|"<<val->definition<<endl;

	assignment = static_cast<AssignmentAST*>(main_func_body->blocks[1]); //=
	cout<<"-----------|"<<assignment->definition<<endl;

	var = static_cast<SymbolIdAST*>(assignment->l_operand); //b
	cout<<"---------------|"<<var->definition<<endl;

	val = static_cast<DigitIdAST*>(assignment->r_operand); //12
	cout<<"---------------|"<<val->definition<<endl;

	assignment = static_cast<AssignmentAST*>(main_func_body->blocks[2]); //=
	cout<<"-----------|"<<assignment->definition<<endl;

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int
	cout<<"---------------|"<<data_type->definition<<endl;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //min
	cout<<"-------------------|"<<var->definition<<endl;

	TernarOperationAST *ternar_op = static_cast<TernarOperationAST*>(assignment->r_operand); //?
	cout<<"---------------|"<<ternar_op->definition<<endl;

	BinOperationAST *bin_op = static_cast<BinOperationAST*>(ternar_op->l_operand); //<
	cout<<"-------------------|"<<bin_op->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op->l_operand); //a
	cout<<"-----------------------|"<<var->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op->r_operand); //b
	cout<<"-----------------------|"<<var->definition<<endl;

	bin_op = static_cast<BinOperationAST*>(ternar_op->r_operand); //:
	cout<<"-------------------|"<<bin_op->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op->l_operand); //a
	cout<<"-----------------------|"<<var->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op->r_operand); //b
	cout<<"-----------------------|"<<var->definition<<endl;

	data_type = static_cast<DataTypeAST*>(main_func_body->blocks[3]); //int
	cout<<"-----------|"<<data_type->definition<<endl;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //nod
	cout<<"---------------|"<<var->definition<<endl;

	ForAST *key_word_for = static_cast<ForAST*>(main_func_body->blocks[4]); //for
	cout<<"-----------|"<<key_word_for->definition<<endl;

	ForConditionAST *for_cond = static_cast<ForConditionAST*>(key_word_for->condition); //for condition
	cout<<"---------------|"<<for_cond->definition<<endl;

	assignment = static_cast<AssignmentAST*>(for_cond->blocks[0]); //=
	cout<<"-------------------|"<<assignment->definition<<endl;

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int
	cout<<"-----------------------|"<<data_type->definition<<endl;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //i
	cout<<"---------------------------|"<<var->definition<<endl;

	var = static_cast<SymbolIdAST*>(assignment->r_operand); // min
	cout<<"-----------------------|"<<var->definition<<endl;

	bin_op= static_cast<BinOperationAST*>(for_cond->blocks[1]); //>
	cout<<"-------------------|"<<bin_op->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op->l_operand); //i
	cout<<"-----------------------|"<<var->definition<<endl;

	val = static_cast<DigitIdAST*>(bin_op->r_operand); //0
	cout<<"-----------------------|"<<val->definition<<endl;

	UnaryOperationAST *unary_op = static_cast<UnaryOperationAST*>(for_cond->blocks[2]); //--
	cout<<"-------------------|"<<unary_op->definition<<endl;

	var = static_cast<SymbolIdAST*>(unary_op->operand); //i
	cout<<"-----------------------|"<<var->definition<<endl;

	ForBodyAST *for_body = static_cast<ForBodyAST*>(key_word_for->body); //for body
	cout<<"---------------|"<<for_body->definition<<endl;

	IfAST *key_word_if = static_cast<IfAST*>(for_body->blocks[0]); //if
	cout<<"-------------------|"<<key_word_if->definition<<endl;

	IfConditionAST *ifCond = static_cast<IfConditionAST*>(key_word_if->condition); //if condition
	cout<<"-----------------------|"<<ifCond->definition<<endl;

	LogicOperationAST *logic_op = static_cast<LogicOperationAST*>(ifCond->blocks[0]); //&&
	cout<<"---------------------------|"<<logic_op->definition<<endl;

	bin_op = static_cast<BinOperationAST*>(logic_op->l_operand); //==
	cout<<"-------------------------------|"<<bin_op->definition<<endl;

	BinOperationAST *bin_op1 = static_cast<BinOperationAST*>(bin_op->l_operand); //%
	cout<<"-----------------------------------|"<<bin_op1->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op1->l_operand); //a
	cout<<"---------------------------------------|"<<var->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op1->r_operand); //i
	cout<<"---------------------------------------|"<<var->definition<<endl;

	val = static_cast<DigitIdAST*>(bin_op->r_operand); //0
	cout<<"-----------------------------------|"<<val->definition<<endl;

	bin_op = static_cast<BinOperationAST*>(logic_op->r_operand); //==
	cout<<"-------------------------------|"<<bin_op->definition<<endl;

	bin_op1 = static_cast<BinOperationAST*>(bin_op->l_operand); //%
	cout<<"-----------------------------------|"<<bin_op1->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op1->l_operand); //b
	cout<<"---------------------------------------|"<<var->definition<<endl;

	var = static_cast<SymbolIdAST*>(bin_op1->r_operand); //i
	cout<<"---------------------------------------|"<<var->definition<<endl;

	val = static_cast<DigitIdAST*>(bin_op->r_operand); //0
	cout<<"-----------------------------------|"<<val->definition<<endl;

	IfBodyAST *ifBody = static_cast<IfBodyAST*>(key_word_if->body); //if body
	cout<<"-----------------------|"<<ifBody->definition<<endl;

	assignment = static_cast<AssignmentAST*>(ifBody->blocks[0]); //=
	cout<<"---------------------------|"<<assignment->definition<<endl;

	var = static_cast<SymbolIdAST*>(assignment->l_operand); //nod
	cout<<"-------------------------------|"<<var->definition<<endl;

	var = static_cast<SymbolIdAST*>(assignment->r_operand); //i
	cout<<"-------------------------------|"<<var->definition<<endl;

	BreakAST *key_word_break = static_cast<BreakAST*>(ifBody->blocks[1]); //break
	cout<<"---------------------------|"<<key_word_break->definition<<endl;

	PrintfAST *func_printf = static_cast<PrintfAST*>(main_func_body->blocks[5]); //printf
	cout<<"-----------|"<<func_printf->definition<<endl;

	StringLexemeAST *text = static_cast<StringLexemeAST*>(func_printf->params[0]); //"nod: %d\n"
	cout<<"---------------|"<<text->definition<<endl;

	var = static_cast<SymbolIdAST*>(func_printf->params[1]); //nod
	cout<<"---------------|"<<var->definition<<endl;

	ReturnAST *key_word_return = static_cast<ReturnAST*>(main_func_body->blocks[6]); //return
	cout<<"-----------|"<<key_word_return->definition<<endl;

	val = static_cast<DigitIdAST*>(key_word_return->identificator); //0
	cout<<"---------------|"<<val->definition<<endl;
}

