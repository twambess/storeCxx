#pragma once
// class Product - класс-данные "Товар". Представляет данные об одном Товаре.
//
// class List - класс, представляющий односвязный список.
//




class Product
{
public:
	Product()
	{
		_number = 0;
		_name = L"";
		_avgPrice = 0;
		_amount = 0;

	}

	~Product() {}

	Product& operator=(Product& rhv)
	{

		_name = rhv._name;
		_number = rhv._number;
		_avgPrice = rhv._avgPrice;
		_amount = rhv._amount;

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

	void SetPrice(float Price)
	{
		if (Price >= 0.0)
		{
			_avgPrice = Price;
		}
	}

	float GetPrice()
	{
		return _avgPrice;
	}

	void SetAmount(int amount)
	{
			_amount = amount;
	}

	int GetAmount()
	{
		return _amount;
	}

private:
	int		_number;
	CString _name;
	float	_avgPrice;
	int _amount;
};

class ListProduct
{
	struct ListNode
	{
		Product   s;
		ListNode* next;
	};
public:
	ListProduct()
	{
		_first = _cur = NULL;
	}

	ListProduct(ListProduct& src)
	{
		CopyFrom(src);
	}

	~ListProduct()
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

	ListProduct& operator=(ListProduct& rhv)
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

	Product* GetNext()
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

	Product* GetFirst()
	{
		_cur = _first;

		if (_cur == NULL)
		{
			return NULL;
		}
		return &_cur->s;
	}

	void PushBack(Product* s)
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
	void CopyFrom(ListProduct& list)
	{
		Product* s = NULL;
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