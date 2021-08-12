#pragma once


#include <iostream>
#include <stdexcept>
#include <functional>

class KeepInt
{
public:
	KeepInt(int &val): m_ref(val) {}

	int& m_ref;
};




class DoUndo
{
public:
	DoUndo() {}
	DoUndo(DoUndo *msg): m_msg(msg) {}
	DoUndo(KeepInt *Int): m_ref_int(Int->m_ref) {}
	static void allok() {}
private:
	int m_ref_int;
	DoUndo * m_msg;
};


class DoUndoAction: public DoUndo
{
public:
	DoUndoAction() = default;
};