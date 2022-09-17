#include "postgres.h"
#include "fmgr.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(add);
PG_FUNCTION_INFO_V1(minus);
PG_FUNCTION_INFO_V1(multiply);
PG_FUNCTION_INFO_V1(divide);

Datum
add(PG_FUNCTION_ARGS)
{
    int32 a = PG_GETARG_INT32(0);
    int32 b = PG_GETARG_INT32(1);

    PG_RETURN_INT32(a + b);
}

Datum
minus(PG_FUNCTION_ARGS)
{
    int32 a = PG_GETARG_INT32(0);
    int32 b = PG_GETARG_INT32(1);

    PG_RETURN_INT32(a - b);
}

Datum
multiply(PG_FUNCTION_ARGS)
{
    int32 a = PG_GETARG_INT32(0);
    int32 b = PG_GETARG_INT32(1);

    PG_RETURN_INT32(a * b);
}

Datum
divide(PG_FUNCTION_ARGS)
{
    int32 a = PG_GETARG_INT32(0);
    int32 b = PG_GETARG_INT32(1);

    if (b == 0) {
        ereport(ERROR,
                (errcode(ERRCODE_DIVISION_BY_ZERO),
                 errmsg("division by zero")));
    }
    PG_RETURN_INT32(a / b);
}

