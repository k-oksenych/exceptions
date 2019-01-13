#pragma once

class Exception
{
};

class ElementExistsException : public Exception
{
};

class ArgumentException : public Exception
{
};

class ArgumentOutOfRangeException : public ArgumentException
{
};