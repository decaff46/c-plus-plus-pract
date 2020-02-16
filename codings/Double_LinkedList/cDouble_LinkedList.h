#pragma once

/*
	Template, Class, Pointer 활용 능력에 관한 예제로
	자료구조 중에서 DoubleLinkedList 를 직접 구현했습니다.
*/

template < typename T >
class cDouble_LinkedList
{
	struct	tagNode {
		T	Data;
		tagNode	*Next = nullptr, *Prev = nullptr;
	};

	tagNode		m_Head, m_Tail;
	int			m_Count;

	tagNode*	FindNode(T Data){
		auto *pFinder = m_Head.Next;

		while (pFinder != &m_Tail)
		{
			if (pFinder->Data == Data)	break;

			pFinder = pFinder->Next;
		}
		return pFinder;
	}
	tagNode*	NewNode(T Data, tagNode *Prev, tagNode *Next){
		auto *pNew = new tagNode;

		pNew->Data = Data;
		pNew->Prev = Prev;
		pNew->Next = Next;

		return pNew;
	}
	void	DelNode(tagNode* Del){
		if (m_Count == 0)	return;

		Del->Prev->Next = Del->Next;
		Del->Next->Prev = Del->Prev;

		delete Del;
		--m_Count;
	}
	void	Insert_Front(tagNode *Node, int Data){
		auto*	pNew = NewNode(Data, Node->Prev, Node);

		Node->Prev->Next	= pNew;
		Node->Prev			= pNew;

		++m_Count;
	}
	void	Insert_Back(tagNode *Node, int Data){
		auto*	pNew = NewNode(Data, Node, Node->Next);

		Node->Next->Prev	= pNew;
		Node->Next			= pNew;

		++m_Count;
	}
public:
	cDouble_LinkedList(void){
		m_Head.Data = m_Tail.Data = -1;
		m_Head.Next = &m_Tail;
		m_Tail.Prev = &m_Head;

		m_Count = 0;
	}
	~cDouble_LinkedList(void){
		DelAll();
	}
	void	DelAll(void){
		auto *pFind = m_Head.Next;

		while (pFind != &m_Tail)
		{
			auto *Del = pFind;

			pFind = pFind->Next;

			delete Del;
		}

		m_Head.Next = &m_Tail;
		m_Tail.Prev = &m_Head;
		m_Count = 0;
	}
	void	push_front(T Data)		{	Insert_Back(&m_Head, Data);		}
	void	push_back(int Data)		{	Insert_Front(&m_Tail, Data);	}
	void	pop_front(void)			{	DelNode(m_Head.Next);			}
	void	pop_back(void)			{	DelNode(m_Tail.Prev);			}

	T		front(void)	{	return m_Head->Next->Data;	}
	T		back(void)	{	return m_Tail->Prev->Data;	}
	T		Size(void)	{	return m_Count;	}
};