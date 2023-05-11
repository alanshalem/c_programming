/*4. Modifique el programa anterior para usar un array de punteros a función.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float op1;
    float op2;
    float result;
} Operands;

void add(Operands *ops)
{
    ops->result = ops->op1 + ops->op2;
}

void subtract(Operands *ops)
{
    ops->result = ops->op1 - ops->op2;
}

void multiply(Operands *ops)
{
    ops->result = ops->op1 * ops->op2;
}

void divide(Operands *ops)
{
    ops->result = ops->op1 / ops->op2;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <operand1> <operand2> <operator>\n", argv[0]);
        return 1;
    }

    float op1 = atof(argv[1]);
    float op2 = atof(argv[2]);
    char op = argv[3][0];

    Operands ops = {op1, op2, 0};

    void (*op_func[])(Operands *) = {add, subtract, multiply, divide};

    if (op == '+')
    {
        op_func[0](&ops);
    }
    else if (op == '-')
    {
        op_func[1](&ops);
    }
    else if (op == '*')
    {
        op_func[2](&ops);
    }
    else if (op == '/')
    {
        op_func[3](&ops);
    }
    else
    {
        printf("Operación no válida\n");
        return 1;
    }

    printf("%.2f %c %.2f = %.2f\n", ops.op1, op, ops.op2, ops.result);

    return 0;
}
