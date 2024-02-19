#include <check.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR 1;

typedef enum token {
  NUM,
  X,
  UN_PLUS,
  UN_MINUS,
  PLUS,
  MINUS,
  MULT,
  DIV,
  POW,
  MOD,
  COS,
  SIN,
  TAN,
  ACOS,
  ASIN,
  ATAN,
  SQRT,
  LN,
  LOG,
  OP_BR,
  CL_BR
} tok;

typedef struct stack {
  double value;
  struct stack *next;
} stack;

int copy_num(char *str, char *note);
int copy_oper(char *note, int tok);
char *parser(char *str);
void pop(stack **head);
double peek(stack **head);
void push(stack **head, double value);
int take_num(char *str, stack **num);
int take_oper(char *str, char *note, stack **oper);
void print_stack(stack **x);
double calculate(stack **work, char *note, double x);
int operation_defenition(char *str);
int find_priority(int x);
int lenght_oper(int x);
void binary_calc(stack **work, double x, double y, int tok);
void unary_calc(stack **work, double x, int tok);
void credit_an(double sum, int term, double per, double *month, double *over,
               double *total);
void credit_diff(double sum, int term, double per, double *max_month,
                 double *min_month, double *over, double *total);
void deposit(double sum, int term, double per, double nalog_per,
             int term_payment, int kapital, int list_add, double add,
             int list_take, double take, double *payment, double *total,
             double *nalog_sum);
int verification(char *str);