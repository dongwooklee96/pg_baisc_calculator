--complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION calculator" to load this file. \quit

CREATE FUNCTION add(int, int) RETURNS int
AS '$libdir/calculator', 'add'
LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION minus(int, int) RETURNS int
AS '$libdir/calculator', 'minus'
LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION multiply(int, int) RETURNS int
AS '$libdir/calculator', 'multiply'
LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION divide(int, int) RETURNS int
AS '$libdir/calculator', 'divide'
LANGUAGE C IMMUTABLE STRICT;

