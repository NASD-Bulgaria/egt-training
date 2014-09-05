#ifndef LISTNODE_H4
#define LISTNODE_H

template<typename T> class List;

template<typename NODETYPE>
class TwoLinked
{
	friend class List<NODETYPE> ;
public:
	TwoLinked(const NODETYPE &);
	NODETYPE getData() const;

	void setNextPtr(TwoLinked *nPtr)
	{
		nextPtr = nPtr;
	}

	TwoLinked *getNextPtr() const
	{
		return nextPtr;
	}

private:
	NODETYPE data;
	TwoLinked *nextPtr;
};

template<typename NODETYPE>
TwoLinked<NODETYPE>::TwoLinked(const NODETYPE &info)
{
	data = info;
	nextPtr = 0;
}
template<typename NODETYPE>
NODETYPE TwoLinked<NODETYPE>::getData() const
{
	return data;
}

#endif
