#include "smart_calc.h"

char *parser(char *str) {
  stack *work = NULL;
  size_t i = 0;
  char *note;
  note = (char *)calloc(strlen(str) * 2, sizeof(char));
  while (str[i] != '\0') {
    if (isdigit(str[i])) {
      i += copy_num(&str[i], note);
    } else if (str[i] == 'x') {
      strcat(note, "x ");
      i++;
    } else if (str[i] > 32) {
      if ((i == 0 || str[i - 1] == '(') && (str[i] == '-' || str[i] == '+')) {
        strncat(note, "0 ", 2);
      }
      i += take_oper(&str[i], note, &work);
    } else {
      i++;
    }
  }
  while (work) {
    copy_oper(note, peek(&work));
    pop(&work);
  }
  strcpy(str, note);
  free(note);
  return str;
}

int take_oper(char *str, char *note, stack **oper) {
  int tok = operation_defenition(str);
  if (*oper && peek(oper) <= 18 &&
      (find_priority(tok) <= find_priority(peek(oper)))) {
    while (*oper && peek(oper) <= 18 &&
           (find_priority(tok) <= find_priority(peek(oper)))) {
      copy_oper(note, peek(oper));
      pop(oper);
    }
    push(oper, tok);
  } else if (tok == CL_BR) {
    while (peek(oper) != OP_BR && peek(oper) != CL_BR) {
      copy_oper(note, peek(oper));
      pop(oper);
    }
    pop(oper);
  } else {
    push(oper, tok);
  }
  return lenght_oper(tok);
}

int copy_oper(char *note, int tok) {
  switch (tok) {
    case PLUS:
      strncat(note, "+ ", 2);
      break;
    case MINUS:
      strncat(note, "- ", 2);
      break;
    case MULT:
      strncat(note, "* ", 2);
      break;
    case DIV:
      strncat(note, "/ ", 2);
      break;
    case POW:
      strncat(note, "^ ", 2);
      break;
    case MOD:
      strncat(note, "mod ", 4);
      break;
    case COS:
      strncat(note, "cos ", 4);
      break;
    case SIN:
      strncat(note, "sin ", 4);
      break;
    case TAN:
      strncat(note, "tan ", 4);
      break;
    case ACOS:
      strncat(note, "acos ", 5);
      break;
    case ASIN:
      strncat(note, "asin ", 5);
      break;
    case ATAN:
      strncat(note, "atan ", 5);
      break;
    case SQRT:
      strncat(note, "sqrt ", 5);
      break;
    case LN:
      strncat(note, "ln ", 3);
      break;
    case LOG:
      strncat(note, "log ", 4);
      break;
    default:
      break;
  }
  return lenght_oper(tok);
}

int copy_num(char *str, char *note) {
  strncat(note, str, 1);
  size_t i = 1;
  while (isdigit(str[i]) || str[i] == '.') {
    strncat(note, &str[i], 1);
    i++;
  }
  strncat(note, " ", 1);
  return i;
}

int find_priority(int x) {
  int res = 0;
  if (x > 18)
    res = 5;
  else if (x > 9)
    res = 4;
  else if (x > 7)
    res = 3;
  else if (x > 5)
    res = 2;
  else if (x > 3)
    res = 1;
  return res;
}

int lenght_oper(int x) {
  int res = 0;
  if ((x > 1 && x < 9) || (x > 18))
    res = 1;
  else if ((x > 8 && x < 13) || x == 18)
    res = 3;
  else if (x > 12 && x < 17)
    res = 4;
  else
    res = 2;
  return res;
}

int operation_defenition(char *str) {
  int op = 0;
  if (!strncmp(str, "cos", 3)) {
    op = COS;
  } else if (!strncmp(str, "sin", 3)) {
    op = SIN;
  } else if (!strncmp(str, "tan", 3)) {
    op = TAN;
  } else if (!strncmp(str, "acos", 4)) {
    op = ACOS;
  } else if (!strncmp(str, "asin", 4)) {
    op = ASIN;
  } else if (!strncmp(str, "atan", 4)) {
    op = ATAN;
  } else if (!strncmp(str, "sqrt", 4)) {
    op = SQRT;
  } else if (!strncmp(str, "ln", 2)) {
    op = LN;
  } else if (!strncmp(str, "log", 3)) {
    op = LOG;
  } else if (*str == '+') {
    op = PLUS;
  } else if (*str == '-') {
    op = MINUS;
  } else if (*str == '*') {
    op = MULT;
  } else if (*str == '/') {
    op = DIV;
  } else if (*str == '^') {
    op = POW;
  } else if (!strncmp(str, "mod", 3)) {
    op = MOD;
  } else if (*str == '(') {
    op = OP_BR;
  } else if (*str == ')') {
    op = CL_BR;
  }
  return op;
}

int verification(char *str) {
  int res = 0, un = 0, bin = 0, br = 0, op = 0, dg = 0;
  if (strlen(str) > 256) {
    res = 1;
  }
  if (!res) {
    size_t i = 0;
    while (str[i] != '\0' && !res) {
      if (str[i] == ' ') {
        i++;
      }
      if (isdigit(str[i]) || str[i] == 'x') {
        res = dg ? 1 : 0, bin = 0, un = 0, op = 0, i++;
        int flag = 0;
        while ((isdigit(str[i]) || str[i] == '.') && !res) {
          if (str[i] == '.') {
            res = flag ? 1 : 0;
            flag = 1;
          }
          i++;
        }
        dg = 1;
      } else {
        int x = operation_defenition(&str[i]);
        if (!x) {
          res = 1;
        } else if (x >= PLUS && x <= MINUS && !bin) {
          bin = 1, dg = 0, un = 0, op = 0;
        } else if (x >= MULT && x <= MOD && !bin && !op) {
          bin = 1, dg = 0, un = 0, op = 0;
        } else if (x >= COS && x <= LOG && !un && !dg) {
          un = 1, dg = 0, bin = 0, op = 0;
        } else if (x == OP_BR) {
          op = 1, bin = 0, un = 0, dg = 0;
          br++;
        } else if (x == CL_BR && !bin && !op) {
          br--;
        } else {
          res = 1;
        }
        str += lenght_oper(x);
      }
    }
    res = br ? 1 : res;
  }
  return res;
}

double calculate(stack **work, char *note, double x) {
  size_t i = 0;
  double res = 0;
  while (note[i] != '\0') {
    if (isdigit(note[i])) {
      i += take_num(&note[i], work);
    } else if (note[i] == 'x') {
      push(work, x);
      i++;
    } else if (note[i] > 32) {
      tok tok = operation_defenition(&note[i]);
      if (tok < COS) {
        double v1 = peek(work);
        pop(work);
        double v2 = peek(work);
        pop(work);
        binary_calc(work, v1, v2, tok);
      } else {
        double v1 = peek(work);
        pop(work);
        unary_calc(work, v1, tok);
      }
      i += lenght_oper(tok);
    } else {
      i += 1;
    }
  }
  res = peek(work);
  pop(work);
  return res;
}

void binary_calc(stack **work, double x, double y, int tok) {
  switch (tok) {
    case PLUS:
      push(work, x + y);
      break;
    case MINUS:
      push(work, y - x);
      break;
    case MULT:
      push(work, x * y);
      break;
    case DIV:
      push(work, y / x);
      break;
    case POW:
      push(work, pow(y, x));
      break;
    case MOD:
      push(work, fmod(y, x));
      break;
    default:
      break;
  }
}

void unary_calc(stack **work, double x, int tok) {
  switch (tok) {
    case COS:
      push(work, cos(x));
      break;
    case SIN:
      push(work, sin(x));
      break;
    case TAN:
      push(work, tan(x));
      break;
    case ACOS:
      push(work, acos(x));
      break;
    case ASIN:
      push(work, asin(x));
      break;
    case ATAN:
      push(work, atan(x));
      break;
    case SQRT:
      push(work, sqrt(x));
      break;
    case LN:
      push(work, log(x));
      break;
    case LOG:
      push(work, log10(x));
      break;
    default:
      break;
  }
}

int take_num(char *str, stack **num) {
  double x = 0;
  size_t i = 0;
  for (; isdigit(str[i]) || str[i] == '.'; i++)
    ;
  char *tmp;
  tmp = (char *)calloc(i, sizeof(char));
  strncat(tmp, str, i);
  x = atof(tmp);
  push(num, x);
  return i;
}

void push(stack **head, double value) {
  stack *tmp = (stack *)calloc(1, sizeof(stack));
  tmp->value = value;
  tmp->next = (*head);
  (*head) = tmp;
}

void pop(stack **head) {
  stack *out;
  out = *head;
  if (out) {
    *head = (*head)->next;
    free(out);
  }
}

double peek(stack **head) {
  double res = 0;
  if (*head) res = (*head)->value;
  return res;
}

void credit_an(double sum, int term, double per, double *month, double *over,
               double *total) {
  *month = sum * ((per / 1200.0) / (1 - pow(1 + (per / 1200.0), -term)));
  *total = *month * term;
  *over = *total - sum;
}

void credit_diff(double sum, int term, double per, double *max_month,
                 double *min_month, double *over, double *total) {
  double pay = sum / term;
  *max_month = pay + sum * per / (100 * 12);
  for (int i = 0; i < term; i++) {
    *min_month = pay + (sum - (pay * i)) * per / 12 / 100;
    *total += *min_month;
  }
  *over = *total - sum;
}

void deposit(double sum, int term, double per, double nalog_per,
             int term_payment, int kapital, int list_add, double add,
             int list_take, double take, double *payment, double *total,
             double *nalog_sum) {
  int a = 0, m = 0;
  if (list_add || list_take) {
    if (list_add == 1)
      a = 1;
    else if (list_add == 2)
      a = 3;
    else if (list_add == 3)
      a = 6;
    else if (list_add == 4)
      a = 12;

    if (list_take == 1)
      m = 1;
    else if (list_take == 2)
      m = 3;
    else if (list_take == 3)
      m = 6;
    else if (list_take == 4)
      m = 12;
  }
  if (!kapital) {
    double p = 0;
    for (int i = 1; i <= term; i++) {
      *payment += ((sum + p) * per * 30.417 / 365.25 / 100);
      sum += !fmod(i, a) ? add : 0;
      sum -= !fmod(i, m) ? take : 0;
    }
    *total = sum + *payment;
    if (*payment > 1000000 * nalog_per) {
      *nalog_sum = ((*payment - 1000000 * nalog_per) * 13 * 0.01);
    }
  } else {
    int k = 0;
    if (term_payment == 0)
      k = 9999;
    else if (term_payment == 1)
      k = 1;
    else if (term_payment == 2)
      k = 4;
    else if (term_payment == 3)
      k = 12;
    double p = 0;
    for (int i = 1; i <= term; i++) {
      *payment += ((sum + p) * per * 30.417 / 365.25 / 100);
      p = !fmod(i, k) ? *payment : 0;
      sum += !fmod(i, a) ? add : 0;
      sum -= !fmod(i, m) ? take : 0;
    }
    *total = sum + *payment;
    if (*payment > 1000000 * nalog_per) {
      *nalog_sum = ((*payment - 1000000 * nalog_per) * 13 * 0.01);
    }
  }
}