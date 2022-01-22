#pragma once
// class ProductNum - класс-данные "“овар". ѕредставл€ет данные об одном “оваре.
//
// class List - класс, представл€ющий односв€зный список.
//
// void testProductNum() - тестирование класса студента
// void testList() - тестирование и пример работы с классом списка
//
// Copyright (c) ћихаил –усаков, 2009. CodingLessons.ru



class ProductNum
{
public:
	ProductNum()
	{
		_number = 0;
		_name = L"";
		_count = 0;

	}

	~ProductNum() {}

	ProductNum& operator=(ProductNum& rhv)
	{

		_name = rhv._name;
		_number = rhv._number;
		_count = rhv._count;

		return *this;
	}

	void SetName(CString name)
	{

		_name = name;
	}

	CString GetName()
	{
		return _name;
	}

	void SetNumber(int n)
	{
		if (n > 0)
			_number = n;
	}

	int GetNumber()
	{
		return _number;
	}

	void SetCount(int count)
	{
		if (count >= 0.0)
		{
			_count = count;
		}
	}

	int GetCount()
	{
		return _count;
	}


private:
	int		_number;
	CString _name;
	int	_count;
};

class ListProductNum
{
	struct ListNode
	{
		ProductNum   s;
		ListNode* next;
	};
public:
	ListProductNum()
	{
		_first = _cur = NULL;
	}

	ListProductNum(ListProductNum& src)
	{
		CopyFrom(src);
	}

	~ListProductNum()
	{
		Clear();
	}

	void Clear()
	{
		ListNode* node = _first;

		while (node != NULL)
		{
			ListNode* tmp = node;
			node = node->next;

			delete tmp;
		}

		_first = NULL;
		_cur = NULL;
	}

	ListProductNum& operator=(ListProductNum& rhv)
	{
		Clear();
		CopyFrom(rhv);
	}

	bool HasNext()
	{
		if (_cur != NULL
			&& _cur->next != NULL)
		{
			return true;
		}
		return false;
	}

	ProductNum* GetNext()
	{
		if (_cur)
		{
			_cur = _cur->next;
		}

		if (_cur)
		{
			return &_cur->s;
		}

		return NULL;
	}

	ProductNum* GetFirst()
	{
		_cur = _first;

		if (_cur == NULL)
		{
			return NULL;
		}
		return &_cur->s;
	}

	void PushBack(ProductNum* s)
	{
		ListNode* tail = GetTail();

		ListNode* newNode = new ListNode;

		newNode->s = *s;
		newNode->next = NULL;

		if (tail != NULL)
		{
			tail->next = newNode;
		}
		else
		{
			_first = newNode;
		}
	}

	void RemoveCurrent()
	{
		if (_first == NULL && _cur == NULL)
		{
			return;
		}

		if (_first == _cur)
		{
			_first = _first->next;
			delete _cur;
			_cur = _first;
			return;
		}

		ListNode* left = FindLeftOf(_cur);

		if (left != NULL)
		{
			left->next = _cur->next;
			delete _cur;

			_cur = left->next;
		}
	}

	int GetCount()
	{
		int nCount = 0;
		ListNode* node = _first;
		while (node != NULL)
		{
			nCount = nCount + 1;
			node = node->next;
		}
		return nCount;
	}
private:
	void CopyFrom(ListProductNum& list)
	{
		ProductNum* s = NULL;
		for (s = list.GetFirst(); s != NULL; s = list.GetNext())
		{
			PushBack(s);
		}
	}

	ListNode* FindLeftOf(ListNode* node)
	{
		ListNode* tmp = _first;

		while (tmp && tmp->next != node)
		{
			tmp = tmp->next;
		}

		return tmp;
	}


private:
	ListNode* GetTail()
	{
		ListNode* node = _first;
		while (node != NULL
			&& node->next != NULL)
		{
			node = node->next;
		}
		return node;
	}

private:
	ListNode* _first;
	ListNode* _cur;

};