#include "BinTree.h"
//ǰ�����   �� �� ��

void PreOrder(BTNode * pRoot)
{
	if(pRoot)
	{
		printf("%d ",pRoot->val);
		PreOrder(pRoot->pLeft);
		PreOrder(pRoot->pRintt);
	}
}
//�������  �� ��  ��
void InOrder(BTNode * pRoot)
{
	if(pRoot)
	{   
		InOrder(pRoot->pLeft);
		printf("%d ",pRoot->val);
		InOrder(pRoot->pRintt);
	}
}

//������� �� �� ��
void PostOrder(BTNode * pRoot)
{
	if(pRoot)
	{   
		 PostOrder(pRoot->pLeft);
		 printf("%d ",pRoot->val);
		 PostOrder(pRoot->pRintt);
	}
}
//��ȡ�������нڵ�ĸ���
/*int count = 0;
int GetNodeCount(BTNode * pRoot)
{

	if(pRoot)
	{
		count++;
		GetNodeCount(pRoot->pLeft);
		GetNodeCount(pRoot->pRintt);
	}

	return count;

}*/
//��ȡ�������нڵ�ĸ���
int GetNodeCount(BTNode * pRoot)
{
	if(NULL == pRoot)
	  return 0;
	else
	{
		return GetNodeCount(pRoot->pLeft)+GetNodeCount(pRoot->pRintt) + 1; 
	}
}


//��ȡ��������Ҷ�ӽڵ�ĸ���
int GetLeafCount(BTNode * pRoot)
{
	if(NULL == pRoot)
		return 0;
	if(NULL == pRoot->pLeft && NULL == pRoot->pRintt)
		return 1;
	return GetLeafCount(pRoot->pLeft)+ GetLeafCount(pRoot->pRintt);
}

//��ȡ��k���нڵ�ĸ���
int GetKLevelCount(BTNode * pRoot,int k)
{
	if(NULL == pRoot || k <= 0)
		return 0;
	if(k == 1)
		return 1;

		return GetKLevelCount(pRoot->pLeft,k-1)+GetKLevelCount(pRoot->pRintt,k-1);	
}

//��ȡ�������ĸ߶�
int GetHeigh(BTNode * pRoot)
{
	int L = 0;//�������߶�
	int R = 0;//�������ĸ߶�
	if(NULL == pRoot)
		return 0;
	L = GetHeigh(pRoot->pLeft);
	R = GetHeigh(pRoot->pRintt);

	return L>R?L+1:R+1;
}
//����x����������Ӧ�Ľڵ�
BTNode * Find(BTNode * pRoot , DataType x)
{
	if(NULL == pRoot)
		return NULL;

	if(x == pRoot->val)
		return pRoot;
		
	return Find(pRoot->pLeft,x) || Find(pRoot->pRintt,x);
}
//��ȡpNode��˫��
BTNode * GetParent(BTNode * pRoot,BTNode * pNode)
{
	if(pNode == pRoot || NULL == pRoot || NULL == pNode)
		return NULL;
	if(pRoot->pLeft == pNode || pRoot->pRintt == pNode)
		return pRoot;
	return GetParent(pRoot->pLeft,pNode) || GetParent(pRoot->pRintt,pNode);

}
