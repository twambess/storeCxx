#pragma once
// class Manager - класс-данные "“овар". ѕредставл€ет данные об одном “оваре.
//
// class List - класс, представл€ющий односв€зный список.




class Manager
{
public:
	Manager()
	{
		_number = 0;
		_name = L"";
		_Position = L"";

	}

	~Manager() {}//деструктор

	Manager& operator=(Manager& rhv)
	{

		_name = rhv._name;
		_number = rhv._number;
		_Position = rhv._Position;

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

	void SetPosition(CString position)
	{
			_Position = position;
	}

	CString GetPosition()
	{
		return _Position;
	}



private://закрытые члены класса
	int		_number;
	CString _name;
	CString	_Position;
};

class ListManager
{
	struct ListNode
	{
		Manager   s;
		ListNode* next;
	};
public:
	ListManager()
	{
		_first = _cur = NULL;
	}

	ListManager(ListManager& src)//конструткор
	{
		CopyFrom(src);
	}

	~ListManager()//деструктор
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

	ListManager& operator=(ListManager& rhv)
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

	Manager* GetNext()
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

	Manager* GetFirst()
	{
		_cur = _first;

		if (_cur == NULL)
		{
			return NULL;
		}
		return &_cur->s;
	}

	void PushBack(Manager* s)
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
	void CopyFrom(ListManager& ListManager)
	{
		Manager* s = NULL;
		for (s = ListManager.GetFirst(); s != NULL; s = ListManager.GetNext())
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
